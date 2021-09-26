/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F
#define MCUF_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/function/Consumer.hpp"
#include "mcuf/lang/Array.hpp"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/util/Collection.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    interface Pool;
  }
}

/* ****************************************************************************************
 * Class Pool
 */  
interface mcuf::util::Pool implement mcuf::util::Collection<mcuf::lang::Memory&>{
  
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
   * Returns this pool element size of byte
   *
   * @return element size of byte.
   */
  public: virtual uint32_t elementSize(void) = 0;
  
  /**
   * Returns this pool's capacity.
   *
   * @return The capacity of this pool.
   */
  public: virtual uint32_t capacity(void) = 0;
  
  /**
   * Alloc memory from pool.
   *
   * @return element pointer if pool not full, otherwise null pointer.
   */
  public: virtual void* alloc(void) = 0;

  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemory(void) = 0;
  
  /**
   * Alloc memory from pool and copy element.
   *
   * @element Element pointer.
   * @return element pointer if pool not full, otherwise null pointer.
   */
  public: virtual void* add(void* elenemt) = 0;
  
  /**
   * Free this element memory.  
   *
   * @element Element pointer.
   * @return true if this poll found element and remove.
   */
  public: virtual bool remove(void* element) = 0;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  
  /**
   * Construct.
   */
  public: Pool(void) = default;

  /**
   * Disconstruct.
   */
  public: virtual ~Pool() = default;

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

#endif/* MCUF_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F */
