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
using mcuf::util::VectorBlockPool;
using mcuf::lang::Math;
using mcuf::lang::Memory;
using mcuf::lang::managerment::MemoryManager;


/* ****************************************************************************************
 * Variable <Public>
 */
const uint16_t MemoryManager::BLOCK_SIZE[MCUF_MEMORY_MANAGERMENT_BLOCk_TYPE_QUANTITY] 
      = {MCUF_MEMORY_MANAGERMENT_BLOCk_TYPE, MCUF_MEMORY_MANAGERMENT_BASE_BLOCK_SIZE};

const uint16_t MemoryManager::NUMBER_OF_BLOCK_QUANTITY 
      = MCUF_MEMORY_MANAGERMENT_BLOCk_TYPE_QUANTITY;

const uint16_t MemoryManager::BASE_BLOCK_SIZE 
      = MCUF_MEMORY_MANAGERMENT_BASE_BLOCK_SIZE;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
MemoryManager::MemoryManager(mcuf::lang::Memory& memory){
  this->initEntityPool();
  this->initBlocks(memory);

  return;
}

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
  if(size > this->BASE_BLOCK_SIZE)
    return nullptr;

  return this->allocAuto(size).pointer();
}

/**
 * 
 */
Memory MemoryManager::allocMemory(size_t size){
  if(size > this->BASE_BLOCK_SIZE)
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
  uint16_t blockShift = this->foundBlockShift(size);

  for(int i=blockShift; i<this->NUMBER_OF_BLOCK_QUANTITY; ++i){
    if(blocks[i]->remove(pointer))
      return true;
  }

  for(int i=0; i<this->NUMBER_OF_BLOCK_QUANTITY; ++i){
    if(blocks[i]->remove(pointer))
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

/**
 * 
 */
bool MemoryManager::expansion(Memory& memory){
  return false;
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

  if(this->expansionBlock(this->foundBlockShift(size)))
    return this->allocDirect(size);

  else
    return this->allocCeil(size);
}

/**
 * 
 */
Memory MemoryManager::allocCeil(size_t size){
  int shift = this->foundBlockShift(size);
  if(shift == -1)
    return Memory::nullMemory();
  
  for(int i=shift; i<this->NUMBER_OF_BLOCK_QUANTITY; ++i){
    if(this->blocks[i] == nullptr)
      continue;
    
    if(this->blocks[i]->isFull())
      continue;

    return this->blocks[i]->allocMemory();
  }

  return Memory::nullMemory();
}

/**
 * 
 */
Memory MemoryManager::allocDirect(size_t size){
  int shift = this->foundBlockShift(size);
  if(shift == -1)
    return Memory::nullMemory();
    
  if(this->blocks[shift] == nullptr)
    return Memory::nullMemory();
    
  return this->blocks[shift]->allocMemory();
}

/**
 * 
 */
Memory MemoryManager::allocFloor(size_t size){
  int shift = this->foundBlockShift(size);
  if(shift == -1)
    return Memory::nullMemory();
  
  for(int i=shift; i>=0; --i){
    if(this->blocks[i] == nullptr)
      continue;
    
    if(this->blocks[i]->isFull())
      continue;

    return this->blocks[i]->allocMemory();
  }

  return Memory::nullMemory();
}

/**
 * 
 */
Memory MemoryManager::allocEntityBlockMemory(void){
  Memory result = this->entityPool->allocMemory();

  if(result.isEmpty())
    return result;

  if(!this->entityPool->isFull())
    return result;

  Memory memory = this->allocFloor(this->BASE_BLOCK_SIZE);
  size_t size = sizeof(VectorBlockPool);

  if(memory.isEmpty())
    return result;

  if(size > memory.length()){
    this->freeMemory(memory);
    return result;
  }
  
  /**
   * 
   */
  uint32_t bytes = Math::ceil((uint32_t)(memory.length() / size), 8UL);

  if(bytes & 0x00000003)
    bytes = (bytes & ~0x00000003) + 4;

  if(bytes > size){
    this->entityPool->addLinked(new(result.pointer()) VectorBlockPool(memory, size));
  }else{
    Memory flag = Memory::nullMemory();
    if((this->BASE_BLOCK_SIZE % size) < bytes)
      flag = this->allocCeil(bytes);


    if(flag.isEmpty())
      this->entityPool->addLinked(new(result.pointer()) VectorBlockPool(memory, size));

    else
      this->entityPool->addLinked(new(result.pointer()) VectorBlockPool(flag, memory, size));
  }
    
  return this->entityPool->allocMemory();
}

/**
 * 
 */
VectorBlockPool* MemoryManager::constructVectorBlockPool(Memory& memory, uint16_t blockShift){
  if(memory.isEmpty())
    return nullptr;

  if(blockShift >= this->NUMBER_OF_BLOCK_QUANTITY)
    return nullptr;

  size_t size = BLOCK_SIZE[blockShift];
  Memory base = this->allocEntityBlockMemory();

  if(base.isEmpty())
    return nullptr;

  Memory flag = Memory::nullMemory();

  uint32_t bytes = Math::ceil((uint32_t)(memory.length() / size), 8UL);

  if(bytes & 0x00000003)
    bytes = (bytes & ~0x00000003) + 4;

  if(bytes > size)
    return new(base.pointer()) VectorBlockPool(memory, size);

  if((this->BASE_BLOCK_SIZE % size) < bytes)
    flag = this->allocCeil(bytes);

  if(flag.isEmpty())
    return new(base.pointer()) VectorBlockPool(memory, size);

  else
    return new(base.pointer()) VectorBlockPool(flag, memory, size);
}

/**
 * 
 */
bool MemoryManager::expansionBlock(uint16_t blockShift){
  Memory memory = this->allocFloor(this->BASE_BLOCK_SIZE);
  if(memory.isEmpty())
    return false;

  if(this->BLOCK_SIZE[blockShift] >= memory.length()){
    this->freeMemory(memory);
    return false;
  }

  VectorBlockPool* result = this->constructVectorBlockPool(memory, blockShift);
  if(result == nullptr){
    this->freeMemory(memory);
    return false;
  }

  this->blocks[blockShift]->addLinked(result);
  return true;
}

/**
 * 
 */
int MemoryManager::foundBlockShift(size_t size){
  for(int i=0; i<this->NUMBER_OF_BLOCK_QUANTITY; i++){
    if(this->BLOCK_SIZE[i] >= size)
      return i;

  }

  return -1;
}

/**
 * 
 */
void MemoryManager::initBlocks(Memory& baseMemory){
  for(int i=0; i<this->NUMBER_OF_BLOCK_QUANTITY-1; i++){
    Memory memory = baseMemory.subMemory((this->BASE_BLOCK_SIZE * i), this->BASE_BLOCK_SIZE);
    this->blocks[i] = this->constructVectorBlockPool(memory, i);
  }

  int i = NUMBER_OF_BLOCK_QUANTITY-1;
  Memory memory = baseMemory.subMemory((this->BASE_BLOCK_SIZE * i));
  this->blocks[i] = this->constructVectorBlockPool(memory, i);
}

/**
 * 
 */
void MemoryManager::initEntityPool(void){
  Memory entityMemory = Memory(this->handleMemory.m, sizeof(this->handleMemory.m));
  Memory entityFlag = Memory(this->handleMemory.f, sizeof(this->handleMemory.f));
  this->entityPool = new(this->handleMemory.entity) VectorBlockPool(entityFlag, entityMemory, sizeof(VectorBlockPool));
}

/* ****************************************************************************************
 * End of file
 */ 
 