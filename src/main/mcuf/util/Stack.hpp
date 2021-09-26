/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C045F3C4_B727_4170_9124_44EFD0DADB46
#define MCUF_C045F3C4_B727_4170_9124_44EFD0DADB46

/* ****************************************************************************************
 * Include
 */ 

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/util/Collection.hpp"
#include "mcuf/lang/Memory.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class Stack;
  }
}

/* ****************************************************************************************
 * Class Stack
 */  
class mcuf::util::Stack extends mcuf::lang::Object
      implements mcuf::util::Collection<mcuf::lang::Memory&>{
  
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: uint8_t* buffer;
  protected: uint32_t bufferSize;
  protected: uint32_t pointer;

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
  public: Stack(void* buffer, uint32_t size);

  /**
   * Construct.
   */
  public: Stack(mcuf::lang::Memory& memory);

  /**
   * Disconstruct.
   */
  public: virtual ~Stack() = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /**
   * Removes all of the elements from this collection. The collection will be empty after 
   * this method returns.
   */
  public: virtual void clear(void) override;

  /**
   * Performs the given action for each element of the Iterable until all elements have 
   * been processed or the action throws an exception. Unless otherwise specified by the 
   * implementing class, actions are performed in the order of iteration (if an iteration 
   * order is specified). 
   *
   * @param Consumer<Memory&>-action The action to be performed for each element.
   */
  public: virtual void forEach(mcuf::function::Consumer<mcuf::lang::Memory&>& action) override;

  /**
   * Returns true if this collection contains no elements.
   * 
   * @return true if this collection contains no elements.
   */
  public: virtual bool isEmpty(void) override;

  /**
   * Returns the number of elements in this collection.
   * 
   * @return the number of elements in this collection.
   */
  public: virtual uint32_t size(void) override;

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: uint32_t getFree(void);

  /**
   * 
   */
  public: uint32_t length(void);

  /**
   * 
   */
  public: void* alloc(uint32_t size);

  /**
   * 
   */
  public: mcuf::lang::Memory allocMemory(uint32_t size);

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

#endif/* MCUF_C045F3C4_B727_4170_9124_44EFD0DADB46 */
