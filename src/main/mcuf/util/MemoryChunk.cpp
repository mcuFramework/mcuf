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
MemoryChunk::MemoryChunk(Memory& memory, uint16_t chunkSize) construct Memory(memory){
  if(chunkSize<8)
    chunkSize = 8;
  
  this->mChunkSize = (chunkSize+7)&0x07;
  this->reset();
}
  
/**
 * Construct.
 */
MemoryChunk::MemoryChunk(Memory&& memory, uint16_t chunkSize) construct MemoryChunk(memory, chunkSize){
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
  uint32_t numberOfChunk = (this->length() / (this->mChunkSize + 8));
  Node* head = reinterpret_cast<Node*>(this->pointer());
  *head = this->configNode(0, numberOfChunk, this->mChunkSize);
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
uint32_t MemoryChunk::getNodeSize(Node* node){
  uint16_t numberOfChunk = node->next & 0x7FFF;
  
  uint32_t result = ((uint32_t)this->mChunkSize * (uint32_t)numberOfChunk);
  result += (sizeof(Node) * (numberOfChunk-1));
  return result;
}

/**
 *
 */
uint32_t MemoryChunk::getPrevNodeSize(Node* node){
  uint16_t numberOfChunk = node->prev & 0x7FFF;
  
  uint32_t result = ((uint32_t)this->mChunkSize * (uint32_t)numberOfChunk);
  result += (sizeof(Node) * (numberOfChunk-1));
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
  *node = configNode(node->prev, split);
  
  /* get next node pointer */
  Node* next = this->getNextNode(node);
  
  /* config new node */
  *next = this->configNode(node->next, originNext - split);
  
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
  if(node->size != this->mChunkSize)
    return false;
  
  return (node->checksum == getNodeChecksum(node));
}

/**
 *
 */
MemoryChunk::Node MemoryChunk::configNode(uint16_t prev, uint16_t next){
  Node result;
  result.next = next;
  result.prev = prev;
  result.size = this->mChunkSize;
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
  result ^= node->size;
  return result;
}

/* ****************************************************************************************
 * End of file
 */ 
