/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A6F08389_E478_4DE1_B194_3B056285084C
#define MCUF_A6F08389_E478_4DE1_B194_3B056285084C

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "hal/Base.h"
#include "hal/SerialPeriphEvent.h"
#include "hal/SerialPeriphPhase.h"
#include "hal/SerialPeriphPolarity.h"
#include "hal/SerialPeriphSignificantBit.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace serial{
    interface SerialPeriphSlot;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::serial::SerialPeriphSlot extends 
hal::Base{

  /* **************************************************************************************
   * Method
   */
   
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abort(void) abstract;
  
  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t clock(void) abstract;

  /**
   * @brief 
   * 
   * @return true confi clock successful.
   * @return false config clock fail.
   */
  virtual bool clock(uint32_t) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isBusy(void) abstract;

  /**
   * @brief 
   * 
   * @return hal::serial::SerialPeriphSignificantBit 
   */
  virtual hal::serial::SerialPeriphSignificantBit significantBit(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool significantBit(hal::serial::SerialPeriphSignificantBit newStatus) abstract;

  /**
   * @brief 
   * 
   * @return hal::serial::SerialPeriphPolarity 
   */
  virtual hal::serial::SerialPeriphPolarity polarity(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool polarity(hal::serial::SerialPeriphPolarity snewStatustatus) abstract;

  /**
   * @brief 
   * 
   * @return hal::serial::SerialPeriphPhase 
   */
  virtual hal::serial::SerialPeriphPhase phase(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool phase(hal::serial::SerialPeriphPhase newStatus) abstract;

  /**
   * @brief 
   * 
   * @param chipSelect 
   * @param packet 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool transfer(mcuf::io::ByteBuffer* tx,
                        mcuf::io::ByteBuffer* rx,
                        SerialPeriphEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A6F08389_E478_4DE1_B194_3B056285084C */
