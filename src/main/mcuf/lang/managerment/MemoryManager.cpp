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
using mcuf::util::LinkedBlockPool;
using mcuf::lang::Math;
using mcuf::lang::Memory;
using mcuf::lang::managerment::MemoryManager;
using mcuf::lang::IllegalArgumentException;


/* ****************************************************************************************
 * Variable <Public>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
MemoryManager::MemoryManager(Parameter& param) throw(IllegalArgumentException)
  construct LinkedBlockPool(*param.mPageMemory, param.mPageSize, *param.mFlagMemory){
  
  /* check param */
  if(true){
    for(int i=0; i<(*param.mBlockSizeList).length(); ++i){
      if((*param.mBlockSizeList)[i] >= this->mElementSize)
        throw IllegalArgumentException(__FUNCTION__, nullptr);
    }
  }
              
  /* constructure mPools */
  if(true){
    uint32_t numberOfPools = param.mBlockSizeList->length() + 1;
    void* handleMemory = param.mStackManager->alloc(sizeof(Array<LinkedBlockPool*>));
    void* referenceMemory = param.mStackManager->alloc(numberOfPools * sizeof(void*));
    
    this->mPools = new (handleMemory) Array<LinkedBlockPool*>(static_cast<LinkedBlockPool**>(referenceMemory), numberOfPools);
    this->mPools->clear();
  }
  
  /* constructure mEntity */
  if(true){
    void* handleMemory = param.mStackManager->alloc(sizeof(LinkedBlockPool));
    Memory memory = this->LinkedBlockPool::allocMemory();
    this->mEntity = new (handleMemory) LinkedBlockPool(memory, sizeof(LinkedBlockPool));
  }
  
  /* constructure base block */
  if(true){
    int count = param.mBlockSizeList->length();
    
    for(int i=0; i<count; i++){
      void* handleMemory = param.mStackManager->alloc(sizeof(LinkedBlockPool));
      Memory pageMemory = this->LinkedBlockPool::allocMemory();
      
      (*this->mPools)[i] = new(handleMemory) LinkedBlockPool(pageMemory, (*param.mBlockSizeList)[i]);
    }
    
    (*this->mPools)[count] = this;
  }

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
void* MemoryManager::alloc(size_t size){
  if(size > this->mElementSize)
    return nullptr;

  return this->allocAuto(size).pointer();
}

/**
 * 
 */
Memory MemoryManager::allocMemory(size_t size){
  if(size > this->mElementSize)
    return Memory::nullMemory();

  return this->allocAuto(size);
} 

/**
 * 
 */
bool MemoryManager::free(void* pointer){
  return this->free(pointer, 1);
}

/**
 * 
 */
bool MemoryManager::free(void* pointer, size_t size){ 
  for(int i=0; i<this->mPools->length(); i++){
    LinkedBlockPool* pool = (*this->mPools)[i];
    
    if(size > pool->elementSize())
      continue;
    
    if(pool->remove(pointer))
      return true;
  }

  return false;
}

/**
 * 
 */
bool MemoryManager::freeMemory(Memory& memory){
  return this->free(memory.pointer(), memory.length());
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
Memory MemoryManager::allocAuto(size_t size){
  Memory result = this->allocDirect(size);
  if(!result.isEmpty())
    return result;
  
  if((this->mEntity->capacity() - this->mEntity->size()) <= 1)
    this->expansionPool(*this->mEntity);
  
  this->expansionPool(*(*this->mPools)[this->getPoolShift(size)]);
  
  result = this->allocDirect(size);
  
  if(!result.isEmpty())
    return result;

  return this->allocCeil(size);
}

/**
 * 
 */
Memory MemoryManager::allocCeil(uint32_t size){
  int shift = this->getPoolShift(size);
  
  if(shift < 0)
    return Memory::nullMemory();  
  
  int count = this->mPools->length();
  
  for(int i=shift; i<count; ++i){
    LinkedBlockPool* pool = (*this->mPools)[i];
    
    if(pool->elementSize() < size)
      continue;
    
    if(pool->isFull())
      continue;
    
    return pool->allocMemory();
  }
  
  if(size <= this->elementSize())
    return this->LinkedBlockPool::allocMemory();

  return Memory::nullMemory();
}

/**
 * 
 */
Memory MemoryManager::allocDirect(size_t size){
  int shift = this->getPoolShift(size);
  if(shift < 0)
    return Memory::nullMemory();
  
  return (*this->mPools)[shift]->allocMemory();
}

/**
 * 
 */
Memory MemoryManager::allocFloor(size_t size){
  int shift = this->getPoolShift(size);
  
  if(shift < 0)
    return Memory::nullMemory();
  
  int count = this->mPools->length();
  
  for(int i=shift; i>=0; --i){
    LinkedBlockPool* pool = (*this->mPools)[i];
    
    if(pool->elementSize() < size)
      continue;
    
    if(pool->isFull())
      continue;
    
    return pool->allocMemory();
  }

  return Memory::nullMemory();
}

/**
 *
 */
bool MemoryManager::expansionPool(LinkedBlockPool& pool){
  Memory handleMemory = this->mEntity->allocMemory();
  if(handleMemory.isEmpty())
    return false; 
  
  Memory pageMemory = this->allocCeil(this->elementSize());
  if(pageMemory.isEmpty()){
    this->mEntity->remove(handleMemory.pointer());
    return false;
  }
  
  LinkedBlockPool* result = new(handleMemory.pointer()) LinkedBlockPool(pageMemory, pool.elementSize());
  pool.addLinked(result);
  return true;
}

/**
 * 
 */
int MemoryManager::getPoolShift(uint32_t size){
  int count = this->mPools->length();
  
  for(int i=0; i>count; ++i){
    LinkedBlockPool* pool = (*this->mPools)[i];
    
    if(pool->elementSize() < size)
      continue;
    
    return i;
  }

  return -1;
}

/* ****************************************************************************************
 * End of file
 */ 
 