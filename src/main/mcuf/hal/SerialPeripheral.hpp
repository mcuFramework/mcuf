/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6
#define MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/hal/Base.hpp"
#include "mcuf/function/BiConsumer.hpp"
#include "mcuf/lang/Pointer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPeripheral;
  }
}



/* ****************************************************************************************
 * Class SerialPeripheral
 */  
interface mcuf::hal::SerialPeripheral implement mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */
  struct Packet{
    void* mTransferPointer;
    void* mReceiverPointer;
    uint16_t mLength;
    uint16_t mDummy;
  };

  /* **************************************************************************************
   * Enum Polarity
   */
  enum Polarity{
    ACTIVE_HIGH = 0x0U,
    ACTIVE_LOW = 0x1U
  };

  /* **************************************************************************************
   * Enum Phase
   */
  enum Phase{
    FIRST_EDGE = 0x0U,
    SECOND_EDGE = 0x1U
  };

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */
   
  /**
   * 
   */
  virtual uint32_t clockRate(void) abstract;

  /**
   * 
   */
  virtual uint32_t clockRate(uint32_t clock) abstract;

  /**
   * 
   */
  virtual bool isBusy(void) abstract;

  /**
   * 
   */
  virtual bool lsb(void) abstract;

  /**
   * 
   */
  virtual bool lsb(bool enable) abstract;

  /**
   * 
   */
  virtual Phase phase(void) abstract;

  /**
   * 
   */
  virtual bool phase(Phase set) abstract;

  /**
   * 
   */
  virtual Polarity polarity(void) abstract;

  /**
   * 
   */
  virtual bool polarity(Polarity set) abstract;

  /**
   * 
   */
  virtual bool transfer(Packet* packet,
                                void* attachment,
                                mcuf::function::BiConsumer<Packet*, void*>* function) abstract;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */
    
};



/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6 */
