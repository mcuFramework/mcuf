/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_E5B93ACC_6FA3_4527_B356_93D76C4F913E
#define MCUF_E5B93ACC_6FA3_4527_B356_93D76C4F913E

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/lang/Interface.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace lang{
    namespace rtos{
      interface InterfaceKernel;
    }
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::lang::rtos::InterfaceKernel extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool kernelInitialize(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool kernelStart(void) abstract;

  /**
   * @brief 
   * 
   * @return int 
   */
  virtual int kernelLock(void) abstract;

  /**
   * @brief 
   * 
   * @return int 
   */
  virtual int kernelUnlock(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t kernelGetTickCount(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t kernelGetTickFreq(void) abstract;
  
  /**
   * @brief 
   *  
   */
  virtual bool kernelDelay(int milliseconds) const abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool kernelWait(void) const abstract;
  
  /**
   * @brief 
   * 
   * @param timeout 
   * @return true 
   * @return false 
   */
  virtual bool kernelWait(uint32_t timeout) const abstract;
  
  /**
   * @brief 將控制權傳遞給具有相同優先級且處於 READY 狀態的下一個線程。 
   *        如果READY狀態下沒有其他相同優先級的線程，則當前線程繼續執行，不發生線程切換。
   * 
   * @return true 控制已成功傳遞給下一個線程。
   * @return false 發生了未指定的錯誤。或者無法從中斷服務例程調用該函數。
   */
  virtual bool kernelYield(void) const abstract;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_E5B93ACC_6FA3_4527_B356_93D76C4F913E */
