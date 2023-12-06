#include "../inc/nanotec/nano_lib_hw_strings.hpp"
// #include "nanolib_sampler_example.hpp"
#include "../inc/nanotec/od_types_helper.hpp"
#include "nanotecHandler.hpp"

#include <iostream>
#include <thread>
#include <chrono>

#include <memory.h>
#include <termios.h>
#include <unistd.h>


static bool bitExtract (uint16_t input, uint16_t bitPos) {
		return (input >> bitPos) & 1;
	}

nanotecHandler::nanotecHandler(){

	// Reduce the verbosity of the app
	nanolibHelper.setLoggingLevel(nlc::LogLevel::Off);

	// list all hardware available
	std::vector<nlc::BusHardwareId> busHardwareIds = nanolibHelper.getBusHardware();

	if (busHardwareIds.empty()) {
			std::cout << "No hardware buses found." << std::endl;
	}

	unsigned lineNum = 0;
	unsigned interfaceNum = 0;
	std::string protocolName;

	for (const nlc::BusHardwareId &busHwId : busHardwareIds) {
			protocolName = busHwId.getProtocol();
			if (protocolName.find("CANopen")!= std::string::npos){
				std::cout << "INFO " << busHwId.getName() << " with protocol " << busHwId.getProtocol() << " found. " << std::endl;
				interfaceNum = lineNum;
				break;
			}
			lineNum++;
		}

	// Use the selected bus hardware
	nlc::BusHardwareId busHwId = busHardwareIds[interfaceNum];

	// create bus hardware options for opening the hardware
	nlc::BusHardwareOptions busHwOptions = nanolibHelper.createBusHardwareOptions(busHwId);

	// open the hardware 
	nanolibHelper.openBusHardware(busHwId, busHwOptions);
	openedBusHardware = busHwId;

	// Scan the bus for available devices
	std::vector<nlc::DeviceId> deviceIds = nanolibHelper.scanBus(busHwId);
	if (deviceIds.empty()) {
			std::cout << std::endl << "WARN No devices found." << std::endl;
			std::cout << std::endl << "INFO The app will automatically restart. Make sure your hardware is connected." << std::endl;
			exit(0);
		}

	// If there are many devices in the CAN bus (this code ask the user, one must adapt it for automatic detection)
	/* 
	unsigned deviceNum = 0;
	// print out available devices
	for (const nlc::DeviceId &deviceId : deviceIds) {
		std::cout << deviceNum << ". " << deviceId.getDescription()
					  << " [device id: " << deviceId.getDeviceId()
					  << ", hardware: " << deviceId.getBusHardwareId().getName() << "]"
					  << std::endl;
		deviceNum++;
		}

	if (deviceNum > 1) {

		std::cout << std::endl
					  << "Type device number (0-" << (deviceNum - 1) << ") and press Enter:";
		std::cin >> deviceNum;
		std::cout << std::endl;

		if (deviceNum >= deviceIds.size()) {
			std::cerr << "Invalid device number." << std::endl;
			exit(0);
			}

		} else {
			deviceNum = 0;
			std::cout << std::endl;
	}

	nlc::DeviceId deviceId = deviceIds[deviceNum];

	*/
	
	// If there is only one drive in the CAN bus
	unsigned deviceNum = 0;
	nlc::DeviceId deviceId = deviceIds[deviceNum];
	nlc::DeviceHandle deviceHandle = nanolibHelper.addDevice(deviceId);

	// Establishing a connection with the device
	std::cout << "INFO Connecting to device " << deviceId.getDescription() << std::endl;
	nanolibHelper.connectDevice(deviceHandle); 
	connectedDeviceHandle = deviceHandle; //this is the object that is used to communicate via the serial interface

	std::cout <<  "INFO Nanotec handler succesfully created" << std::endl;
	}

nanotecHandler::~nanotecHandler() {

	if (connectedDeviceHandle.has_value()) {
		std::cout << "INFO Disconnecting the device." << std::endl;
		nanolibHelper.disconnectDevice(*connectedDeviceHandle);
	}

	if (openedBusHardware.has_value()) {
		std::cout << "INFO Closing the hardware bus." << std::endl;
		nanolibHelper.closeBusHardware(*openedBusHardware);
	}

	exit(0);
}

void nanotecHandler::set_units_state(){

	// Set dimension factor for vel_mode
	nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_VEL_MODE_UNITS_NUM, nlc::OdIndex(DRIVE_ADDRESS_VEL_MODE_UNITS_INDEX, DRIVE_ADDRESS_VEL_MODE_UNITS_SUBINDEX_NUM), DRIVE_ADDRESS_VEL_MODE_UNITS_BITLENGTH);
	nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_VEL_MODE_UNITS_DEN, nlc::OdIndex(DRIVE_ADDRESS_VEL_MODE_UNITS_INDEX, DRIVE_ADDRESS_VEL_MODE_UNITS_SUBINDEX_DEN), DRIVE_ADDRESS_VEL_MODE_UNITS_BITLENGTH);

	// Set acceleration and deceleration for vel_mode
	nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_VEL_MODE_ACC, nlc::OdIndex(DRIVE_ADDRESS_VEL_MODE_ACC_INDEX, DRIVE_ADDRESS_VEL_MODE_ACC_SUBINDEX_NUM), DRIVE_ADDRESS_VEL_MODE_ACC_BITLENGTH);
	nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_VEL_MODE_DEC, nlc::OdIndex(DRIVE_ADDRESS_VEL_MODE_DEC_INDEX, DRIVE_ADDRESS_VEL_MODE_DEC_SUBINDEX_NUM), DRIVE_ADDRESS_VEL_MODE_DEC_BITLENGTH);

	// Set position units for state read
	nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_POS_UNITS, nlc::OdIndex(DRIVE_ADDRESS_POS_UNITS_INDEX, DRIVE_ADDRESS_POS_UNITS_SUBINDEX), DRIVE_ADDRESS_POS_UNITS_BITLEGTH);
	// Set velocity units for state read
	nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_VEL_UNITS, nlc::OdIndex(DRIVE_ADDRESS_VEL_UNITS_INDEX, DRIVE_ADDRESS_VEL_UNITS_SUBINDEX), DRIVE_ADDRESS_VEL_UNITS_BITLEGTH);

	// Set reference to zero
	nanolibHelper.writeInteger(*connectedDeviceHandle, 0, nlc::OdIndex(DRIVE_ADDRESS_HOME_OFFSET_INDEX, DRIVE_ADDRESS_HOME_OFFSET_SUBINDEX), DRIVE_ADDRESS_HOME_OFFSET_BITLENGTH);

}

void nanotecHandler::read_state(){
	drive_curr_pos = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_POS_CURR_INDEX, DRIVE_ADDRESS_POS_CURR_SUBINDEX));
	drive_curr_vel = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_VEL_CURR_INDEX, DRIVE_ADDRESS_VEL_CURR_SUBINDEX));
	drive_targ_pos = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_POS_TARG_INDEX, DRIVE_ADDRESS_POS_TARG_SUBINDEX));
	drive_targ_vel = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_VEL_TARG_INDEX, DRIVE_ADDRESS_VEL_TARG_SUBINDEX));
}

int nanotecHandler::stop_mode(){

	// write the controlWord only once
	if (first && (driverStatusCode!=DRIVE_STATUS_STOP)){
   		nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_CONTROL_STOP, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX), DRIVE_CONTROL_BITLENGTH);
		first = false; // drop the flag
	}

	// if not in the desired operation mode, check the status word
	if (driverStatusCode != DRIVE_STATUS_STOP){
		driverStatusWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_STATUS_INDEX, DRIVE_ADDRESS_STATUS_SUBINDEX));
		// check if the driver has already switched 
		if ((bitExtract(driverStatusWord,9) & bitExtract(driverStatusWord,5) & bitExtract(driverStatusWord,0))) {
			std::cout << "INFO: Motor in stop state (ready to switch on)" << std::endl;
			driverStatusCode = DRIVE_STATUS_STOP; // stop mode reached
			first = true; // rise the flag 
		}
	}

	// if already in the desired operation mode, perfom the tasks
	if (driverStatusCode == DRIVE_STATUS_STOP){
		//
	}

	return driverStatusCode;

}


int nanotecHandler::switch_on_mode(){

	// write the controlWord only once
	if (first && (driverStatusCode!=DRIVE_STATUS_SWITCH_ON)){
   		nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_CONTROL_SWITCH_ON, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX), DRIVE_CONTROL_BITLENGTH);
		first = false; // drop the flag
	}

	// if not in the desired operation mode, check the status word
	if (driverStatusCode != DRIVE_STATUS_SWITCH_ON){
		driverStatusWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_STATUS_INDEX, DRIVE_ADDRESS_STATUS_SUBINDEX));
		// check if the driver has already switched 
		if (bitExtract(driverStatusWord,9) & bitExtract(driverStatusWord,5) & bitExtract(driverStatusWord,4) & bitExtract(driverStatusWord,1) & bitExtract(driverStatusWord,0)){
			std::cout << "INFO: Motor switched on" << std::endl;
			driverStatusCode = DRIVE_STATUS_SWITCH_ON; // switch on mode reached
			first = true; // rise the flag
		}
	}

	// if already in the desired operation mode, perfrom the tasks
	if (driverStatusCode == DRIVE_STATUS_SWITCH_ON){
		//
	}

	return driverStatusCode;

}

int nanotecHandler::enable_mode(){

	// write the controlWord only once
	if (first && (driverStatusCode!=DRIVE_STATUS_ENABLE)){
   		nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_CONTROL_ENABLE, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX), DRIVE_CONTROL_BITLENGTH);
		first = false; // drop the flag
	}

	// if not in the desired operation mode, check the status word
	if (driverStatusCode != DRIVE_STATUS_ENABLE){
		driverStatusWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_STATUS_INDEX, DRIVE_ADDRESS_STATUS_SUBINDEX));
		// check if the driver has already switched 
		if (bitExtract(driverStatusWord,9) & bitExtract(driverStatusWord,5) & bitExtract(driverStatusWord,4) & bitExtract(driverStatusWord,1) & bitExtract(driverStatusWord,1) & bitExtract(driverStatusWord,0)){
			std::cout << "INFO: Motor enabled" << std::endl;
			driverStatusCode = DRIVE_STATUS_ENABLE; // enable mode reached
			first = true; // rise the flag
		}
	}
	
	// if already in the desired operation mode, perfrom the tasks
	if (driverStatusCode == DRIVE_STATUS_ENABLE){
		//
	}
	
	return driverStatusCode;
}

void nanotecHandler::set_pos_mode(){
    nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_POS_MODE, nlc::OdIndex(DRIVE_ADDRESS_OPERATION_MODE_INDEX, DRIVE_ADDRESS_OPERATION_MODE_SUBINDEX), DRIVE_OPERATION_MODE_BITLENGTH);
}


void nanotecHandler::set_rel_pos_mode(){
	int16_t driverControlWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX));
	driverControlWord |= 0b0000000001000000; // bit 6
	nanolibHelper.writeInteger(*connectedDeviceHandle, driverControlWord, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX), DRIVE_CONTROL_BITLENGTH);
}

void nanotecHandler::set_immed_pos_mode(){
	int16_t driverControlWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX));
	driverControlWord |= 0b0000000000100000; // bit 5
	nanolibHelper.writeInteger(*connectedDeviceHandle, driverControlWord, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX), DRIVE_CONTROL_BITLENGTH);
}

void nanotecHandler::start_momevement_pos_mode(){
	int16_t driverControlWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX));
	driverControlWord &= 0b1111111111101111; // bit 4 x->0
	nanolibHelper.writeInteger(*connectedDeviceHandle, driverControlWord, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX), DRIVE_CONTROL_BITLENGTH);
	driverControlWord |= 0b0000000000010000; // bit 4 0->1
	nanolibHelper.writeInteger(*connectedDeviceHandle, driverControlWord, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX), DRIVE_CONTROL_BITLENGTH);
}


void nanotecHandler::set_vel_mode(){
    nanolibHelper.writeInteger(*connectedDeviceHandle, DRIVE_VEL_MODE, nlc::OdIndex(DRIVE_ADDRESS_OPERATION_MODE_INDEX, DRIVE_ADDRESS_OPERATION_MODE_SUBINDEX), DRIVE_OPERATION_MODE_BITLENGTH);
}

void nanotecHandler::update_pos_cmd(int32_t data){
    nanolibHelper.writeInteger(*connectedDeviceHandle, data, nlc::OdIndex(DRIVE_ADDRESS_POS_CMD_INDEX, DRIVE_ADDRESS_POS_CMD_SUBINDEX), DRIVE_POS_CMD_BITLENGTH);
}

void nanotecHandler::update_vel_cmd(int16_t data){
    nanolibHelper.writeInteger(*connectedDeviceHandle, data, nlc::OdIndex(DRIVE_ADDRESS_VEL_CMD_INDEX, DRIVE_ADDRESS_VEL_CMD_SUBINDEX), DRIVE_VEL_CMD_BITLENGTH);
}

void nanotecHandler::printStatus(){
	driverStatusWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_STATUS_INDEX, DRIVE_ADDRESS_STATUS_SUBINDEX));
	std::cout << driverStatusWord << std::endl;
}

void nanotecHandler::printControl(){
	driverStatusWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX));
	std::cout << driverStatusWord << std::endl;
}

void nanotecHandler::update_words(){
	driverStatusWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_STATUS_INDEX, DRIVE_ADDRESS_STATUS_SUBINDEX));
	driverControlWord = nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(DRIVE_ADDRESS_CONTROL_INDEX, DRIVE_ADDRESS_CONTROL_SUBINDEX));
}

// Reading from different interfaces examples

/* 

static int _getch() {

	struct termios tios;

	memset(&tios, 0, sizeof(tios));

	if (tcgetattr(STDIN_FILENO, &tios) < 0)
		return EOF;

	tios.c_lflag &= ~(ICANON | ECHO);

	if (tcsetattr(STDIN_FILENO, TCSANOW, &tios) < 0)
		return EOF;

	setbuf(stdin, NULL);

	char ch = getchar();

	tios.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tios);

	return ch;
}

void NanoLibExampleProgram::processObjectDictionaryAccessExamples() {

	std::cout << std::endl << "Object Dictionary Access Examples:" << std::endl;

	std::cout << std::endl << "Reading subindex 0 of index 0x6040" << std::endl;
	uint16_t controlWord = static_cast<uint16_t>(
		nanolibHelper.readInteger(*connectedDeviceHandle, nlc::OdIndex(0x6040, 0x00)));
	std::cout << "Result: " << controlWord << std::endl;

	std::cout << std::endl << "Motor Stop (0x6040-0)" << std::endl;
	nanolibHelper.writeInteger(*connectedDeviceHandle, 6, nlc::OdIndex(0x6040, 0x00), 16);

	std::cout << std::endl << "Reading Nanotec home page string" << std::endl;
	std::cout << "Homepage of Nanotec Electronic GmbH & Co. KG is: "
			  << nanolibHelper.readString(*connectedDeviceHandle, nlc::OdIndex(0x6505, 0x00))
			  << std::endl;

	std::cout << std::endl << "Reading device error stack:" << std::endl;
	std::vector<std::int64_t> errorStack = nanolibHelper.readArray(*connectedDeviceHandle, 0x1003);
	std::cout << "The error stack has " << std::to_string(errorStack.at(0)) << " element"
			  << std::endl;
}

void NanoLibExampleProgram::processObjectDictionaryAccessExamplesViaDictionaryInterface() {

	std::cout << std::endl << "Object Dictionary Access Examples via Dictionary Interface:" << std::endl;

	const nlc::OdIndex odControlWord(0x6040, 0x00);
	const nlc::OdIndex odHomePage(0x6505, 0x00);

	nlc::ResultObjectDictionary resultObjectDictionary
		= NanoLibHelper::checkedResult("getAssignedObjectDictionary", nanolibHelper->getAssignedObjectDictionary(*connectedDeviceHandle));

	nlc::ObjectDictionary &objectDictionary
		= const_cast<nlc::ObjectDictionary&>(resultObjectDictionary.getResult());

	std::cout << std::endl << "Reading subindex 0 of index 0x6040" << std::endl;
	uint16_t controlWord = static_cast<uint16_t>(
		NanoLibHelper::checkedResult("ObjectDictionary::readNumber",
									 objectDictionary.readNumber(odControlWord))
			.getResult());
	std::cout << "Result: " << controlWord << std::endl;

	std::cout << std::endl << "Motor Stop (0x6040-0)" << std::endl;
	NanoLibHelper::checkResult("ObjectDictionary::writeNumber", objectDictionary.writeNumber(odControlWord, 6));
	
	std::cout << std::endl << "Reading Nanotec home page string" << std::endl;
	std::cout << "Homepage of Nanotec Electronic GmbH & Co. KG is: "
			  << NanoLibHelper::checkedResult("ObjectDictionary::readString",
											  objectDictionary.readString(odHomePage))
					 .getResult()
			  << std::endl;

	std::cout << std::endl;
		
	std::cout << "Some ObjectEntry properties:" << std::endl;
		
	const nlc::ObjectEntry &objectEntry
		= NanoLibHelper::checkedResult("ObjectDictionary::getObjectEntry",
									   objectDictionary.getObjectEntry(odControlWord.getIndex()))
			  .getResult();


	std::cout << "Object(0x6040).ObjectCode = "; //<< static_cast<int>(objectEntry.getObjectCode())
												//<< std::endl;
	const auto objectCode = objectEntry.getObjectCode();
	switch (objectCode) {
	case nlc::ObjectCode::Null:
		std::cout << "Null";
		break;
	case nlc::ObjectCode::Deftype:
		std::cout << "Deftype";
		break;
	case nlc::ObjectCode::Defstruct:
		std::cout << "Defstruct";
		break;
	case nlc::ObjectCode::Var:
		std::cout << "Var";
		break;
	case nlc::ObjectCode::Array:
		std::cout << "Array";
		break;
	case nlc::ObjectCode::Record:
		std::cout << "Record";
		break;
	default:
		std::cout << static_cast<int>(objectCode);
		break;
	}
	std::cout << std::endl;

	std::cout << "Object(0x6040).DataType = "
			  << nlc::OdTypesHelper::objectEntryDataTypeToString(objectEntry.getDataType())
			  << std::endl;

	std::cout << "Some ObjectSubEntry properties:" << std::endl;

	nlc::ResultObjectSubEntry resultObjectSubEntry = NanoLibHelper::checkedResult(
		"ObjectDictionary::getObject", objectDictionary.getObject(odControlWord));
	const nlc::ObjectSubEntry &objectSubEntry = resultObjectSubEntry.getResult();

	std::cout << "OdIndex(" << odControlWord.toString()
			  << ").DataType = " << nlc::OdTypesHelper::objectEntryDataTypeToString(objectSubEntry.getDataType())
			  << std::endl;
	std::cout << "OdIndex(" << odControlWord.toString()
			  << ").BitLength = " << objectSubEntry.getBitLength()
			  << std::endl;
}

void NanoLibExampleProgram::processProfinetDCPExample() {

	nlc::BusHardwareId busHardwareId(openedBusHardware.value());
	nlc::ProfinetDCP &profinetDCP = nanolibHelper->getProfinetDCP();


	std::cout << "Scanning " << busHardwareId.getName() << " for Profinet devices..."
			  << std::endl;
	nlc::ResultProfinetDevices resultProfinetDevices
		= profinetDCP.scanProfinetDevices(busHardwareId);

	if (resultProfinetDevices.hasError()
		&& (resultProfinetDevices.getErrorCode() != nlc::NlcErrorCode::TimeoutError)) {
		std::cerr << "ProfinetDCP::scanProfinetDevices failed with error: "
				  << resultProfinetDevices.getError() << std::endl;
		return;
	}

	const std::vector<nlc::ProfinetDevice> &profinetDevices = resultProfinetDevices.getResult();
	const size_t numberOfProfinetDevices = profinetDevices.size();

	if (numberOfProfinetDevices < 1) {
		std::cout << "No Profinet devices found." << std::endl;
		return;
	}

	std::cout << numberOfProfinetDevices << " Profinet device(s) found:" << std::endl;
	for (const auto &profinetDevice : profinetDevices) {

		std::cout << "IP: " << ((profinetDevice.ipAddress >> 24) & 0x000000FF) << "."
				  << ((profinetDevice.ipAddress >> 16) & 0x000000FF) << "."
				  << ((profinetDevice.ipAddress >> 8) & 0x000000FF) << "."
				  << (profinetDevice.ipAddress & 0x000000FF)
				  << "\tName: " << profinetDevice.deviceName << std::endl;

		// Checking the IP address against the context of the current network configuration
		const auto resultValid
			= profinetDCP.validateProfinetDeviceIp(busHardwareId, profinetDevice);
		std::cout << "\tDevice IP is " << (resultValid.hasError() ? " not " : "")
				  << "valid into current network." << std::endl;

		// Trying to blink the device
		const auto resultBlink = profinetDCP.blinkProfinetDevice(busHardwareId, profinetDevice);
		std::cout << "\tBlink the device ";
		if (resultBlink.hasError())
			std::cout << "failed with error: " << resultBlink.getError();
		else
			std::cout << "succeeded.";
		std::cout << std::endl;
	}
}

*/