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

const int STOP_STATE = 0;
const int ENABLE_VEL_STATE = 1;
const int VEL_LOOP_STATE = 2;

const int MODE_ID_STOP = 0;
const int MODE_ID_VEL = 1;