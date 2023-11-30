#pragma once

// Author: Raul Cruz-Oliver
// Email: raul.cruz.oliver@gmail.com
// Date and place: November 2023, Buttikon CH

/*

This file creates all the neccesary artifacts for handling
a communication with the CANopen device using the library 
provided from nanotec

*/

#include "nanolib_helper.hpp"
#include <optional>

// Nanotec memory addresses (from user guide)
const int DRIVE_ADDRESS_CONTROL_INDEX = 0x6040;
const int DRIVE_ADDRESS_CONTROL_SUBINDEX = 0x00;
const int DRIVE_CONTROL_BITLENGTH = 16;

const int DRIVE_ADDRESS_STATUS_INDEX = 0x6041;
const int DRIVE_ADDRESS_STATUS_SUBINDEX = 0x00;

const int DRIVE_ADDRESS_OPERATION_MODE_INDEX = 0x6060;
const int DRIVE_ADDRESS_OPERATION_MODE_SUBINDEX = 0x00;
const int DRIVE_OPERATION_MODE_BITLENGTH = 8;

const int DRIVE_ADDRESS_VEL_CMD_INDEX = 0x6042;
const int DRIVE_ADDRESS_VEL_CMD_SUBINDEX = 0x00;
const int DRIVE_VEL_CMD_BITLENGTH = 16;

// Nanotec codes for operation mode
const int8_t DRIVE_VEL_MODE = 2;

// Nanotec codes for control word (from user guide)
const uint16_t DRIVE_CONTROL_STOP = 6;
const uint16_t DRIVE_CONTROL_SWITCH_ON = 7;
const uint16_t DRIVE_CONTROL_ENABLE = 15;

// Own status output codes, for checking operations in the main (They do not come from nanotec)
const int DRIVE_STATUS_STOP = 0;
const int DRIVE_STATUS_SWITCH_ON = 1;
const int DRIVE_STATUS_ENABLE = 2;

class nanotecHandler{
public:
	nanotecHandler();
	~nanotecHandler();

	uint16_t driverStatusWord; // driver status word, is read from 0x6041
	int driverStatusCode = -1; // driver status code, humman redeable code for checking operations

	bool first = true; // flag to avoid writing several times the same message, avoid traffic in serial interface
	
	int stop_mode(); // sends the control word to switch the drive to stop, waits for status confirmation
	int switch_on_mode(); // sends the control word to switch the drive to switch on, waits for status confirmation
	int enable_mode(); // sends the control word to switch the drive to enable, waits for status confirmation

	void set_vel_mode(); // configures the operating mode as velocity mode (will apply when drive enabled)
	void update_vel_command(uint16_t velCommand); // updates the command value for velocity

private:
	NanoLibHelper nanolibHelper;
	std::optional<nlc::BusHardwareId> openedBusHardware;
	std::optional<nlc::DeviceHandle> connectedDeviceHandle;
};


// Reading from different interfaces examples
/*

class NanoLibExampleProgram {
public:
	NanoLibExampleProgram();
	~NanoLibExampleProgram();

private:	
	void processObjectDictionaryAccessExamples();
	void processObjectDictionaryAccessExamplesViaDictionaryInterface();
	void processProfinetDCPExample();

private:
	NanoLibHelper nanolibHelper;
	std::optional<nlc::BusHardwareId> openedBusHardware;
	std::optional<nlc::DeviceHandle> connectedDeviceHandle;
};

*/