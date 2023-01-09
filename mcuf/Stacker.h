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
#include "mcuf\Collection.h"
#include "mcuf\Memory.h"
#include "mcuf\Allocator.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class Stacker;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::Stacker extends mcuf::Memory implements 
  public mcuf::Collection<mcuf::Memory>,
  public mcuf::Allocator{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: 
    uint8_t* mStackPointer;

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
  public:
    
    /**
     * @brief Construct a new Stacker object
     * 
     * @param buffer 
     * @param size 
     */
    Stacker(void* buffer, uint32_t size);

    /**
     * @brief Construct a new Stacker object
     * 
     * @param memory 
     */
    Stacker(const mcuf::Memory& memory);

    /**
     * @brief Destroy the Stacker object
     * 
     */
    virtual ~Stacker(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> mcuf::Collection<mcuf::Memory>
   */
  public: 
  
    /**
     * @brief Removes all of the elements from this collection. The collection will be 
     *        empty after this method returns.
     * 
     */
    virtual void clear(void) override;

    /**
     * @brief Returns true if this collection contains no elements.
     * 
     * @return true 
     * @return false 
     */
    virtual bool isEmpty(void) const override;

    /**
     * @brief Returns the number of elements in this collection.
     * 
     * @return uint32_t the number of elements in this collection.
     */
    virtual int size(void) const override;
  
  /* **************************************************************************************
   * Public Method <Override> - mcuf::Iterable<E>
   */
  public:

    /**
     * @brief Performs the given action for each element of the Iterable until all elements
     *        have been processed or the action throws an exception. Unless otherwise 
     *        specified by the implementing class, actions are performed in the order of 
     *        iteration (if an iteration order is specified). 
     * 
     * @param attachment 
     * @param action 
     */
    virtual void forEach(void* attachment, 
                         mcuf::function::BiConsumer<mcuf::Memory*, void*>& action) const override;


  /* **************************************************************************************
   * Public Method <Override> mcuf::Allocator
   */
  public: 

    /**
     * @brief 
     * 
     * @param size 
     */
    virtual void* alloc(uint32_t size) override;

    /**
     * @brief 
     * 
     * @param ptr pointer
     * @return true successful
     * @return false fail
     */
    virtual bool free(void* ptr) override;

    /**
     * @brief 
     * 
     * @param ptr pointer
     * @param size pointer size
     * @return true successful
     * @return false fail
     */
    virtual bool free(void* ptr, uint32_t size) override;
  
  /* **************************************************************************************
   * Public Method 
   */
  public: 

    /**
     * @brief Get the Free object
     * 
     * @return uint32_t 
     */
    virtual uint32_t getFree(void);

    /**
     * @brief 
     * 
     * @param size 
     * @return void* 
     */
    virtual void* allocAlignment32(uint32_t size);
      
    /**
     * @brief 
     * 
     * @param size 
     * @return void* 
     */
    virtual void* allocAlignment64(uint32_t size);  

    /**
     * @brief 
     * 
     * @param size 
     * @return mcuf::Memory 
     */
    virtual mcuf::Memory allocMemory(uint32_t size);
      
    /**
     * @brief 
     * 
     * @param size 
     * @return mcuf::Memory 
     */
    virtual mcuf::Memory allocMemoryAlignment32(uint32_t size);

    /**
     * @brief 
     * 
     * @param size 
     * @return mcuf::Memory 
     */
    virtual mcuf::Memory allocMemoryAlignment64(uint32_t size);

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

#endif /* MCUF_C045F3C4_B727_4170_9124_44EFD0DADB46 */
