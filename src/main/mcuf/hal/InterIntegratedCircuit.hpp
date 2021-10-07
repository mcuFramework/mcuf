/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474
#define MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf\hal\Base.hpp"
#include "mcuf\io\channel\ByteBuffer.hpp"
#include "mcuf\io\channel\CompletionHandler.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface InterIntegratedCircuit;
  }
}



/* ****************************************************************************************
 * Class InterIntegratedCircuit
 */  
interface mcuf::hal::InterIntegratedCircuit implement mcuf::hal::Base{

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
  virtual void read(uint8_t address, 
                     mcuf::io::channel::ByteBuffer* bytebuffer,
                     void* attachment,
                     mcuf::io::channel::CompletionHandler<int, void*>* handler) abstract;

  /**
   * 
   */
  virtual void write(uint8_t address, 
                     mcuf::io::channel::ByteBuffer* bytebuffer,
                     void* attachment,
                     mcuf::io::channel::CompletionHandler<int, void*>* handler) abstract;

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


#endif/* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
