/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DEF49AD1_F66A_45EA_BC7D_16E860F3A655
#define MCUF_DEF49AD1_F66A_45EA_BC7D_16E860F3A655

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Interface.h"

//-----------------------------------------------------------------------------------------
#include "hal/EdgeTriggerEvent.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  interface EdgeTriggerControl;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::EdgeTriggerControl extends virtual mcuf::lang::Interface{
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

#endif /* MCUF_DEF49AD1_F66A_45EA_BC7D_16E860F3A655 */
