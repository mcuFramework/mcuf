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
   * @param thread 
   * @param priority 
   * @param stackSize 
   * @return void* ThreadID
   */
  virtual void* threadAlloc(mcuf::lang::Thread& thread, mcuf::lang::ThreadPriority priority, uint32_t stackSize) abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @param name 
   */
  virtual void threadSetName(mcuf::lang::Thread& thread, const char* name) abstract;
  
  /**
   * @brief 
   * 
   * @param thread 
   * @return const char* 
   */
  virtual const char* threadGetName(const mcuf::lang::Thread& thread) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::lang::ThreadState 
   */
  virtual mcuf::lang::ThreadState threadGetStatus(const mcuf::lang::Thread& thread) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::lang::ThreadPriority 
   */
  virtual mcuf::lang::ThreadPriority threadGetPriority(const mcuf::lang::Thread& thread) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @param stackSize 
   * @param priority 
   * @return true 
   * @return false 
   */
  virtual bool threatStart(mcuf::lang::Thread& thread, int stackSize, mcuf::lang::ThreadPriority priority) abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::lang::ThreadPriority 
   */
  virtual bool threadSetPriority(mcuf::lang::Thread& thread, mcuf::lang::ThreadPriority) abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return true 
   * @return false 
   */
  virtual bool threadYield(mcuf::lang::Thread& thread) abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return true 
   * @return false 
   */
  virtual bool threadExit(mcuf::lang::Thread& thread) abstract;
  
  /**
   * @brief 
   * 
   * @param thread 
   * @return int 
   */
  virtual int threadGetStackSize(const mcuf::lang::Thread& thread) const abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool threadWait(void);
  
  /**
   * @brief 
   * 
   * @param timeout 
   * @return true 
   * @return false 
   */
  virtual bool threadWait(uint32_t timeout);

  /**
   * @brief 
   * 
   * @param thread 
   * @return true 
   * @return false 
   */
  virtual bool threadNotify(mcuf::lang::Thread& thread);
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_ACC59C48_81F5_4103_BD4A_BC6FC3355FBF */