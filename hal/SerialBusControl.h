/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D62227AD_6C8A_4906_8DEB_0269D2F0EBF1
#define MCUF_D62227AD_6C8A_4906_8DEB_0269D2F0EBF1

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "../mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{
  interface SerialBusControl;
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface mcuf::hal::SerialBusControl extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t clockRate(void) abstract;

  /**
   * @brief 
   * 
   * @param clock 
   * @return uint32_t 
   */
  virtual uint32_t clockRate(uint32_t clock) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_D62227AD_6C8A_4906_8DEB_0269D2F0EBF1 */
