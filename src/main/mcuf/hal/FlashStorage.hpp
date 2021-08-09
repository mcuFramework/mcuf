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
#include "../hal/Base.hpp"
#include "../function/Consumer.hpp"
#include "../function/ConsumerEvent.hpp"
#include "../lang/Memory.hpp"
#include "../lang/Pointer.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    class FlashStorage;
  }
}



/* ****************************************************************************************
 * Class FlashStorage
 */  
class mcuf::hal::FlashStorage : 
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
  public: virtual uint32_t flashSize(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t pageSize(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t sectorSize(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t minimumWriteSize(void) = 0;


  /**
   * 
   */
  public: virtual bool write(mcuf::lang::Memory& memory,
                             mcuf::function::Consumer<mcuf::lang::Memory&>* function) = 0;

  /**
   * 
   */
  public: virtual mcuf::lang::Pointer readDirect(uint32_t address) = 0;

  /**
   * 
   */
  public: virtual mcuf::lang::Memory readDirect(uint32_t address, uint32_t size) = 0;  

  /**
   * 
   */
  public: virtual bool read(mcuf::lang::Memory& memory,
                            mcuf::function::Consumer<mcuf::lang::Memory&>* function) = 0;

  
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: FlashStorage(void) = default;
  
  /**
   * 
   */
  public: virtual ~FlashStorage(void) = default;
  
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
