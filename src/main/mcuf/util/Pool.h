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
#include "mcuf/function/Consumer.h"
#include "mcuf/lang/Array.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/util/Collection.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    interface Pool;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::util::Pool extends mcuf::util::Collection<mcuf::lang::Memory>{

  /* **************************************************************************************
   * Method 
   */

  /**
   * @brief Returns this pool element size of byte
   * 
   * @return uint32_t element size of byte.
   */
  virtual uint32_t elementSize(void) abstract;
  
  /**
   * @brief Returns this pool's capacity.
   * 
   * @return uint32_t The capacity of this pool.
   */
  virtual uint32_t capacity(void) abstract;
  
  /**
   * @brief Alloc memory from pool.
   * 
   * @return void* element pointer if pool not full, otherwise null pointer.
   */
  virtual void* alloc(void) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::lang::Memory 
   */
  virtual mcuf::lang::Memory allocMemory(void) abstract;

  /**
   * @brief Alloc memory from pool and copy element.
   * 
   * @param elenemt Element pointer.
   * @return void* element pointer if pool not full, otherwise null pointer.
   */
  virtual void* add(const void* elenemt) abstract;

  /**
   * @brief Free this element memory.  
   * 
   * @param element Element pointer.
   * @return true this poll found element and remove.
   * @return false element not found in this pool.
   */
  virtual bool remove(void* element) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F */
