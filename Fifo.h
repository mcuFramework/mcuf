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
#include "./mcuf_base.h"
#include "./Object.h"
#include "./Memory.h"
#include "./Collection.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class Fifo;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::Fifo extends mcuf::Memory implements 
  public mcuf::Collection<mcuf::Memory>{

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
    Fifo(const mcuf::Memory& memory, uint32_t elementSize);

    /**
     * @brief Construct a new Fifo object
     * 
     * @param size 
     * @param elementSize 
     */
    Fifo(uint32_t size, uint32_t elementSize);

    /**
     * @brief Destroy the Fifo object
     * 
     */
    virtual ~Fifo(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::Iterable<E>
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
                        mcuf::function::BiConsumer<mcuf::Memory*, void*>& action) const override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::Collection<E>
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
    virtual bool isEmpty(void) const override;

    /**
     * @brief Returns the number of elements in this collection.
     * 
     * @return uint32_t the number of elements in this collection.
     */
    virtual int size(void) const override;

  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief Get the Head object
     * 
     * @return mcuf::Memory 
     */
    mcuf::Memory getHead(void);

    /**
     * @brief Get the Head Pointer object
     * 
     * @return void* 
     */
    void* getHeadPointer(void);

    /**
     * @brief Get the Tail object
     * 
     * @return mcuf::Memory 
     */
    mcuf::Memory getTail(void);

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
    bool insertHead(const mcuf::Memory& memory);

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
    bool isFull(void) const;

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    uint32_t length(void) const;

    /**
     * @brief 
     * 
     * @param memory 
     * @return true 
     * @return false 
     */
    bool popTail(mcuf::Memory& memory);

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
