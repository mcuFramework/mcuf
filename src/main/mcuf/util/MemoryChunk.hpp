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
  public: struct Node{
    uint16_t next;
    uint16_t prev;
    uint16_t fast;
    uint16_t checksum;
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
  
  private: uint32_t mChunkSize;
  private: uint32_t mChunkQuantity;

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
  private: uint16_t getNodeSerialNumber(Node* node);
  
  /**
   * get next node.
   * 
   * @oaram node
   * @return node = unused node, nullptr = not found unused node.
   */
  private: Node* getNextNode(Node* node);  
  
  /**
   * get next node.
   * 
   * @oaram node
   * @param shift
   * @return node = unused node, nullptr = not found unused node.
   */
  private: Node* getNextNode(Node* node, uint16_t shift);
  
  /**
   * get next node size as byte.
   * 
   * @oaram node
   * @return get node size as byte.
   */
  private: uint32_t getNextNodeSize(Node* node);  

  /**
   * get next previous node.
   * 
   * @oaram node
   * @return node = unused node, nullptr = not found unused node.
   */
  private: Node* getPrevNode(Node* node);

  /**
   * get next previous node.
   * 
   * @oaram node
   * @param shift
   * @return node = unused node, nullptr = not found unused node.
   */
  private: Node* getPrevNode(Node* node, uint16_t shift);  
  
  /**
   * get previous node size as byte.
   *
   * @return get node size as byte.
   */
  private: uint32_t getPrevNodeSize(Node* node);  
  
  /** 
   * Get node status.
   *
   * @return true = using, false = unused
   */
  private: bool getNodeStatus(Node* node);
  
  /**
   * Get next unused node.
   *
   * @return node = unused node, nullptr = not found unused node.
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
