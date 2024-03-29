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
#include "./CommandLineExecutor.h"


/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------
using cli::CommandLineExecutor;

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
CommandLineExecutor::CommandLineExecutor(const mcuf::Memory& memory, mcuf::OutputBuffer& outputBuffer) : 
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
CommandLineExecutor::CommandLineExecutor(size_t length, mcuf::OutputBuffer& outputBuffer) : 
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
 * Public Method
 */
/**
 * @brief 
 * 
 */
void CommandLineExecutor::action(void){
  if(this->mOutputBuffer.avariable() <= 0)
    return;
  
  
  char* buffer = static_cast<char*>(this->pointer());
  if(this->mArgsLen == 0){
    this->mArgs[0] = buffer;
    ++this->mArgsLen;
  }
  
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
        if(this->mArgsLen >= 16){
          this->putByte(' ');
          break;
        }
        
        if(buffer[this->position()-1] != 0x00){
          this->putByte(0x00);
          this->mArgs[this->mArgsLen++] = &buffer[this->position()];
        }
        
        break;
        
      //-----------------------------------------------------------------------------------
      case '\n':
      case '\r':
      case 0x00:
        this->putByte(0x00);
        this->flip();
        this->commandExecute();
        this->bufferClear();
        break;
      //-----------------------------------------------------------------------------------
      default:
        this->putByte(temp);
        break;
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
bool CommandLineExecutor::addCommand(cli::CommandLineHandler& commandLineHandler){
  for(int i=0; i<32; ++i){
    if(this->mCommand[i] == nullptr){
      this->mCommand[i] = &commandLineHandler;
      return true;
    }
  }
  return false;
}

/**
 * @brief 
 * 
 * @param commandLineHandler 
 * @return true 
 * @return false 
 */
bool CommandLineExecutor::removeCommand(cli::CommandLineHandler& commandLineHandler){
  for(int i=0; i<32; ++i){
    if(this->mCommand[i] == &commandLineHandler){
      this->mCommand[i] = nullptr;
      return true;
    }
  }
  return false;
}

/**
 * @brief Get the Command object
 * 
 * @param command 
 * @return cli::CommandLineHandler& 
 */
cli::CommandLineHandler* CommandLineExecutor::getCommand(const char* command){
  if(command == nullptr)
    return nullptr;

  size_t commandLen = strlen(command);
  for(int i=0; i<32; ++i){
    if(this->mCommand[i] == nullptr)
      continue;
    
    size_t targetLen = strlen(this->mCommand[i]->getCommand());
    if(commandLen != targetLen)
      continue;
      
    if(strcmp(command, this->mCommand[i]->getCommand()) != 0)
      continue;
    
    return this->mCommand[i];
  }
  return nullptr;
}

/**
 * @brief 
 * 
 */
void CommandLineExecutor::clearCommand(void){
  for(int i=0; i<32; ++i)
    this->mCommand[i] = nullptr;
  
  this->bufferClear();
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
  cli::CommandLineHandler* c = this->getCommand(static_cast<const char*>(this->pointer()));
  if(c != nullptr)
    c->execute(this->mArgs, this->mArgsLen);

  return;
}

/**
 * @brief 
 * 
 */
void CommandLineExecutor::bufferClear(void){
  this->flush();
  
  for(int i=0; i<16; ++i)
    this->mArgs[i] = nullptr;  
  
  this->mArgs[0] = static_cast<char*>(this->pointer());
  this->mArgsLen = 1;
  
  return;
}

/* ****************************************************************************************
 * End of file
 */
