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
  
  /**
   * struct Node
   */
  private: struct Node{
    uint16_t next;
    uint16_t prev;
    uint16_t fast;
    uint16_t checksum;
  };
  
  /**
   *
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
  
  private: uint32_t mChunkSize;
  private: uint16_t mFreeHead;

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
  public: MemoryChunk(mcuf::lang::Memory& memory, uint32_t chunkSize);
  
  /**
   * Construct.
   */
  public: MemoryChunk(mcuf::lang::Memory&& memory, uint32_t chunkSize);  

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
  private: Node* getNode(uint16_t chunk);
  
  /**
   *
   */
  private: uint32_t getNodeSize(Node* node);
  
  /**
   *
   */
  private: uint32_t getPrevNodeSize(Node* node);  
  
  /** 
   *
   */
  private: bool getNodeStatus(Node* node);
  
  /**
   *
   */
  private: Node* getNextNode(Node* node);
  
  /**
   *
   */
  private: Node* getPrevNode(Node* node);
  
  /**
   *
   */
  private: Node* getFastNode(Node* node);
  
  /**
   *
   */
  private: bool setNodeUsing(Node* node);
  
  /**
   *
   */
  private: bool setNodeUnused(Node* node);  

  /**
   *
   */
  private: bool splitNode(Node* node, uint16_t split);

  /**
   *
   */
  private: bool mergeNode(Node* node);

  /**
   *
   */
  private: bool veriftNode(Node* node);
  
  /**
   *
   */
  private: Node configNode(uint16_t prev, uint16_t next, uint16_t fast);
  
  /**
   *
   */
  private: uint16_t getNodeChecksum(Node* node);

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_F48A5F39_DD99_4D2C_9E97_CC9E88B36DDF */
