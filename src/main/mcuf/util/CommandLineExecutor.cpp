/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include <string.h>
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf/util/CommandLineExecutor.h"


/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------
using mcuf::util::CommandLineExecutor;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Command Line Executor object
 * 
 * @param memory 
 * @param outputBuffer 
 */
CommandLineExecutor::CommandLineExecutor(const mcuf::lang::Memory& memory, mcuf::io::OutputBuffer& outputBuffer) : 
ByteBuffer(memory), 
mOutputBuffer(outputBuffer){
  this->clearCommand();
  return;
}

/**
 * @brief Construct a new Command Line Executor object
 * 
 * @param length 
 * @param outputBuffer 
 */
CommandLineExecutor::CommandLineExecutor(size_t length, mcuf::io::OutputBuffer& outputBuffer) : 
ByteBuffer(length), 
mOutputBuffer(outputBuffer){
  this->clearCommand();
  return;
}

/**
 * @brief Destroy the Command Line Executor object
 * 
 */
CommandLineExecutor::~CommandLineExecutor(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */
/**
 * @brief 
 * 
 */
void CommandLineExecutor::action(void){
  char* buffer = static_cast<char*>(this->pointer());
  this->mArgs[0] = buffer;
  
  while (true){
    char temp = 0x00;
    if(this->mOutputBuffer.getByte(temp) == false)
      break;
    
    if(this->position() == 0)
      if((temp == ' ') || (temp == 'r') || (temp == 'n'))
        continue;
    
    switch(temp){
      //-----------------------------------------------------------------------------------
      case ' ':
        if(buffer[this->position()-1] != 0x00){
          this->putByte(0x00);
          this->mArgs[++this->mArgsLen] = &buffer[this->position()];
        }
        
        break;
        
      //-----------------------------------------------------------------------------------
      case '\n':
      case '\r':
      case 0x00:
        this->putByte(0x00);
        
        break;
      //-----------------------------------------------------------------------------------
      default:
        this->putByte(temp);
    }

    
  }
  
}

/**
 * @brief 
 * 
 * @param commandLineHandler 
 * @return true 
 * @return false 
 */
bool CommandLineExecutor::addCommand(mcuf::util::CommandLineHandler& commandLineHandler){
  for(int i=0; i<32; ++i){
    if(this->mCommand[i] == nullptr){
      this->mCommand[i] = &commandLineHandler;
      return true;
    }
  }
}

/**
 * @brief 
 * 
 * @param commandLineHandler 
 * @return true 
 * @return false 
 */
bool CommandLineExecutor::removeCommand(mcuf::util::CommandLineHandler& commandLineHandler){
  for(int i=0; i<32; ++i){
    if(this->mCommand[i] == &commandLineHandler){
      this->mCommand[i] = nullptr;
      return true;
    }
  }
  return false;
}

/**
 * @brief 
 * 
 */
void CommandLineExecutor::clearCommand(void){
  for(int i=0; i<32; ++i)
    this->mCommand[i] = nullptr;
  
  for(int i=0; i<16; ++i)
    this->mArgs[i] = nullptr;

  this->mArgsLen = 0;

  this->flush();
  return;
}
/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
/**
 * @brief 
 * 
 */
void CommandLineExecutor::commandExecute(void){
  size_t cmdlen = strlen(static_cast<const char*>(this->pointer()));
  for(int i=0; i<32; ++i){
    if(this->mCommand[i] == nullptr)
      continue;
    
    
      
  }
  
}

/* ****************************************************************************************
 * End of file
 */
