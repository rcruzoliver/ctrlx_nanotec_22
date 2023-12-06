/*
 * SPDX-FileCopyrightText: Bosch Rexroth AG
 *
 * SPDX-License-Identifier: MIT
 */

 // The example app datalayer.register.node creates a new provider
 // with node 'sdk-cpp-registernode' and different type elements to the ctrlX Data Layer.

#include <iostream>
#include <filesystem>
#include <csignal>

// Include the libraries from the project directories, not from the system root 
#include "../inc/commDatalayer/comm/datalayer/datalayer.h"
#include "../inc/commDatalayer/comm/datalayer/datalayer_system.h"
#include "../inc/commDatalayer/comm/datalayer/metadata_generated.h"

#include "ctrlx_datalayer_helper.h"
#include "dataLayerHandler.hpp"
#include "nanotecHandler.hpp"

// Add some signal Handling so we are able to abort the program with sending sigint
static bool g_endProcess = false;

static void signalHandler(int signal)
{
  std::cout << "signal: " << signal << std::endl;
  g_endProcess = true;
}

using comm::datalayer::IProviderNode;

// Basic class Provider node interface for providing data to the system
class MyProviderNode: public IProviderNode
{
private:
  comm::datalayer::Variant m_data;

public:
  MyProviderNode(comm::datalayer::Variant data)
    : m_data(data)
  {};

  virtual ~MyProviderNode() override {};

  // Create function of an object. Function will be called whenever a object should be created.
  virtual void onCreate(const std::string& address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback& callback) override
  {
    callback(comm::datalayer::DlResult::DL_FAILED, nullptr);
  }

  // Read function of a node. Function will be called whenever a node should be read.
  virtual void onRead(const std::string& address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback& callback) override
  {
    comm::datalayer::Variant dataRead;
    dataRead = m_data;
    callback(comm::datalayer::DlResult::DL_OK, &dataRead);
  }

  // Write function of a node. Function will be called whenever a node should be written.
  virtual void onWrite(const std::string& address, const comm::datalayer::Variant* data, const comm::datalayer::IProviderNode::ResponseCallback& callback) override
  {
    // std::cout << "INFO onWrite " <<  address << std::endl;
    
    if (data->getType() != m_data.getType())
    {
      callback(comm::datalayer::DlResult::DL_TYPE_MISMATCH, nullptr);
    }

    m_data = *data;
    callback(comm::datalayer::DlResult::DL_OK, data);
  }

  // Remove function for an object. Function will be called whenever a object should be removed.
  virtual void onRemove(const std::string& address, const comm::datalayer::IProviderNode::ResponseCallback& callback) override
  {
    callback(comm::datalayer::DlResult::DL_FAILED, nullptr);
  }

  // Browse function of a node. Function will be called to determine children of a node.
  virtual void onBrowse(const std::string& address, const comm::datalayer::IProviderNode::ResponseCallback& callback) override
  {
    callback(comm::datalayer::DlResult::DL_FAILED, nullptr);
  }

  // Read function of metadata of an object. Function will be called whenever a node should be written.
  virtual void onMetadata(const std::string& address, const comm::datalayer::IProviderNode::ResponseCallback& callback) override
  {
    // Keep this comment! Can be used as sample creating metadata programmatically.
    // callback(comm::datalayer::DlResult::DL_OK, &_metaData);

    // Take metadata from metadata.mddb
    callback(comm::datalayer::DlResult::DL_FAILED, nullptr);
  }
};


dataLayerHandler::dataLayerHandler(){
  std::cout << "INFO Creating a datalayer handler. " << std::endl;
  datalayerSystem.start(false);   // Starts the ctrlX Data Layer system without a new broker because one broker is already running on ctrlX CORE

  // Create a data PROVIDER
  provider = getProvider(datalayerSystem);
  if (provider == nullptr){
      std::cout << "ERROR Getting provider connection failed." << std::endl;
      datalayerSystem.stop(false);
      exit(0);
    };

  // Create a data CLIENT  
  std::string connectionString = getConnectionString(); 

  // check if the connection string is such corresponding to being in a snap
  if (connectionString.find("ipc") != std::string::npos){ 
    std::cout << "INFO Creating ctrlX Data Layer client connection to " << connectionString << " ..." << std::endl;
    client = datalayerSystem.factory()->createClient(connectionString); 
  }else{
    std::cout << "ERROR Getting client connection failed." << std::endl;
    datalayerSystem.stop(false);
    exit(0);
  }
    
};

template <typename T>
void dataLayerHandler::registerSingleNode(comm::datalayer::Variant node, const char* node_address){

  comm::datalayer::DlResult result;

  node.setValue((T)0);
  std::cout << "INFO Register node " << node_address  << std::endl;
  result = provider->registerNode(node_address, new MyProviderNode(node));
  if (STATUS_FAILED(result))
  {
    std::cout << "ERROR Register node " << node_address  << " failed with: " << result.toString() << std::endl;
    exit(0);
  }

}

void dataLayerHandler::registerNodes(){

  // API
  mode_id.setValue((int8_t)0);
  std::cout << "INFO Register node " << mode_id_address  << std::endl;
  comm::datalayer::DlResult result_1 = provider->registerNode(mode_id_address, new MyProviderNode(mode_id));
  if (STATUS_FAILED(result_1))
  {
    std::cout << "ERROR Register node " << mode_id_address  << " failed with: " << result_1.toString() << std::endl;
    exit(0);
  }

  // COMMAND
  registerSingleNode<int32_t>(pos_cmd, pos_cmd_address);
  registerSingleNode<int16_t>(vel_cmd, vel_cmd_address);

  // STATE 
  registerSingleNode<int32_t>(curr_pos, curr_pos_address);
  registerSingleNode<int32_t>(curr_vel, curr_vel_address);
  registerSingleNode<int32_t>(targ_pos, targ_pos_address);
  registerSingleNode<int32_t>(targ_vel, targ_vel_address);

  registerSingleNode<int16_t>(status_word, status_word_address);
  registerSingleNode<int16_t>(control_word, control_word_address);

}

bool dataLayerHandler::read_mode_id(){
  comm::datalayer::DlResult result = client->readSync(mode_id_address, &mode_id);
  if (result != DL_OK){
    std::cout <<"ERROR Reading " << mode_id_address << " failed with: " << result.toString() << std::endl;
    return false;
  } 
  else
  {
    if (mode_id.getType() == comm::datalayer::VariantType::INT8)
    {
      // std::cout << "INFO Value of " << mode_id_address << ": " << double(mode_id) << std::endl;
      return true;
    }
    else { std::cout << "ERROR Value of " << mode_id_address << " has unexpected type: " << mode_id.typeAsString() << std::endl;}
    return false;
    }
  
}

bool dataLayerHandler::read_vel_cmd(){
  comm::datalayer::DlResult result = client->readSync(vel_cmd_address, &vel_cmd);
  if (result != DL_OK){
    std::cout <<"ERROR Reading " << vel_cmd_address << " failed with: " << result.toString() << std::endl;
    return false;
  } 
  else
  {
    if (vel_cmd.getType() == comm::datalayer::VariantType::INT16)
    {
      // std::cout << "INFO Value of " << vel_cmd_address << ": " << double(vel_cmd) << std::endl;
      return true;
    }
    else { std::cout << "ERROR Value of " << vel_cmd_address << " has unexpected type: " << vel_cmd.typeAsString() << std::endl;}
    return false;
    }
  
}

bool dataLayerHandler::read_pos_cmd(){
  comm::datalayer::DlResult result = client->readSync(pos_cmd_address, &pos_cmd);
  if (result != DL_OK){
    std::cout <<"ERROR Reading " << pos_cmd_address << " failed with: " << result.toString() << std::endl;
    return false;
  } 
  else
  {
    if (pos_cmd.getType() == comm::datalayer::VariantType::INT32)
    {
      // std::cout << "INFO Value of " << vel_cmd_address << ": " << double(vel_cmd) << std::endl;
      return true;
    }
    else { std::cout << "ERROR Value of " << pos_cmd_address << " has unexpected type: " << pos_cmd.typeAsString() << std::endl;}
    return false;
    }
  
}



bool dataLayerHandler::is_connected(){
  return (provider->isConnected() & client->isConnected());
}

template<typename T>
void dataLayerHandler::writeSingleNode(T data, comm::datalayer::Variant node, const char* node_address) {
  node.setValue((T)data);
	client->writeSync(node_address,&node);
}

void dataLayerHandler::writeNodes(nanotecHandler& nanotecHandler){
    writeSingleNode(nanotecHandler.drive_curr_pos,curr_pos,curr_pos_address);
		writeSingleNode(nanotecHandler.drive_curr_vel,curr_vel,curr_vel_address);
    writeSingleNode(nanotecHandler.drive_targ_pos,curr_pos,targ_pos_address);
		writeSingleNode(nanotecHandler.drive_targ_vel,curr_vel,targ_vel_address);

    writeSingleNode((int16_t)nanotecHandler.driverStatusWord,status_word,status_word_address);
    writeSingleNode((int16_t)nanotecHandler.driverControlWord,control_word,control_word_address);
}