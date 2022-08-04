/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_ACC59C48_81F5_4103_BD4A_BC6FC3355FBF
#define MCUF_ACC59C48_81F5_4103_BD4A_BC6FC3355FBF

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/lang/Interface.h"
#include "mcuf/lang/Thread.h"
#include "mcuf/lang/ThreadPriority.h"
#include "mcuf/lang/ThreadState.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace lang{
    namespace rtos{
      interface InterfaceThread;
    }
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::lang::rtos::InterfaceThread extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param stack 
   * @return void* 
   */
  virtual void* threadCreate(mcuf::lang::Data& stack) abstract;
  
  /**
   * @brief 
   * 
   * @param thread 
   * @param name 
   */
  virtual void threadSetName(void* handler, const char* name) abstract;
  
  /**
   * @brief 
   * 
   * @param handler 
   * @return uint32_t 
   */
  virtual uint32_t threadGetID(void* handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return const char* 
   */
  virtual const char* threadGetName(void* handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::lang::ThreadState 
   */
  virtual mcuf::lang::ThreadState threadGetStatus(void* handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::lang::ThreadPriority 
   */
  virtual mcuf::lang::ThreadPriority threadGetPriority(void* handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @param stackSize 
   * @param priority 
   * @return true 
   * @return false 
   */
  virtual bool threatStart(void* handler, mcuf::lang::ThreadPriority priority) abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::lang::ThreadPriority 
   */
  virtual bool threadSetPriority(void* handler,  mcuf::lang::ThreadPriority) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return true 
   * @return false 
   */
  virtual bool threadExit(void* handler) abstract;
  
  /**
   * @brief 
   * 
   * @param thread 
   * @return int 
   */
  virtual int threadGetStackSize(void* handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return true 
   * @return false 
   */
  virtual bool threadNotify(void* handler) const abstract;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_ACC59C48_81F5_4103_BD4A_BC6FC3355FBF */
