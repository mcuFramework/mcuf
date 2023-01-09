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
#include "mcuf\Interface.h"
#include "mcuf\Thread.h"
#include "mcuf\ThreadPriority.h"
#include "mcuf\ThreadState.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface InterfaceThread;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::InterfaceThread extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 取的當前線程的執行ID
   * 
   * @return uint32_t 執行序ID
   */
  virtual uint32_t threadGetCurrentID(void) const abstract;

  /**
   * @brief 將控制權傳遞給具有相同優先級且處於 READY 狀態的下一個線程。 
   *        如果READY狀態下沒有其他相同優先級的線程，則當前線程繼續執行，不發生線程切換。
   * 
   * @return true 控制已成功傳遞給下一個線程。
   * @return false 發生了未指定的錯誤。或者無法從中斷服務例程調用該函數。
   */
  virtual bool threadYield(void) const abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t threadGetHandlerSize(void) const abstract;

  /**
   * @brief 
   * 
   * @return mcuf::ThreadState 
   */
  virtual mcuf::ThreadState threadGetState(const mcuf::Memory& handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @param name 
   */
  virtual void threadSetName(mcuf::Memory& handler, const char* name) abstract;
  
  /**
   * @brief 
   * 
   * @param handler 
   * @return uint32_t 
   */
  virtual uint32_t threadGetID(const mcuf::Memory& handler) const abstract;
  
  /**
   * @brief 
   * 
   * @param thread 
   * @return const char* 
   */
  virtual const char* threadGetName(const mcuf::Memory& handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::ThreadPriority 
   */
  virtual mcuf::ThreadPriority threadGetPriority(const mcuf::Memory& handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @param stackSize 
   * @param priority 
   * @return true 
   * @return false 
   */
  virtual bool threatStart(mcuf::Memory& handler, mcuf::ThreadPriority priority, mcuf::Memory& stackMemory, mcuf::function::Runnable& runnable) abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return mcuf::ThreadPriority 
   */
  virtual bool threadSetPriority(mcuf::Memory& handler,  mcuf::ThreadPriority) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return true 
   * @return false 
   */
  virtual bool threadExit(mcuf::Memory& handler) abstract;
  
  /**
   * @brief 
   * 
   * @param thread 
   * @return int 
   */
  virtual int threadGetStackSize(const mcuf::Memory& handler) const abstract;

  /**
   * @brief 
   * 
   * @param thread 
   * @return true 
   * @return false 
   */
  virtual bool threadNotify(const mcuf::Memory& handler) const abstract;

  /**
   * @brief 
   * 
   * @param threadID 
   * @return true 
   * @return false 
   */
  virtual bool threadNotify(uint32_t threadID) const abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_ACC59C48_81F5_4103_BD4A_BC6FC3355FBF */
