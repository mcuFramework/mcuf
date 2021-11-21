/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F48A5F39_DD99_4D2C_9E97_CC9E88B36DDF
#define MCUF_F48A5F39_DD99_4D2C_9E97_CC9E88B36DDF

/* ****************************************************************************************
 * Include
 */  

#include "mcuf_base.h"
#include "mcuf/lang/Memory.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class MemoryChunk;
  }
}

/* ****************************************************************************************
 * Class mcuf::util::MemoryChunk
 */  
class mcuf::util::MemoryChunk extends mcuf::lang::Memory{

  /* **************************************************************************************
   * Subclass
   */
  private: struct Node{
    uint16_t next;
    uint16_t prev;
    uint16_t size;
    uint8_t config;
    uint8_t checksum;
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
  private: uint16_t mChunkSize;

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
  public: MemoryChunk(mcuf::lang::Memory& memory, uint16_t chunkSize);
  
  /**
   * Construct.
   */
  public: MemoryChunk(mcuf::lang::Memory&& memory, uint16_t chunkSize);  

  /**
   * Destruct.
   */
  public: virtual ~MemoryChunk(void) = default;

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
  public: Memory allocChunk(uint16_t numberOfChunk);
  
  /**
   *
   */
  public: bool freeChunk(Memory& memory);
  
  /**
   *
   */
  public: void reset(void);

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
  private: bool veriftNode(Node* node);
  
  /**
   *
   */
  private: Node configNode(uint16_t prev, uint16_t next, uint16_t size, uint8_t config);
  
  /**
   *
   */
  private: uint8_t getNodeChecksum(Node* node);

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_F48A5F39_DD99_4D2C_9E97_CC9E88B36DDF */
