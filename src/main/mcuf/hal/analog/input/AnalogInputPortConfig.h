/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D3D44900_B44C_4E13_B861_E5956D0061D7
#define MCUF_D3D44900_B44C_4E13_B861_E5956D0061D7

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace hal{
    namespace analog{
      namespace input{
        interface AnalogInputPortConfig;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::analog::input::AnalogInputPortConfig{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t sampleRate(void) abstract;

  /**
   * @brief 
   * 
   * @param rate 
   * @return true 
   * @return false 
   */
  virtual bool sampleRate(uint32_t rate) abstract;
};  

/* *****************************************************************************************
 * End of file
 */

#endif/* MCUF_D3D44900_B44C_4E13_B861_E5956D0061D7 */
