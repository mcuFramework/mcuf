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
#include "mcuf_base.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/util/Collection.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class Fifo;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::util::Fifo extends mcuf::lang::Memory implements 
  public mcuf::util::Collection<mcuf::lang::Memory>{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    uint16_t mElementSize;
    uint16_t mElementLength;
    uint16_t mHead;
    uint16_t mTail;
    bool mEmpty;

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
     * @brief Construct a new Fifo object
     * 
     * @param memory 
     * @param elementSize 
     */
    Fifo(const mcuf::lang::Memory& memory, uint32_t elementSize);

    /**
     * @brief Destroy the Fifo object
     * 
     */
    virtual ~Fifo(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Iterable<E>
   */
  public:
    /**
     * @brief Performs the given action for each element of the Iterable until all 
     *        elements have been processed or the action throws an exception. Unless 
     *        otherwise specified by the implementing class, actions are performed in the 
     *        order of iteration (if an iteration order is specified). 
     * 
     * @param attachment 
     * @param action 
     */
    virtual void forEach(void* attachment, 
                        mcuf::function::BiConsumer<mcuf::lang::Memory*, void*>& action) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::util::Collection<E>
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
     * @return true if this collection contains no elements.
     * @return false 
     */
    virtual bool isEmpty(void) override;

    /**
     * @brief Returns the number of elements in this collection.
     * 
     * @return uint32_t the number of elements in this collection.
     */
    virtual uint32_t size(void) override;

  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief Get the Head object
     * 
     * @return mcuf::lang::Memory 
     */
    mcuf::lang::Memory getHead(void);

    /**
     * @brief Get the Head Pointer object
     * 
     * @return void* 
     */
    void* getHeadPointer(void);

    /**
     * @brief Get the Tail object
     * 
     * @return mcuf::lang::Memory 
     */
    mcuf::lang::Memory getTail(void);

    /**
     * @brief Get the Tail Pointer object
     * 
     * @return void* 
     */
    void* getTailPointer(void);  

    /**
     * @brief 
     * 
     * @param memory 
     * @return true 
     * @return false 
     */
    bool insertHead(const mcuf::lang::Memory& memory);

    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    bool insertHead(void* pointer);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isFull(void);

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    uint32_t length(void);

    /**
     * @brief 
     * 
     * @param memory 
     * @return true 
     * @return false 
     */
    bool popTail(mcuf::lang::Memory& memory);

    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    bool popTail(void* pointer);  

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
