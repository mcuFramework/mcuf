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
#include "../mcuf/package-info.h"
#include "../mcuf/Interface.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace rtos{
  interface InterfaceKernel;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface rtos::InterfaceKernel extends virtual mcuf::Interface{

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
  virtual bool kernelWait(int timeout) const abstract;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_E5B93ACC_6FA3_4527_B356_93D76C4F913E */
