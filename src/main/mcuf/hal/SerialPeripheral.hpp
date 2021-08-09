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
  public: class Packet;

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
  public: virtual bool isBusy(void) = 0;

  /**
   * 
   */
  public: virtual bool lsb(bool enable) = 0;

  /**
   * 
   */
  public: virtual bool lsb(void) = 0;

  /**
   * 
   */
  public: virtual bool polarity(Polarity set) = 0;

  /**
   * 
   */
  public: virtual Polarity polarity(void) = 0;

  /**
   * 
   */
  public: virtual bool phase(Phase set) = 0;

  /**
   * 
   */
  public: virtual Phase phase(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t clockRate(uint32_t clock) = 0;

  /**
   * 
   */
  public: virtual uint32_t clockRate(void) = 0;

  /**
   * 
   */
  public: virtual bool transfer(Packet& packet,
                                mcuf::lang::Pointer attachment,
                                mcuf::function::BiConsumer<Packet, mcuf::lang::Pointer>& function) = 0;

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



/* ****************************************************************************************
 * Class SerialPeripheral
 */  
class mcuf::hal::SerialPeripheral::Packet:
      public mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: void* mTransferPointer;
  private: void* mReceiverPointer;
  private: uint16_t mLength;
  private: uint16_t mDummy;

  /* **************************************************************************************
   * Abstract method <Public>
   */
   
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: Packet(void);

  /**
   * 
   */
  public: Packet(void* transferPointer, void* receiverPointer, uint16_t length, uint16_t dummy); 
  
  /**
   * 
   */
  public: virtual ~Packet() = default;

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

  /**
   * 
   */
  public: uint16_t dummy(void);
  
  /**
   * 
   */
  public: Packet* dummy(uint16_t dummy);

  /**
   * 
   */
  public: uint16_t length(void);
  
  /**
   * 
   */
  public: Packet* length(uint16_t length);

  /**
   * 
   */
  public: void* ReceiverPointer(void);

  /**
   * 
   */
  public: Packet* ReceiverPointer(void* pointer);

  /**
   * 
   */
  public: Packet* ReceiverPointer(mcuf::lang::Pointer pointer);  

  /**
   * 
   */
  public: void* TransferPointer(void);

  /**
   * 
   */
  public: Packet* TransferPointer(void* pointer);

  /**
   * 
   */
  public: Packet* TransferPointer(mcuf::lang::Pointer pointer);  


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
