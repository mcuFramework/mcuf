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
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/hal/serial/periph/SerialPeriphEvent.h"
#include "mcuf/hal/serial/periph/SerialPeriphPhase.h"
#include "mcuf/hal/serial/periph/SerialPeriphPolarity.h"
#include "mcuf/hal/serial/periph/SerialPeriphSignificantBit.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace periph{
        interface SerialPeriphSlot;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::serial::periph::SerialPeriphSlot extends mcuf::hal::Base{

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
   * @return mcuf::hal::serial::periph::SerialPeriphSignificantBit 
   */
  virtual mcuf::hal::serial::periph::SerialPeriphSignificantBit significantBit(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool significantBit(mcuf::hal::serial::periph::SerialPeriphSignificantBit newStatus) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::hal::serial::periph::SerialPeriphPolarity 
   */
  virtual mcuf::hal::serial::periph::SerialPeriphPolarity polarity(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool polarity(mcuf::hal::serial::periph::SerialPeriphPolarity snewStatustatus) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::hal::serial::periph::SerialPeriphPhase 
   */
  virtual mcuf::hal::serial::periph::SerialPeriphPhase phase(void) abstract;

  /**
   * @brief 
   * 
   * @param newStatus 
   * @return true 
   * @return false 
   */
  virtual bool phase(mcuf::hal::serial::periph::SerialPeriphPhase newStatus) abstract;

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

#endif/* MCUF_A6F08389_E478_4DE1_B194_3B056285084C */
