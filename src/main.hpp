#pragma once

// Author: Raul Cruz-Oliver
// Email: raul.cruz.oliver@gmail.com
// Date and place: November 2023, Buttikon CH

/*

This file create instances of dataLayerHandler
and nanotecHandler classes and starts an infinity
loop with a state machine to switch the motor
operation mode from stop to velocity mode using an 
API in dataLayer

*/

// state machine states
#define STOP_STATE 0

#define ENABLE_REL_POS_STATE 1
#define REL_POS_LOOP_STATE 2

#define ENABLE_VEL_STATE 3
#define VEL_LOOP_STATE 4

// values read from the datalayer
#define MODE_ID_STOP 0
#define MODE_ID_POS 1
#define MODE_ID_VEL 2