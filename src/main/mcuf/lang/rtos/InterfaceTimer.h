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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Interface.h"
#include "mcuf/lang/Memory.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace lang{
    namespace rtos{
      interface InterfaceTimer;
    }
  }

  namespace util{
    class TimerTask;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::lang::rtos::InterfaceTimer extends virtual mcuf::lang::Interface{

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
   * @return true TimerID
   */
  virtual uint32_t timerStart(mcuf::lang::Memory& handler, uint32_t delay, bool mode) abstract;

  /**
   * @brief 停止Timer
   * 
   * @param timerTask 
   * @return true 停止成功
   * @return false Timer尚未啟動
   */
  virtual bool timerStop(mcuf::lang::Memory& handler) abstract;

  /**
   * @brief 回傳timer是否已啟動
   * 
   * @param timerTask 
   * @return true Timer狀態啟動
   * @return false Timer狀態閒置
   */
  virtual bool timerIsStart(mcuf::lang::Memory& handler) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_BABF4372_8F41_418D_B649_DC7081D0F3BF */
