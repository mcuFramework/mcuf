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
   * @brief 建立一個新的Timer記憶體資源
   * 
   * @param timerTask 
   * @return uint32_t TimerTask ID
   */
  virtual uint32_t timerAlloc(mcuf::util::TimerTask& timerTask);

  /**
   * @brief 釋放Timer記憶體資源
   * 
   * @param timerTask 
   * @return true 
   * @return false 
   */
  virtual bool timerFree(mcuf::util::TimerTask& timerTask);

  /**
   * @brief 
   * 
   * @param timerTask 
   * @param delay 延遲時間 單位ms
   * @param mode false = 單次; true = 循環
   * @return true 開始成功
   * @return false 開始失敗
   */
  virtual bool timerStart(mcuf::util::TimerTask& timerTask, uint32_t delay, bool mode);

  /**
   * @brief 停止Timer
   * 
   * @param timerTask 
   * @return true 停止成功
   * @return false Timer尚未啟動
   */
  virtual bool timerStop(mcuf::util::TimerTask& timerTask);

  /**
   * @brief 回傳timer是否已啟動
   * 
   * @param timerTask 
   * @return true Timer狀態啟動
   * @return false Timer狀態閒置
   */
  virtual bool timerIsStart(mcuf::util::TimerTask& timerTask);

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_BABF4372_8F41_418D_B649_DC7081D0F3BF */
