/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695
#define MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/hal/Base.hpp"
#include "mcuf/function/Consumer.hpp"
#include "mcuf/function/ConsumerEvent.hpp"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/lang/Pointer.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    interface FlashStorage;
  }
}



/* ****************************************************************************************
 * Class FlashStorage
 */  
interface mcuf::hal::FlashStorage implement mcuf::hal::Base{

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
  virtual uint32_t flashSize(void) abstract;

  /**
   * 
   */
  virtual uint32_t pageSize(void) abstract;

  /**
   * 
   */
  virtual uint32_t sectorSize(void) abstract;

  /**
   * 
   */
  virtual uint32_t minimumWriteSize(void) abstract;


  /**
   * 
   */
  virtual bool write(mcuf::lang::Memory& memory,
                     mcuf::function::Consumer<mcuf::lang::Memory&>* function) abstract;

  /**
   * 
   */
  virtual mcuf::lang::Pointer readDirect(uint32_t address) abstract;

  /**
   * 
   */
  virtual mcuf::lang::Memory readDirect(uint32_t address, uint32_t size) abstract;  

  /**
   * 
   */
  virtual bool read(mcuf::lang::Memory& memory,
                    mcuf::function::Consumer<mcuf::lang::Memory&>* function) abstract;

  
  
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


#endif/* MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695 */
