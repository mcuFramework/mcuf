/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/util/MemoryChunk.hpp"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::util::MemoryChunk;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * Construct.
 */
MemoryChunk::MemoryChunk(Memory& memory, uint32_t chunkSize) construct Memory(memory){
  if(chunkSize<8)
    chunkSize = 8;
  
  this->mChunkSize = (chunkSize+7)&0x07;
  this->mChunkQuantity = (this->length() / (this->mChunkSize + sizeof(Node)));
  if(this->mChunkQuantity > 0x7FFF)
    this->mChunkQuantity = 0x7FFF;
  
  this->reset();
}
  
/**
 * Construct.
 */
MemoryChunk::MemoryChunk(Memory&& memory, uint32_t chunkSize) construct MemoryChunk(memory, chunkSize){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 *
 */
void MemoryChunk::reset(void){
  Node* node = this->getNode(0);
  
  node->prev = 0;
  node->next = this->mChunkQuantity;
  node->nextLink = 0xFFFF;
  node->prevLink = 0xFFFF;
  
  this->mAvailableNodeLink = node;
  this->mUsingNodeLink = nullptr;
  
  return;
}

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getNode(uint16_t chunk){
  if(chunk == 0xFFFF) 
    return nullptr;
  
  chunk &= 0x7FFF;
  uint32_t shift = this->getChunkWithNodeSize() * chunk;
  Node* result = static_cast<Node*>(this->pointer(shift));
  return result;
}

/**
 *
 */
uint16_t MemoryChunk::getNodeSerialNumber(Node* node){
  if(!this->inRange(node))
    return 0xFFFF;
  
  uint32_t start = reinterpret_cast<uint32_t>(this->pointer());
  uint32_t delta = start - reinterpret_cast<uint32_t>(node);
  
  return (delta / this->getChunkWithNodeSize());
}

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getNextNode(Node* node){
  uint16_t shift = (node->next & 0x7FFF);
  uint32_t result = reinterpret_cast<uint32_t>(node);
  result += (this->getChunkWithNodeSize() * shift);
  
  return reinterpret_cast<Node*>(result);
}

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getNextLinkNode(Node* node){
  return this->getNode(node->nextLink);
}

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getPrevNode(Node* node){
  uint16_t shift = (node->next & 0x7FFF);
  uint32_t result = reinterpret_cast<uint32_t>(node);
  result -= (this->getChunkWithNodeSize() * shift);
  
  return reinterpret_cast<Node*>(result);
}

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getPrevLinkNode(Node* node){
  return this->getNode(node->prevLink);
}

/** 
 *
 */
bool MemoryChunk::getNodeStatus(Node* node){
  return (node->next & 0x8000);
}

/**
 *
 */
bool MemoryChunk::setNodeUsing(Node* node){
  if(this->getNodeStatus(node))
    return false;
  
  node->next |= 0x8000;
  this->removeNodeLink(node);
  
  if(this->mUsingNodeLink == nullptr)
    this->mUsingNodeLink = node;

  return true;  
}

/**
 *
 */
bool MemoryChunk::setNodeAvailable(Node* node){
  if(!this->getNodeStatus(node))
    return false;
  
  node->next &= 0x7FFF;
  this->removeNodeLink(node);
  
  return true; 
}

/**
 * Split new node. 
 *
 * @param node - node pointer.
 * @param split - number of chunk.
 * @return true successful, false fail.
 */
bool MemoryChunk::splitNode(Node* node, uint16_t split){
  return true;
}

/**
 *
 */
bool MemoryChunk::mergeNode(Node* node){
  return false;
}

/**
 *
 */
bool MemoryChunk::veriftNode(Node* node){
  if(node->next){
    Node* nextNode = this->getNextNode(node);
    if(node->next != nextNode->prev)
      return false;
  }
  
  if(node->prev){
    Node* prevNode = this->getPrevNode(node);
    if(node->prev != prevNode->prev)
      return false;
  }
  
  return true;
}

/**
 *
 */
uint32_t MemoryChunk::getChunkWithNodeSize(void){
  return (sizeof(Node) + this->mChunkSize);
}

/**
 *
 */
void MemoryChunk::removeNodeLink(Node* node){
  if((node->nextLink == 0xFFFF) && (node->prevLink == 0xFFFF))
    return;
  
  Node* prevNode = this->getPrevLinkNode(node);
  Node* nextNode = this->getNextLinkNode(node);
  
  if(prevNode != nullptr)
    prevNode->nextLink = node->nextLink;
  
  if(nextNode != nullptr)
    nextNode->prevLink = node->prevLink;
  
  node->nextLink = 0xFFFF;
  node->prevLink = 0xFFFF;
  

  return;
}

/**
 *
 */
void MemoryChunk::nodeLinkInsert(Node* linkedNode, Node* node){
  Node* nextNode = this->getNextLinkNode(linkedNode);
  
  /* config node nextLink link to linkedNode */
  node->nextLink = linkedNode->nextLink;
  
  /* config node nextLink link to nextNode */
  if(nextNode != nullptr)
    node->prevLink = nextNode->prevLink;
  else
    node->prevLink = this->getNodeSerialNumber(linkedNode);
  
  /* config linkedNode nextLink link to node */
  linkedNode->nextLink = this->getNodeSerialNumber(node);
  
  /* config nextNode nextLink link to node <if exist> */
  if(nextNode != nullptr)
    nextNode->prevLink = linkedNode->nextLink;
  
  return;
}

/* ****************************************************************************************
 * Private Method - LinkedList
 */

/**
 *
 */
bool MemoryChunk::LinkedList::insert(Node** head, Node* node){
  if(!LinkedList::isFree(node))
    return false;
  
  if(node == nullptr)
    return false;
  
  if(*head == nullptr){
    *head = node;
  }else{

  
  }
  
  return true;
}

/* ****************************************************************************************
 * End of file
 */ 
