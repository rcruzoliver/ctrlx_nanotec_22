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

    comm::datalayer::Variant pos_cmd;
    const char* pos_cmd_address = "ctrlx_nanotec/cmd/position_mode/pos_cmd";

    // comm::datalayer::Variant vel_posM_cmd;
    // const char* vel_posM_cmd_address = "ctrlx_nanotec/cmd/position_mode/vel_cmd";

    comm::datalayer::Variant vel_cmd;
    const char* vel_cmd_address = "ctrlx_nanotec/cmd/velocity_mode/vel_cmd";

    // state
    comm::datalayer::Variant curr_pos;
    const char* curr_pos_address = "ctrlx_nanotec/state/current_values/position";

    comm::datalayer::Variant curr_vel;
    const char* curr_vel_address = "ctrlx_nanotec/state/current_values/velocity";

    comm::datalayer::Variant targ_pos;
    const char* targ_pos_address = "ctrlx_nanotec/state/target_values/position";

    comm::datalayer::Variant targ_vel;
    const char* targ_vel_address = "ctrlx_nanotec/state/target_values/velocity";

    comm::datalayer::Variant status_word;
    const char* status_word_address = "ctrlx_nanotec/state/drive/status_word";

    comm::datalayer::Variant control_word;
    const char* control_word_address = "ctrlx_nanotec/state/drive/control_word";


    // Constructor
    dataLayerHandler(); 

    // Methods
    template <typename T>
    void registerSingleNode(const comm::datalayer::Variant node, const char* node_address);
    void registerNodes();

    bool read_mode_id();
    bool read_vel_cmd();

    bool read_pos_cmd();

    bool is_connected();

    template<typename T>
    void writeSingleNode(T data, comm::datalayer::Variant node, const char* node_address);
    void writeNodes(nanotecHandler& nanotecHandler);

};