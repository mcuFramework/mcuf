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
  uint32_t numberOfChunk = (this->length() / (this->mChunkSize + sizeof(Node)));
  
  if(numberOfChunk > 0x00007FFF)
    numberOfChunk = 0x00007FFF;
  
  Node* head = this->getNode(0);
  
  *head = this->configNode(0, numberOfChunk, 0);
  
  this->mFreeHead = 0x0000;
  
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
MemoryChunk::Node* MemoryChunk::getNode(Node* node, int16_t shift){
  int32_t offset = (this->mChunkSize + sizeof(Node)) * shift;
  uint32_t addrSre = reinterpret_cast<uint32_t>(node) + offset;
  return reinterpret_cast<Node*>(addrSre);
}

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getNode(uint16_t chunk){
  return this->getNode(static_cast<Node*>(this->mPointer), chunk);
}

/**
 *
 */
uint32_t MemoryChunk::getNodeSize(Node* node){
  uint16_t numberOfChunk = node->next & 0x7FFF;
  
  uint32_t result = ((uint32_t)(this->mChunkSize + sizeof(Node)) * (uint32_t)numberOfChunk);
  result -= sizeof(Node);

  return result;
}

/**
 *
 */
uint32_t MemoryChunk::getPrevNodeSize(Node* node){
  uint16_t numberOfChunk = node->prev & 0x7FFF;
  
  uint32_t result = ((uint32_t)(this->mChunkSize + sizeof(Node)) * (uint32_t)numberOfChunk);
  result -= sizeof(Node);
  return result;
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
MemoryChunk::Node* MemoryChunk::getNextNode(Node* node){
  uint8_t* ptr = reinterpret_cast<uint8_t*>(node);
  ptr += this->getNodeSize(node);
  
  return reinterpret_cast<Node*>(ptr);
}

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getPrevNode(Node* node){
  uint8_t* ptr = reinterpret_cast<uint8_t*>(node);
  ptr -= this->getPrevNodeSize(node);
  
  return reinterpret_cast<Node*>(ptr);
}

/**
 *
 */
MemoryChunk::Node* MemoryChunk::getFastNode(Node* node){
  uint8_t* ptr = reinterpret_cast<uint8_t*>(node);
  ptr += this->getNodeSize(node);
  
  return reinterpret_cast<Node*>(ptr);
}

/**
 * Split new node. 
 *
 * @param node - node pointer.
 * @param split - number of chunk.
 * @return true successful, false fail.
 */
bool MemoryChunk::splitNode(Node* node, uint16_t split){
  if(split == 0)
    return false;
  
  if(!this->veriftNode(node)) /* verify node checksum */
    return false; /* verify fail */
  
  if(this->getNodeStatus(node)) /* check node is useing or not */
    return false; /* node is using */
  
  if(split >= node->next) /* check spile size more than the node size */
    return false; /* check fail */
  
  /* recode origin node size */
  uint16_t originNext = node->next;
  
  /* config node new next size */
  *node = configNode(node->prev, split, 0);
  
  /* get next node pointer */
  Node* next = this->getNextNode(node);
  
  /* config new node */
  *next = this->configNode(node->next, originNext - split, 0);
  
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
  return (node->checksum == getNodeChecksum(node));
}

/**
 *
 */
MemoryChunk::Node MemoryChunk::configNode(uint16_t prev, uint16_t next, uint16_t fast){
  Node result;
  result.next = next;
  result.prev = prev;
  result.fast = fast;
  result.checksum = this->getNodeChecksum(&result);
  return result;
}

/**
 *
 */
uint16_t MemoryChunk::getNodeChecksum(Node* node){
  uint16_t result = 0x0000;
  result ^= node->next;
  result ^= node->prev;
  result ^= node->fast;
  return result;
}

/* ****************************************************************************************
 * End of file
 */ 
