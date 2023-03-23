/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_EFF1A157_A291_4313_A742_99FB124D0B71
#define MCUF_EFF1A157_A291_4313_A742_99FB124D0B71

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"

//-----------------------------------------------------------------------------------------
#include "./EdgeTriggerEvent.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface EdgeTrigger;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::EdgeTrigger extends hal::Base{
  /* **************************************************************************************
   * Method
   */
  /**
   * @brief 取消全部邊緣觸發事件
   * 
   */
  virtual void disableAll(void) abstract;

  /**
   * @brief 取消負緣觸發
   * 
   */
  virtual void disableFall(void) abstract;

  /**
   * @brief 取消正緣觸發
   * 
   */
  virtual void disableRise(void) abstract;

  /**
   * @brief 啟用負緣觸發
   * 
   * @param event 觸發事件
   * @return true 設定成功
   * @return false 設定失敗
   */
  virtual bool enableFall(hal::EdgeTriggerEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param event 啟用正緣觸發
   * @return true 設定成功
   * @return false 設定失敗
   */
  virtual bool enableRise(hal::EdgeTriggerEvent* event) abstract;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_EFF1A157_A291_4313_A742_99FB124D0B71 */
