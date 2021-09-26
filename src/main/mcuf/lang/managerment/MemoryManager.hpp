/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F8B90962_2CA1_4BCF_AB1E_3E9F5FB48DE3
#define MCUF_F8B90962_2CA1_4BCF_AB1E_3E9F5FB48DE3

/* ****************************************************************************************
 * Include
 */  
 
//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf_config.h"
#include "mcuf/lang/Object.hpp"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/util/VectorBlockPool.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace managerment{
      class MemoryManager;
    }
  }
}



/* ****************************************************************************************
 * Class MemoryManager
 */  
class mcuf::lang::managerment::MemoryManager extends mcuf::lang::Object{

  
  /* **************************************************************************************
   * Subclass
   */
  
  /* **************************************************************************************
   * Struct handleMemory
   */
  private: struct{
    uint8_t entity[sizeof(mcuf::util::VectorBlockPool)];
    uint8_t m[sizeof(mcuf::util::VectorBlockPool) * 16];
    uint8_t f[2];
  }handleMemory;

   /* **************************************************************************************
   * Variable <Constant>
   */

  /* **************************************************************************************
   * Variable <Public>
   */
  public: static const uint16_t BASE_BLOCK_SIZE;
  public: static const uint16_t NUMBER_OF_BLOCK_QUANTITY;
  public: static const uint16_t BLOCK_SIZE[MCUF_MEMORY_MANAGERMENT_BLOCk_TYPE_QUANTITY];

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  public: mcuf::util::VectorBlockPool* entityPool;
  public: mcuf::util::VectorBlockPool* blocks[MCUF_MEMORY_MANAGERMENT_BLOCk_TYPE_QUANTITY];

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
  public: MemoryManager(mcuf::lang::Memory& memory);

  /**
   * Destruct.
   */
  public: virtual ~MemoryManager(void) = default;

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

  /**
   * 
   */
  public: void* alloc(size_t size);

  /**
   * 
   */
  public: mcuf::lang::Memory allocMemory(size_t size);
  
  /**
   * 
   */
  public: bool free(void* pointer);

  /**
   * 
   */
  public: bool free(void* pointer, size_t size);

  /**
   * 
   */
  public: bool freeMemory(mcuf::lang::Memory& memory);

  /**
   * 
   */
  public: bool expansion(mcuf::lang::Memory& memory);



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

  /**
   * 
   */
  private: mcuf::lang::Memory allocAuto(size_t size);

  /**
   * 
   */
  private: mcuf::lang::Memory allocCeil(size_t size);

  /**
   * 
   */
  private: mcuf::lang::Memory allocDirect(size_t size);

  /**
   * 
   */
  private: mcuf::lang::Memory allocFloor(size_t size);

  /**
   * 
   */
  private: mcuf::lang::Memory allocEntityBlockMemory(void);

  /**
   * 
   */
  private: mcuf::util::VectorBlockPool* constructVectorBlockPool(mcuf::lang::Memory& memory, uint16_t blockShift);

  /**
   * 
   */
  private: bool expansionBlock(uint16_t blockShift);

  /**
   * 
   */
  private: int foundBlockShift(size_t size);

  /**
   * 
   */
  private: void initEntityPool(void);

  /**
   * 
   */
  private: void initBlocks(mcuf::lang::Memory& memory);

};




/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_F8B90962_2CA1_4BCF_AB1E_3E9F5FB48DE3 */
