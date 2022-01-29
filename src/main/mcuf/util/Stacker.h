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
#include "mcuf/util/Collection.h"
#include "mcuf/lang/Memory.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class Stacker;
  }
}

/* ****************************************************************************************
 * Class Stacker
 */  
class mcuf::util::Stacker extends mcuf::lang::Memory
      implements mcuf::util::Collection<mcuf::lang::Memory>{
  
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: uint8_t* mStackPointer;

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
  public: Stacker(void* buffer, uint32_t size);

  /**
   * Construct.
   */
  public: Stacker(const mcuf::lang::Memory& memory);

  /**
   * Destruct.
   */
  public: virtual ~Stacker() = default;

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
  public: virtual void forEach(mcuf::function::Consumer<mcuf::lang::Memory*>& action) override;

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
  public: virtual uint32_t getFree(void);

  /**
   * 
   */
  public: virtual void* alloc(uint32_t size);
  
  /**
   *
   */
  public: virtual void* allocAlignment32(uint32_t size);
  
  /**
   *
   */
  public: virtual void* allocAlignment64(uint32_t size);  

  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemory(uint32_t size);
  
  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemoryAlignment32(uint32_t size);

  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemoryAlignment64(uint32_t size);

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
