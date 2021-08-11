/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_FC2DBE4C_D417_448E_8824_A88F579A5EF3
#define MCUF_FC2DBE4C_D417_448E_8824_A88F579A5EF3
/* ****************************************************************************************
 * Include
 */  
#include "../lang/Object.hpp"
#include "../lang/Memory.hpp"
#include "../util/Collection.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class Fifo;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::util::Fifo :
      public mcuf::util::Collection<mcuf::lang::Memory>{

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
  private: mcuf::lang::Memory mMemory;
  private: uint16_t mElementSize;
  private: uint16_t mTail;
  private: uint16_t mHead;
  private: uint16_t mCapacity;

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
  public: Fifo(mcuf::lang::Memory memory, uint32_t elementSize);

  /**
   * Disconstruct.
   */
  public: virtual ~Fifo(void) = default;

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
   * @action - The action to be performed for each element.
   */
  public: virtual void forEach(mcuf::function::Consumer<mcuf::lang::Memory>& action) = 0;

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
  public: void flush(void);

  /**
   * 
   */
  public: mcuf::lang::Memory getHead(void);

  /**
   * 
   */
  public: void* getHeadPointer(void);

  /**
   * 
   */
  public: mcuf::lang::Memory getTail(void);

  /**
   * 
   */
  public: void* getTailPointer(void);  

  /**
   * 
   */
  public: bool insert(mcuf::lang::Memory memory);

  /**
   * 
   */
  public: bool insert(void* pointer);

  /**
   * 
   */
  public: bool isFull(void);

  /**
   * 
   */
  public: bool pop(mcuf::lang::Memory memory);

  /**
   * 
   */
  public: bool pop(void* pointer);

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


#endif /* MCUF_FC2DBE4C_D417_448E_8824_A88F579A5EF3 */