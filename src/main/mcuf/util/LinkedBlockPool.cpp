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
#include "mcuf/util/LinkedBlockPool.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::lang::Linked;
using mcuf::lang::LinkedEntity;
using mcuf::util::LinkedBlockPool;
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
LinkedBlockPool::LinkedBlockPool(uint32_t pageSize, uint32_t elementSize) construct
                 BlockPool(pageSize, elementSize),
                 mLinkedEntity(this){
  
  return;
}
/**
 * 
 */

LinkedBlockPool::LinkedBlockPool(Memory& page, uint32_t elementSize, Memory& flag) construct
                 BlockPool(page, elementSize, flag),
                 mLinkedEntity(this){
  
  return;
}

/**
 * 
 */
LinkedBlockPool::LinkedBlockPool(Memory& page, uint32_t elementSize) construct
                 BlockPool(page, elementSize),
                 mLinkedEntity(this){
  
  return;
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Linked<LinkedBlockPool>
 */

/**
 * 
 */
bool LinkedBlockPool::addLinked(LinkedBlockPool* e){
  if(e->mElementSize != this->mElementSize)
    return false;
  
  this->mLinkedEntity.add(&e->mLinkedEntity);
  return true;
}

/**
 * 
 */
bool LinkedBlockPool::insertLinked(LinkedBlockPool* e){
  if(e->mElementSize != this->mElementSize)
    return false;  
  
  this->mLinkedEntity.insert(&e->mLinkedEntity);
  return true;
}

/**
 *
 */
LinkedBlockPool* LinkedBlockPool::getNextLinked(void){
  return static_cast<LinkedBlockPool*>(this->mLinkedEntity.get());
}

/**
 * 
 */
bool LinkedBlockPool::hasNextLinked(void){
  return this->mLinkedEntity.hasNext();
}

/**
 * 
 */
LinkedBlockPool* LinkedBlockPool::removeLinked(void){
  LinkedEntity* linkedEntity = this->mLinkedEntity.remove();
  if(linkedEntity == nullptr)
    return nullptr;
  
  return static_cast<LinkedBlockPool*>(linkedEntity->get());
}

/**
 * 
 */
LinkedBlockPool* LinkedBlockPool::removeAllLinked(void){
  LinkedEntity* linkedEntity = this->mLinkedEntity.removeAll();
  if(linkedEntity == nullptr)
    return nullptr;
  
  return static_cast<LinkedBlockPool*>(linkedEntity->get());
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::BlockPool
 */

/**
 * 
 */
void* LinkedBlockPool::add(void* element){
  void* result = BlockPool::add(element);
  
  if((result == nullptr) && (this->hasNextLinked()))
    return this->getNextLinked()->add(element);
  
  return result;
}

/**
 * 
 */
void* LinkedBlockPool::alloc(void){
  void* result = BlockPool::alloc();
  
  if((result == nullptr) && (this->hasNextLinked()))
    return this->getNextLinked()->alloc();

  return result;
}

/**
 * 
 */
Memory LinkedBlockPool::allocMemory(void){
  Memory result = BlockPool::allocMemory();
  
  if(result.isEmpty() && (this->hasNextLinked()))
    return this->getNextLinked()->allocMemory();

  return result;
}

/**
 * 
 */
uint32_t LinkedBlockPool::capacity(void){
  uint32_t result = BlockPool::mCapacity;
  
  if(this->hasNextLinked())
    result += this->getNextLinked()->capacity();

  return result;
}

/**
 * 
 */
void LinkedBlockPool::clear(void){
  BlockPool::clear();
  if(this->hasNextLinked())
    this->getNextLinked()->clear();
  
  return;
}

/**
 * 
 */
void LinkedBlockPool::forEach(Consumer<Memory*>& consumer){
  BlockPool::forEach(consumer);
  
  if(this->hasNextLinked())
    this->getNextLinked()->forEach(consumer);
  
  return;
}

/**
 * 
 */
bool LinkedBlockPool::isEmpty(void){
  bool result = BlockPool::isEmpty();
  
  if(this->hasNextLinked())
    result &= this->getNextLinked()->isEmpty();
  
  return result;
}

/**
 * 
 */
bool LinkedBlockPool::isFull(void){
  bool result = BlockPool::isFull();
  
  if(this->hasNextLinked())
    result &= this->getNextLinked()->isFull();
  
  return result;
}

/**
 * 
 */
uint32_t LinkedBlockPool::size(void){
  uint32_t result = BlockPool::mSize;
  
  if(this->hasNextLinked())
    result += this->getNextLinked()->size();
  
  return result;
}

/**
 * 
 */
bool LinkedBlockPool::remove(void* element){
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
