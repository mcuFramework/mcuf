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
interface mcuf::util::Pool implement mcuf::util::Collection<mcuf::lang::Memory>{
  
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
  virtual uint32_t elementSize(void) abstract;
  
  /**
   * Returns this pool's capacity.
   *
   * @return The capacity of this pool.
   */
  virtual uint32_t capacity(void) abstract;
  
  /**
   * Alloc memory from pool.
   *
   * @return element pointer if pool not full, otherwise null pointer.
   */
  virtual void* alloc(void) abstract;

  /**
   * 
   */
  virtual mcuf::lang::Memory allocMemory(void) abstract;
  
  /**
   * Alloc memory from pool and copy element.
   *
   * @element Element pointer.
   * @return element pointer if pool not full, otherwise null pointer.
   */
  virtual void* add(void* elenemt) abstract;
  
  /**
   * Free this element memory.  
   *
   * @element Element pointer.
   * @return true if this poll found element and remove.
   */
  virtual bool remove(void* element) abstract;

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

#endif/* MCUF_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F */
