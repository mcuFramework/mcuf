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
  private: class LinkedList;
  
  /**
   * struct Node
   */
  public: struct Node{
    uint16_t next;
    uint16_t prev;
    uint16_t nextLink;
    uint16_t prevLink;
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
  
  private: Node* mAvailableNodeLink;
  private: Node* mUsingNodeLink;
  

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
   * @return 
   */
  private: Node* getNextNode(Node* node);  
  
  /**
   * get next linked node.
   * 
   * @oaram node
   * @return 
   */
  private: Node* getNextLinkNode(Node* node);
  
  /**
   * get next previous node.
   * 
   * @oaram node
   * @return 
   */
  private: Node* getPrevNode(Node* node);

  /**
   * get next previous node.
   * 
   * @oaram node
   * @return 
   */
  private: Node* getPrevLinkNode(Node* node);
  
  /** 
   * Get node status.
   *
   * @return true = using, false = available
   */
  private: bool getNodeStatus(Node* node);
  
  /**
   *
   */
  private: bool setNodeUsing(Node* node);
  
  /**
   *
   */
  private: bool setNodeAvailable(Node* node);

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
  private: uint16_t getNodeChecksum(Node* node);
  
  /**
   *
   */
  private: uint32_t getChunkWithNodeSize(void);
  
  /**
   *
   */
  private: void removeNodeLink(Node* node);
  
  /**
   *
   */
  private: void nodeLinkInsert(Node* linkedNode, Node* node);

};



/* ****************************************************************************************
 * Class mcuf::util::MemoryChunk::LinkedList
 */  
class mcuf::util::MemoryChunk::LinkedList extends mcuf::lang::Object{
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
  private: LinkedList(void) = default;

  /**
   * Destruct.
   */
  public: virtual ~LinkedList(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  
  /**
   *
   */
  public: static Node* removeLink(Node* node);
  
  /**
   *
   */
  public: static Node* insert(Node** head, Node* node);
  
  /**
   *
   */
  public: static Node* remove(Node** head, Node* node);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

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

#endif/* MCUF_F48A5F39_DD99_4D2C_9E97_CC9E88B36DDF */
