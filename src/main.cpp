
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

	// Set units
	nanotecHandler.set_units_state();

	// handling variables for the main state machine
	int state_machine = STOP_STATE;
	int drive_status;
	bool read_ok;
	int32_t old_pos_cmd;
	
	// infinite loop, stay in it while the data Layer connection is successful
	while (dataLayerHandler.is_connected()) {

		/////////////////
		// STATE

		// Update state in nanotec handler object
		nanotecHandler.read_state();
		nanotecHandler.update_words();

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

			if ((int)dataLayerHandler.mode_id == MODE_ID_POS){
				state_machine = ENABLE_REL_POS_STATE;
			}
			else if ((int)dataLayerHandler.mode_id == MODE_ID_VEL){
				state_machine = ENABLE_VEL_STATE;
			}
			
			break;

		case ENABLE_REL_POS_STATE:
			std::cout << "INFO Starting relative positioning mode."<< std::endl; 
			// Set up the driver mode
			nanotecHandler.set_pos_mode();

			// Swtich on the drive (only if it in stop mode)
			if (drive_status == DRIVE_STATUS_STOP){
				drive_status = nanotecHandler.switch_on_mode();
			}
			
			// Enable the drive (only if it in switch on mode)
			if (drive_status == DRIVE_STATUS_SWITCH_ON){
				drive_status = nanotecHandler.enable_mode();
			};

			// If the drive is already enable, enter the relative loop
			if (drive_status == DRIVE_STATUS_ENABLE){
				// Setting up the position mode in relative and immediately triggered mode
				nanotecHandler.set_rel_pos_mode();
				
				state_machine = REL_POS_LOOP_STATE;
				// nanotecHandler.printStatus();
				// nanotecHandler.printControl();
				std::cout << "INFO Motor in relative positioning mode."<< std::endl; 
			}

			break;

		case REL_POS_LOOP_STATE:
			read_ok = dataLayerHandler.read_pos_cmd(); // Perform syncron readings from data layer
			if (read_ok==0){break;}

			if((int32_t)dataLayerHandler.pos_cmd != old_pos_cmd){
				nanotecHandler.update_pos_cmd((int32_t)dataLayerHandler.pos_cmd);
				nanotecHandler.set_immed_pos_mode();
				nanotecHandler.start_momevement_pos_mode();
				std::cout << "INFO New positioning command"<< std::endl; 
			}

			old_pos_cmd = (int32_t)dataLayerHandler.pos_cmd;
			
			// nanotecHandler.printStatus();

			if ((int)dataLayerHandler.mode_id == MODE_ID_STOP){
				state_machine = STOP_STATE;
			}
			break;


    	case ENABLE_VEL_STATE: // make driver enable in velocity operation mode 
			std::cout << "INFO Starting velocity mode."<< std::endl; 
			// Set up the driver mode
			nanotecHandler.set_vel_mode();
			read_ok = dataLayerHandler.read_vel_cmd(); // Perform syncron readings from data layer
			if (read_ok==0){break;}
			nanotecHandler.update_vel_cmd((int)dataLayerHandler.vel_cmd);

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

			read_ok = dataLayerHandler.read_vel_cmd(); // Perform syncron readings from data layer
			if (read_ok==0){break;}

			nanotecHandler.update_vel_cmd((int)dataLayerHandler.vel_cmd);

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
