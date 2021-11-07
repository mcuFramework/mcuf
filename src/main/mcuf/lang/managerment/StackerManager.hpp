/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DDCD3A4D_0FC6_470B_9D90_3EADC6BC1D97
#define MCUF_DDCD3A4D_0FC6_470B_9D90_3EADC6BC1D97

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/util/Stacker.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class System;
    namespace managerment{
      class StackerManager;
    }
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::lang::managerment::StackerManager extends mcuf::util::Stacker{

  friend mcuf::lang::System;
  
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

  /**
   * Construct.
   */
  public: StackerManager(void* buffer, uint32_t size);

  /**
   * Construct.
   */
  public: StackerManager(mcuf::lang::Memory& memory);

  /**
   * Destruct.
   */
  public: virtual ~StackerManager(void) = default;

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
   * Public Method <Override> - mcuf::util::Stacker
   */
   
  /**
   * 
   */
  public: virtual void* alloc(uint32_t size) override;
  
  /**
   *
   */
  public: virtual void* allocAlignment32(uint32_t size) override;
  
  /**
   *
   */
  public: virtual void* allocAlignment64(uint32_t size) override;  

  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemory(uint32_t size) override;
  
  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemoryAlignment32(uint32_t size) override;

  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemoryAlignment64(uint32_t size) override;
  
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

#endif/* MCUF_DDCD3A4D_0FC6_470B_9D90_3EADC6BC1D97 */
