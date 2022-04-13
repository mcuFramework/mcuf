/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_819EF0C3_9A1E_49F9_B8BA_987BCBD67365
#define MCUF_819EF0C3_9A1E_49F9_B8BA_987BCBD67365

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf\lang\Memory.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class MemoryPool;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::util::MemoryPool extends mcuf::lang::Memory implements
  public mcuf::lang::Allocator{

  /* **************************************************************************************
   * Struct Node
   */
  public:
    struct Node{
      Node* prev;
      Node* next;
      Node* linkPrev;
      Node* linkNext;
    };

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
    uint32_t mMin;
    uint32_t mMax;
    Node* mNode;
    Node* mFreeNode;

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
     * @brief Construct a new Memory Pool object
     * 
     * @param memory 
     * @param min 
     * @param max 
     */
    MemoryPool(const mcuf::lang::Memory& memory, uint32_t min, uint32_t max);

    /**
     * @brief Destroy the Memory Pool object
     * 
     */
    virtual ~MemoryPool(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Memory
   */
  public:
    /**
     * @brief 
     * 
     * @return Memory& 
     */
    virtual bool wipe(void) override;
    
    /**
     * @brief 
     * 
     * @param value 
     * @return Memory& 
     */
    virtual bool wipe(uint8_t value) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Allocator
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
     * @param ptr 
     * @return true 
     * @return false 
     */
    virtual bool free(void* ptr) override;

    /**
     * @brief 
     * 
     * @param ptr 
     * @param size 
     * @return true 
     * @return false 
     */
    virtual bool free(void* ptr, uint32_t size) override;    

  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief Get the Free Size object
     * 
     * @return uint32_t 
     */
    virtual uint32_t getFreeSize(void);

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
  private:
    /**
     *
     */
    Node* split(Node* node, uint32_t size);
  
    /**
     *
     */
    uint32_t getNodeSize(Node* node);
  
    /**
     *
     */
    bool merge(Node* node);
  
    /**
     *
     */
    bool markUsing(Node* node);
  
    /**
     *
     */
    bool markFree(Node* node);
    
    /**
     *
     */
    bool isNodeFree(Node* node);
    
    /**
     *
     */
    Node* allocFreeNode(uint32_t size, bool head);
    
    /**
     *
     */
    uint32_t valuePowerful(uint32_t value);
    
    /**
     *
     */
    uint32_t sizePowerful(uint32_t size);
    
    /**
     *
     */
    bool verifyNode(Node* node);

};

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  


/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_819EF0C3_9A1E_49F9_B8BA_987BCBD67365 */
