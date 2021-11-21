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
  *head = this->configNode(0, numberOfChunk, this->mChunkSize, 0);
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
bool MemoryChunk::veriftNode(Node* node){
  return (node->checksum == getNodeChecksum(node));
}

/**
 *
 */
MemoryChunk::Node MemoryChunk::configNode(uint16_t prev, uint16_t next, uint16_t size, uint8_t config){
  Node result;
  result.next = next;
  result.prev = prev;
  result.size = size;
  result.config = config;
  result.checksum = this->getNodeChecksum(&result);
  return result;
}

/**
 *
 */
uint8_t MemoryChunk::getNodeChecksum(Node* node){
  uint8_t* ptr = reinterpret_cast<uint8_t*>(node);
  uint8_t result = 0x00;
  
  for(uint8_t i=0; i<7; ++i)
    result ^= ptr[i];
  
  return result;
}

/* ****************************************************************************************
 * End of file
 */ 
