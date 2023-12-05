
#include "nanotecHandler.hpp"
#include "dataLayerHandler.hpp"
#include "main.hpp"

int main() {
	// Create a nanotecHandler isntance (manage the read/write operations via serial interface with the CAN Open adapter)
	nanotecHandler nanotecHandler;

	// Create dataLayerHandler instance (manage read/write operations from data layer in ctrlX Core)
	dataLayerHandler dataLayerHandler;

	// Ctreate the neccesary nodes in data layer
	dataLayerHandler.registerNodes();

	// handling variables for the main state machine
	int state_machine = STOP_STATE;
	int drive_status;
	bool read_ok;
	
	// infinite loop, stay in it while the data Layer connection is successful
	while (dataLayerHandler.is_connected()) {

		/////////////////
		// STATE

		// Update state in nanotec handler object
		nanotecHandler.read_state();

		// Update state in data layer
		dataLayerHandler.writeNodes(nanotecHandler);

		////////////////
		// COMMAND 

		// Perform syncron readings from data layer
    	read_ok = dataLayerHandler.read_mode_id();

    	if (read_ok==0){break;}

		// Communicate with the serial device in a state machine fashion
		switch (state_machine){
    	case STOP_STATE: // driver in stop operation
        	drive_status = nanotecHandler.stop_mode();
			if ((int)dataLayerHandler.mode_id == MODE_ID_VEL){
				state_machine = ENABLE_VEL_STATE;
			}
			break;

    	case ENABLE_VEL_STATE: // make driver enable in velocity operation mode 
			std::cout << "INFO Starting velocity mode."<< std::endl; 
			// Set up the driver mode
			nanotecHandler.set_vel_mode();
			read_ok = dataLayerHandler.read_command_vel(); // Perform syncron readings from data layer
			if (read_ok==0){break;}
			nanotecHandler.update_vel_command((int)dataLayerHandler.command_vel);

			// Swtich on the drive (only if it in stop mode)
			if (drive_status == DRIVE_STATUS_STOP){
				drive_status = nanotecHandler.switch_on_mode();
			}
			
			// Enable the drive (only if it in switch on mode)
			if (drive_status == DRIVE_STATUS_SWITCH_ON){
				drive_status = nanotecHandler.enable_mode();
			};

			// If the drive is already enable, enter the velocity update loop
			if (drive_status == DRIVE_STATUS_ENABLE){
				state_machine = VEL_LOOP_STATE;
				std::cout << "INFO Motor in velocity mode."<< std::endl; 
			}
			break;
			
		case VEL_LOOP_STATE: // loop state for velocity mode, waiting for a change in command velocity
			read_ok = dataLayerHandler.read_command_vel(); // Perform syncron readings from data layer
			if (read_ok==0){break;}
			nanotecHandler.update_vel_command((int)dataLayerHandler.command_vel);

			if ((int)dataLayerHandler.mode_id == MODE_ID_STOP){
				state_machine = STOP_STATE;
			}
			break;

    	default:
        	std::cout << "ERROR You attemped to enter a invalid state for the serial communication state machine" << std::endl;
			break; // exit the infinity loop, if this happens is because something went unexpectly
		}

		// Sleep until next loop
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	// If the connection with the data layer fails
	std::cout << "ERROR Datalayer connection broken!" << std::endl;

	// Bring the motor to a stop state for safety reasons
	std::cout << "INFO Motor will be stopped. " << std::endl;
	nanotecHandler.stop_mode();

	// Inform the user that the app will re-started (daemon manager from snap)
	std::cout << "WARN Check if the hardware is connected. " << std::endl;
	std::cout << "INFO App will be automatically restarted. " << std::endl;

	exit(0);

};
