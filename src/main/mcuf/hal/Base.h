/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_C49120BF_2531_4068_86B3_87BA2D347ED7
#define MCUF_C49120BF_2531_4068_86B3_87BA2D347ED7

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface Base;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief uninitialze hardware.
   * 
   * @return true 
   * @return false 
   */
  virtual bool deinit(void) abstract;

  /**
   * @brief initialze hardware;
   * 
   * @return true 
   * @return false 
   */
  virtual bool init(void) abstract;

  /**
   * @brief get hardware initialzed status.
   * 
   * @return true not init
   * @return false initd
   */
  virtual bool isInit(void) abstract;
   
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_C49120BF_2531_4068_86B3_87BA2D347ED7 */
