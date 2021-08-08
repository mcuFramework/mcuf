/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19
#define MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19

/* ****************************************************************************************
 * Include
 */  
#include "..\hal\Base.hpp"
#include "..\function\BiConsumer.hpp"
#include "..\lang\Memory.hpp"
#include "..\lang\Pointer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    class SerialPort;
  }
}



/* ****************************************************************************************
 * Class SerialPort
 */  
class mcuf::hal::SerialPort : 
      public mcuf::hal::Base{
        
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

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /**
   * 
   */
  public: virtual bool open(void) = 0;

  /**
   * 
   */
  public: virtual void close(void) = 0;

  /**
   * 
   */
  public: virtual bool isOpen(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t baudrate(uint32_t rate) = 0;
  
  /**
   * 
   */
  public: virtual uint32_t baudrate(void) = 0;

  /**
   * 
   */
  public: virtual int available(void) = 0;

  /**
   * 
   */
  public: virtual bool read(mcuf::lang::Memory& memory, 
                            mcuf::lang::Pointer* attachment,
                            mcuf::function::BiConsumer<mcuf::lang::Memory&, mcuf::lang::Pointer&>* function) = 0;

  /**
   * 
   */
  public: virtual bool write(mcuf::lang::Memory& memory, 
                             mcuf::lang::Pointer* attachment,
                             mcuf::function::BiConsumer<mcuf::lang::Memory&, mcuf::lang::Pointer&>* function) = 0;
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: SerialPort(void) = default;
  
  /**
   * 
   */
  public: virtual ~SerialPort() = default;
  
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


#endif/* MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19 */
