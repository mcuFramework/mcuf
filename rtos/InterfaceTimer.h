/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BABF4372_8F41_418D_B649_DC7081D0F3BF
#define MCUF_BABF4372_8F41_418D_B649_DC7081D0F3BF

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"
#include "../func/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace rtos{
  interface InterfaceTimer;
  
}

namespace mcuf{
  class TimerTask;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface rtos::InterfaceTimer extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t timerGetHandlerSize(void) const abstract;

  /**
   * @brief 
   * 
   * @param timerTask 
   * @param delay 延遲時間 單位ms
   * @param mode false = 單次; true = 循環
   * @param runnable 直行進入點
   * @return 
   */
  virtual bool timerStart(mcuf::Memory& handler, uint32_t delay, bool mode, func::Runnable& runnable) abstract;

  /**
   * @brief 停止Timer
   * 
   * @param timerTask 
   * @return true 停止成功
   * @return false Timer尚未啟動
   */
  virtual bool timerStop(mcuf::Memory& handler) abstract;

  /**
   * @brief 回傳timer是否已啟動
   * 
   * @param timerTask 
   * @return true Timer狀態啟動
   * @return false Timer狀態閒置
   */
  virtual bool timerIsStart(mcuf::Memory& handler) abstract;

  /**
   * @brief 
   * 
   * @param handler 
   * @return uint32_t 
   */
  virtual uint32_t timerGetID(mcuf::Memory& handler) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_BABF4372_8F41_418D_B649_DC7081D0F3BF */
