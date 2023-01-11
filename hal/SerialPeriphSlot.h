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
#include "../mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"
#include "./SerialPeriphEvent.h"
#include "./SerialPeriphPhase.h"
#include "./SerialPeriphPolarity.h"
#include "./SerialPeriphSignificantBit.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{
  interface SerialPeriphSlot;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialPeriphSlot extends 
mcuf::hal::Base{

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
   * @return mcuf::hal::SerialPeriphSignificantBit 
   */
  virtual mcuf::hal::SerialPeriphSignificantBit significantBit(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool significantBit(mcuf::hal::SerialPeriphSignificantBit newStatus) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::hal::SerialPeriphPolarity 
   */
  virtual mcuf::hal::SerialPeriphPolarity polarity(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool polarity(mcuf::hal::SerialPeriphPolarity snewStatustatus) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::hal::SerialPeriphPhase 
   */
  virtual mcuf::hal::SerialPeriphPhase phase(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool phase(mcuf::hal::SerialPeriphPhase newStatus) abstract;

  /**
   * @brief 
   * 
   * @param chipSelect 
   * @param packet 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool transfer(mcuf::ByteBuffer* tx,
                        mcuf::ByteBuffer* rx,
                        SerialPeriphEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A6F08389_E478_4DE1_B194_3B056285084C */
