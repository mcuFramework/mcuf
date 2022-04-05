/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf/util/MemoryPool.h"
#include "mcuf/lang/System.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::util::MemoryPool;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::ErrorCode;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Memory Pool:: Memory Pool object
 * 
 * @param memory 
 * @param max 
 * @param min 
 */
MemoryPool::MemoryPool(Memory& memory, uint32_t max, uint32_t min) construct Memory(memory){
  
  this->mMax = this->valuePowerful(max);
  this->mMin = this->valuePowerful(min);
  
  if(this->mMax < 32)
    this->mMax = 32;
  
  if(this->mMin < 16)
    this->mMin = 16;
  
  if(this->mMin > this->mMax)
    this->mMin = this->mMax;
    
  this->clear();
}

/**
 * @brief Destroy the Memory Pool:: Memory Pool object
 * 
 */
MemoryPool::~MemoryPool(void){
  this->clear();
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Allocator
 */

/**
 * @brief 
 * 
 * @param size 
 */
void* MemoryPool::alloc(uint32_t size){
  if(this->mFreeNode == nullptr)
    return nullptr;
  
  Node* node = this->mFreeNode;
  
  return nullptr;
}

/**
 * @brief 
 * 
 * @param ptr 
 * @return true 
 * @return false 
 */
bool MemoryPool::free(void* ptr){
  Node* node = static_cast<Node*>(Pointer::pointShift(ptr, -sizeof(Node)));
  
  if(!this->verifyNode(node))
    return false;
  
  this->markFree(node);
  this->merge(node);
  
  return true;
}

/**
 * @brief 
 * 
 * @param ptr 
 * @param size 
 * @return true 
 * @return false 
 */
bool MemoryPool::free(void* ptr, uint32_t size){
  return this->free(ptr);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Memory
 */

/**
 * @brief 
 * 
 */
void MemoryPool::clear(void){
  if(this->isReadOnly())
    mcuf::lang::System::error(this, ErrorCode::WRITE_TO_READONLY_MEMORY);

  uint32_t size = (this->length() & (this->mMin - 1));
  
  this->mNode = reinterpret_cast<Node*>(this->pointer());
  Node* tail = reinterpret_cast<Node*>(this->pointer(size - sizeof(Node)));
  
  this->mNode->linkPrev = this->mNode;
  this->mNode->linkNext = this->mNode;
  this->mNode->prev = this->mNode;
  this->mNode->next = tail;
  
  tail->linkPrev = nullptr;
  tail->linkNext = nullptr;
  tail->prev = this->mNode;
  tail->next = tail;
  
  this->mFreeNode = this->mNode;
}

/**
 * @brief 
 * 
 * @param value 
 */
void MemoryPool::clear(uint8_t value){
  this->clear();
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief Get the Free Size object
 * 
 * @return uint32_t 
 */
uint32_t MemoryPool::getFreeSize(void){
  if(this->mFreeNode == nullptr)
    return 0;
  
  uint32_t result = 0;
  
  Node* node = this->mFreeNode;
  while(true){
    result += (this->getNodeSize(node) - sizeof(Node));
    
    if(node->linkNext == this->mFreeNode)
      break;
    
    node = node->linkNext;
  }
  
  return result;
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
MemoryPool::Node* MemoryPool::split(Node* node, uint32_t size){
  if(!this->isNodeFree(node))
    return nullptr;
  
  uint32_t nodeSize = this->getNodeSize(node);
  size = this->sizePowerful(size + sizeof(Node));

  if((size + this->mMin) > nodeSize)  //not enough free space
      return nullptr;

  nodeSize = nodeSize - size;
  
  Node* next = node->next;
  Node* linkNext = node->linkNext;
  Node* result = static_cast<Node*>(Pointer::pointShift(node, nodeSize));
  
  result->next = next;
  result->prev = node;
  result->linkNext = linkNext;
  result->linkPrev = node;
  
  next->prev = result;
  
  linkNext->linkPrev = result;
  
  node->next = result;
  node->linkNext = result;
  
  return result;
}

/**
 *
 */
bool MemoryPool::merge(Node* node){
  if(node == nullptr)
    return false;
  
  if(!this->isNodeFree(node))
    return false;
  
  if(!this->isNodeFree(node->next))
    return false;
  
  Node* next = node->next;
  
  node->next = next->next;
  node->next->prev = node;
  node->linkNext = next->linkNext;
  node->linkNext->linkPrev = node;
  
  return true;
}

/**
 *
 */
bool MemoryPool::isNodeFree(Node* node){
  return ((node->linkNext != nullptr) || (node->linkPrev != nullptr));
}

/**
 *
 */
bool MemoryPool::markUsing(Node* node){
  if(!this->isNodeFree(node))
    return false;

  Node* linkNext = node->linkNext;
  Node* linkPrev = node->linkPrev;
  
  linkNext->linkPrev = linkPrev;
  linkPrev->linkNext = linkNext;
  
  node->linkNext = nullptr;
  node->linkPrev = nullptr;
  
  if(node == this->mFreeNode){
    if(node == linkNext)
      this->mFreeNode = nullptr;
    
    else
      this->mFreeNode = linkNext;
  }
    
  return true;
}

/**
 *
 */
bool MemoryPool::markFree(Node* node){
  if(this->isNodeFree(node))
    return false;
  
  Node* temp;
  
  //try to find prev free node
  temp = node->prev;
  while(true){
    
    //if found free node, mark and break while
    if(this->isNodeFree(temp)){
      node->linkPrev = temp;
      temp->linkNext = temp;
      break;
    }
    
    //free node not found. mark self.
    if(temp == temp->prev){
      node->linkPrev = node;
      break;
    }
    
    //prev
    temp = temp->prev;
  }
  
  //try to find next free node
  temp = node->next;
  while(true){
    
    //if found free node, mark and break while
    if(this->isNodeFree(temp)){
      node->linkNext = temp;
      temp->linkPrev = temp;
      break;
    }
    
    //free node not found. mark self.
    if(temp == temp->next){
      node->linkNext = node;
      break;
    }
    
    //next
    temp = temp->next;
  }
  
  //check freeNode
  if(this->mFreeNode == nullptr)
    this->mFreeNode = node;
  
  //compair node address
  else if(node > this->mFreeNode)
    this->mFreeNode = node;
    
  return true;
}

/**
 *
 */
uint32_t MemoryPool::getNodeSize(Node* node){
  if(node->next == nullptr)
    return 0;
  
  uint32_t head = reinterpret_cast<uint32_t>(node);
  uint32_t tail = reinterpret_cast<uint32_t>(node->next);
  return tail - head;
}

/**
 *
 */
uint32_t MemoryPool::sizePowerful(uint32_t size){
  if(size < this->mMin)
    return this->mMax;
  
  if(size <= this->mMax)
    return this->valuePowerful(size);
  
  if(size & (1-this->mMax))
    return size;
  
  size &= (1-this->mMax);
  size += this->mMax;
  return size;
}

/**
 *
 */
uint32_t MemoryPool::valuePowerful(uint32_t value){
  uint32_t mask = 0x80000000;
  for(int i=0; i<32; ++i){
    if(value & mask){
    	if(value & ~mask)
    		return mask << 1;
    		
    	else
    		return mask;
	}
          
    mask = (mask >> 1);
  }
  
  return 0;	
}

/**
 *
 */
bool MemoryPool::verifyNode(Node* node){
  if(!this->inRange(node))
    return false;
  
  if(node->next->prev != node)
    return false;
  
  if(node->prev->next != node)
    return false;
  
  return true;
}

/* ****************************************************************************************
 * End of file
 */
