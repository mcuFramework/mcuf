/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf/io/Future.h"
#include "mcuf/lang/Threads.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::Future;
using mcuf::lang::Threads;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
Future::Future(void){
  this->reset();
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

/**
 * @brief 
 * 
 * @param result 
 * @param attachment 
 */
void Future::completed(int result, void* attachment){
  if(!this->classAvariable())
    return;
  
  if(this->mStatus != Status::WAIT)
    return;
  
  this->mResult = result;
  this->mStatus = Status::DONE;
  if(this->mThreadID != 0)
    Threads::notify(this->mThreadID);
}
    
/**
 * @brief 
 * 
 * @param exc 
 * @param attachment 
 */
void Future::failed(void* exc, void* attachment){
  if(!this->classAvariable())
    return;
  
  if(this->mStatus != Status::WAIT)
    return;
  
  this->mResult = -1;
  this->mStatus = Status::DONE;
  if(this->mThreadID != 0)
    Threads::notify(this->mThreadID);
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::setWait(void){
  if(this->mStatus == Status::IDLE){
    this->mStatus = Status::WAIT;
    return true;
    
  }else{
    return false;
    
  }
}

/**
 * @brief 
 * 
 * @return int 
 */
int Future::get(void){
  if(this->mStatus == Status::WAIT){
    this->mThreadID = Threads::getThreadID();
    if(this->mThreadID != 0){
      while(true){
        this->wait(1000);
        if(this->mStatus != Status::WAIT)
          break;
      
      }
    }
  }
  return this->mResult;
}
  
/**
 * @brief 
 * 
 * @param timeout 
 * @return int 
 */
int Future::get(uint32_t timeout){
  if(this->mStatus == Status::WAIT){
    this->mThreadID = Threads::getThreadID();
    
    if(this->mThreadID != 0){
      this->wait(timeout);
      
      if(this->mStatus != Status::DONE)
        return -1;
      
    }
  }  
  return this->mResult;
}
  
/**
 * @brief 
 * 
 */
void Future::reset(void){
  this->mStatus = Status::IDLE;
  this->mThreadID = 0;
  this->mResult = 0;
  return;
}
  
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::isDone(void){
  return (this->mStatus == Status::DONE);
}
    
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::isIdle(void){
   return (this->mStatus == Status::IDLE);
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

/* ****************************************************************************************
 * End of file
 */
