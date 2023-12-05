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

// NANOTEC MEMORY ADDRESSES (from user guide)
// Command addresses
#define DRIVE_ADDRESS_CONTROL_INDEX 0x6040
#define DRIVE_ADDRESS_CONTROL_SUBINDEX 0x00
#define DRIVE_CONTROL_BITLENGTH 16

#define DRIVE_ADDRESS_OPERATION_MODE_INDEX 0x6060
#define DRIVE_ADDRESS_OPERATION_MODE_SUBINDEX 0x00
#define DRIVE_OPERATION_MODE_BITLENGTH 8

#define DRIVE_ADDRESS_VEL_CMD_INDEX 0x6042
#define DRIVE_ADDRESS_VEL_CMD_SUBINDEX 0x00
#define DRIVE_VEL_CMD_BITLENGTH 16

// State addresses
#define DRIVE_ADDRESS_STATUS_INDEX 0x6041
#define DRIVE_ADDRESS_STATUS_SUBINDEX 0x00

#define DRIVE_ADDRESS_POS_CURR_INDEX 0x6064
#define DRIVE_ADDRESS_POS_CURR_SUBINDEX 0x00

#define DRIVE_ADDRESS_VEL_CURR_INDEX 0x606C
#define DRIVE_ADDRESS_VEL_CURR_SUBINDEX 0x00

#define DRIVE_ADDRESS_POS_TARG_INDEX 0x6062
#define DRIVE_ADDRESS_POS_TARG_SUBINDEX 0x00

#define DRIVE_ADDRESS_VEL_TARG_INDEX 0x606B
#define DRIVE_ADDRESS_VEL_TARG_SUBINDEX 0x00

// NANOTEC CONTROL WORDS (written in 0x6040)
const uint16_t DRIVE_CONTROL_STOP = 6; // 0b 0000 0000 0000 0110
const uint16_t DRIVE_CONTROL_SWITCH_ON = 7; // 0b 0000 0000 0000 0111
const uint16_t DRIVE_CONTROL_ENABLE = 15; // 0b 0000 0000 0000 1111

// NANOTEC CODES FOR OPERATION MODES (written in 0x6060)
const int8_t DRIVE_POS_MODE = 1; 
const int8_t DRIVE_VEL_MODE = 2;

// OWN STATUS OUTPUT CODES, for checking operations in the main (They do not come from nanotec, but are related with DRIVE_CONTROL_*)
const int DRIVE_STATUS_STOP = 0;
const int DRIVE_STATUS_SWITCH_ON = 1;
const int DRIVE_STATUS_ENABLE = 2;

class nanotecHandler{
public:
	nanotecHandler();
	~nanotecHandler();

	////////////
	// STATE
	uint16_t driverStatusWord; // driver status word, is read from 0x6041
	int driverStatusCode = -1; // driver status code, humman redeable code for checking operations

	bool first = true; // flag to avoid writing several times the same message, avoid traffic in serial interface

	// drive state values 
	int32_t drive_curr_pos; // current position
	int32_t drive_curr_vel; // current velocity
	int32_t drive_targ_pos; // target position
	int32_t drive_targ_vel; // target velocity

	// read state 
	void read_state(); // updates the state values

	////////////
	// COMMAND

	// Driver control methods
	int stop_mode(); // sends the control word to switch the drive to stop, waits for status confirmation
	int switch_on_mode(); // sends the control word to switch the drive to switch on, waits for status confirmation
	int enable_mode(); // sends the control word to switch the drive to enable, waits for status confirmation

	// Driver setting up methods
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