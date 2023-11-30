#pragma once

#include "../inc/commDatalayer/comm/datalayer/datalayer.h"
#include "../inc/commDatalayer/comm/datalayer/datalayer_system.h"
#include "../inc/commDatalayer/comm/datalayer/metadata_generated.h"
#include "ctrlx_datalayer_helper.h"
#include <thread>

int main_datalayer();


class dataLayerHandler {
public:
    // Data members
    comm::datalayer::DatalayerSystem datalayerSystem;
    comm::datalayer::IProvider* provider;
    comm::datalayer::IClient* client;

    comm::datalayer::Variant mode_id;
    const char* mode_id_address = "ctrlx_nanotec/mode_id";
    comm::datalayer::Variant command_vel;
    const char* command_vel_address = "ctrlx_nanotec/velocity_mode/command_vel";

    // Constructor
    dataLayerHandler(); 

    // Methods
    void registerNodes();
    bool read_mode_id();
    bool read_command_vel();
    bool is_connected();

};