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
#include "mcuf_base.h"
#include "mcuf\hal\Base.hpp"
#include "mcuf\function\Consumer.hpp"
#include "mcuf\io\channel\ByteBuffer.hpp"
#include "mcuf\lang\Pointer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPort;
  }
}



/* ****************************************************************************************
 * Class SerialPort
 */  
interface mcuf::hal::SerialPort implement mcuf::hal::Base{
        
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
  virtual bool abortRead(void) abstract;

  /**
   * 
   */
  virtual bool abortWrite(void) abstract;

  /**
   * 
   */
  virtual uint32_t baudrate(void) abstract;

  /**
   * 
   */
  virtual uint32_t baudrate(uint32_t rate) abstract;

  /**
   *
   */
  virtual bool readBusy(void) abstract;

  /**
   *
   */
  virtual bool writeBusy(void) abstract;

  /**
   * 
   */
  virtual bool read(mcuf::io::channel::ByteBuffer& byteBuffer, 
                            mcuf::function::Consumer<mcuf::io::channel::ByteBuffer&>* consumer) abstract;

  /**
   * 
   */
  virtual bool write(mcuf::io::channel::ByteBuffer& byteBuffer, 
                             mcuf::function::Consumer<mcuf::io::channel::ByteBuffer&>* consumer) abstract;
  
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


#endif/* MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19 */
