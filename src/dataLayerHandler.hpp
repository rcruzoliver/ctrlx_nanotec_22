#pragma once

// Author: Raul Cruz-Oliver
// Email: raul.cruz.oliver@gmail.com
// Date and place: November 2023, Buttikon CH

/*

This file creates all the neccesary artifacts for handling
a communication with the ctrlX OS datalayer.

It is a good example of a provider and a client. 

*/

#include "../inc/commDatalayer/comm/datalayer/datalayer.h"
#include "../inc/commDatalayer/comm/datalayer/datalayer_system.h"
#include "../inc/commDatalayer/comm/datalayer/metadata_generated.h"
#include "ctrlx_datalayer_helper.h"
#include <thread>
#include "nanotecHandler.hpp"


class dataLayerHandler {
public:
    // Data members
    comm::datalayer::DatalayerSystem datalayerSystem;
    comm::datalayer::IProvider* provider;
    comm::datalayer::IClient* client;

    // command
    comm::datalayer::Variant mode_id;
    const char* mode_id_address = "ctrlx_nanotec/cmd/mode_id";

    comm::datalayer::Variant command_vel;
    const char* command_vel_address = "ctrlx_nanotec/cmd/velocity_mode/vel_cmd";

    // state
    comm::datalayer::Variant curr_pos;
    const char* curr_pos_address = "ctrlx_nanotec/state/current_values/position";

    comm::datalayer::Variant curr_vel;
    const char* curr_vel_address = "ctrlx_nanotec/state/current_values/velocity";

    comm::datalayer::Variant targ_pos;
    const char* targ_pos_address = "ctrlx_nanotec/state/target_values/position";

    comm::datalayer::Variant targ_vel;
    const char* targ_vel_address = "ctrlx_nanotec/state/target_values/velocity";

    // Constructor
    dataLayerHandler(); 

    // Methods
    void registerSingleNode(const comm::datalayer::Variant node, const char* node_address);
    void registerNodes();
    bool read_mode_id();
    bool read_command_vel();
    bool is_connected();

    void writeSingleNode(int32_t data, comm::datalayer::Variant node, const char* node_address);
    void writeNodes(nanotecHandler& nanotecHandler);
};