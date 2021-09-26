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
#include "mcuf.h"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::lang::Linked;
using mcuf::lang::LinkedEntity;
using mcuf::util::VectorBlockPool;
using mcuf::function::Consumer;
 
/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
VectorBlockPool::VectorBlockPool(void* flag, void* pointer, uint32_t elementSize, uint32_t capacity) :
                 BlockPool(flag, pointer, elementSize, capacity),
                 mLinkedEntity(this){
  
  return;
}
/**
 * 
 */

VectorBlockPool::VectorBlockPool(Memory flags, Memory memory, uint32_t elementSize) : 
                 BlockPool(flags, memory, elementSize),
                 mLinkedEntity(this){
  
  return;
}

/**
 * 
 */
VectorBlockPool::VectorBlockPool(Memory memory, uint32_t elementSize) :
                 BlockPool(memory, elementSize),
                 mLinkedEntity(this){
  
  return;
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Linked<VectorBlockPool>
 */

/**
 * 
 */
void VectorBlockPool::addLinked(VectorBlockPool* e){
  this->mLinkedEntity.add(&e->mLinkedEntity);
  return;
}

/**
 * 
 */
void VectorBlockPool::insertLinked(VectorBlockPool* e){
  this->mLinkedEntity.insert(&e->mLinkedEntity);
  return;
}

/**
 *
 */
VectorBlockPool* VectorBlockPool::getNextLinked(void){
  return static_cast<VectorBlockPool*>(this->mLinkedEntity.get());
}

/**
 * 
 */
bool VectorBlockPool::hasNextLinked(void){
  return this->mLinkedEntity.hasNext();
}

/**
 * 
 */
VectorBlockPool* VectorBlockPool::removeLinked(void){
  LinkedEntity* linkedEntity = this->mLinkedEntity.remove();
  if(linkedEntity == nullptr)
    return nullptr;
  
  return static_cast<VectorBlockPool*>(linkedEntity->get());
}

/**
 * 
 */
VectorBlockPool* VectorBlockPool::removeAllLinked(void){
  LinkedEntity* linkedEntity = this->mLinkedEntity.removeAll();
  if(linkedEntity == nullptr)
    return nullptr;
  
  return static_cast<VectorBlockPool*>(linkedEntity->get());
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::BlockPool
 */

/**
 * 
 */
void* VectorBlockPool::add(void* element){
  void* result = BlockPool::add(element);
  
  if((result == nullptr) && (this->hasNextLinked()))
    return this->getNextLinked()->add(element);
  
  return result;
}

/**
 * 
 */
void* VectorBlockPool::alloc(void){
  void* result = BlockPool::alloc();
  
  if((result == nullptr) && (this->hasNextLinked()))
    return this->getNextLinked()->alloc();

  return result;
}

/**
 * 
 */
Memory VectorBlockPool::allocMemory(void){
  Memory result = BlockPool::allocMemory();
  
  if(result.isEmpty() && (this->hasNextLinked()))
    return this->getNextLinked()->allocMemory();

  return result;
}

/**
 * 
 */
uint32_t VectorBlockPool::capacity(void){
  uint32_t result = BlockPool::mCapacity;
  
  if(this->hasNextLinked())
    result += this->getNextLinked()->capacity();

  return result;
}

/**
 * 
 */
void VectorBlockPool::clear(void){
  BlockPool::clear();
  if(this->hasNextLinked())
    this->getNextLinked()->clear();
  
  return;
}

/**
 * 
 */
void VectorBlockPool::forEach(Consumer<Memory&>& consumer){
  BlockPool::forEach(consumer);
  
  if(this->hasNextLinked())
    this->getNextLinked()->forEach(consumer);
  
  return;
}

/**
 * 
 */
bool VectorBlockPool::isEmpty(void){
  bool result = BlockPool::isEmpty();
  
  if(this->hasNextLinked())
    result &= this->getNextLinked()->isEmpty();
  
  return result;
}

/**
 * 
 */
bool VectorBlockPool::isFull(void){
  bool result = BlockPool::isFull();
  
  if(this->hasNextLinked())
    result &= this->getNextLinked()->isFull();
  
  return result;
}

/**
 * 
 */
uint32_t VectorBlockPool::size(void){
  uint32_t result = BlockPool::mSize;
  
  if(this->hasNextLinked())
    result += this->getNextLinked()->size();
  
  return result;
}

/**
 * 
 */
bool VectorBlockPool::remove(void* element){
  bool result = BlockPool::remove(element);
  
  if((result == false) && (this->hasNextLinked()))
    result |= this->getNextLinked()->remove(element);

  return result;
}

/* ****************************************************************************************
 * Public Method
 */

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
 
/* ****************************************************************************************
 * End of file
 */ 
