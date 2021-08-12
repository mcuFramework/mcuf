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
#include "../hal/Base.hpp"
#include "../function/BiConsumer.hpp"
#include "../lang/Pointer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    class SerialPeripheral;
  }
}



/* ****************************************************************************************
 * Class SerialPeripheral
 */  
class mcuf::hal::SerialPeripheral:
      public mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */
  public: struct Packet{
    void* mTransferPointer;
    void* mReceiverPointer;
    uint16_t mLength;
    uint16_t mDummy;
  };

  /* **************************************************************************************
   * Enum Polarity
   */
  public: enum Polarity{
    ACTIVE_HIGH = 0x0U,
    ACTIVE_LOW = 0x1U
  };

  /* **************************************************************************************
   * Enum Phase
   */
  public: enum Phase{
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
  public: virtual uint32_t clockRate(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t clockRate(uint32_t clock) = 0;

  /**
   * 
   */
  public: virtual bool isBusy(void) = 0;

  /**
   * 
   */
  public: virtual bool lsb(void) = 0;

  /**
   * 
   */
  public: virtual bool lsb(bool enable) = 0;

  /**
   * 
   */
  public: virtual Phase phase(void) = 0;

  /**
   * 
   */
  public: virtual bool phase(Phase set) = 0;

  /**
   * 
   */
  public: virtual Polarity polarity(void) = 0;

  /**
   * 
   */
  public: virtual bool polarity(Polarity set) = 0;

  /**
   * 
   */
  public: virtual bool transfer(Packet& packet,
                                void* attachment,
                                mcuf::function::BiConsumer<Packet, void*>& function) = 0;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: SerialPeripheral(void) = default;
  
  /**
   * 
   */
  public: virtual ~SerialPeripheral() = default;

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
