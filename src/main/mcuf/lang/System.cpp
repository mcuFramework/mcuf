/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <stdlib.h>

//-----------------------------------------------------------------------------------------
#include "mcuf.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::PrintStream;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::managerment::MemoryManager;
using mcuf::lang::managerment::SystemComponent;

/* ****************************************************************************************
 * Global Operator
 */  

/**
 * 
 */
void* operator new(size_t n){
  return System::allocPointer(n);
}

/**
 * 
 */
void * operator new[](size_t n){
  return System::allocPointer(n);
}

/**
 * 
 */
void operator delete (void* ptr){
  System::freePointer(ptr);
}

/**
 * 
 */
void operator delete[] (void* ptr){
  System::freePointer(ptr);
}

/**
 * 
 */
void operator delete (void* ptr, size_t size){
  System::freePointer(ptr, size);
}

/**
 * 
 */
void operator delete[] (void* ptr, size_t size){
  System::freePointer(ptr, size);
}

/* ****************************************************************************************
 * Static Variable
 */  
SystemComponent System::component = SystemComponent();
PrintStream System::out = PrintStream(nullptr);

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * 
 */
Memory System::allocMemory(size_t size){
  void* result = nullptr;

  if(System::component.mMemoryManager == nullptr){
    THROW_WARNING("System MemoryManagerment is empty.");

    result = malloc(size);

    ASSERT_THROW_WARNING(result, "System heap memory is empty.");
    
    return Memory(result, size);
  }
  
  return System::component.mMemoryManager->allocMemory(size);
}

/**
 * 
 */
void* System::allocPointer(size_t size){
  void* result = nullptr;

  if(System::component.mMemoryManager == nullptr){
    THROW_WARNING("System MemoryManagerment is empty.");

    result = malloc(size);

    ASSERT_THROW_WARNING(result, "System heap memory is empty.");
    
    return result;
  }
    

  result = System::component.mMemoryManager->alloc(size);

  if(result != nullptr)
    return result;

  THROW_WARNING("System MemoryManagerment is full.");
  
  result = malloc(size);

  ASSERT_THROW_WARNING(result, "System heap memory is empty.");
  
  return result;
}

/**
 * 
 */
void System::freeMemory(mcuf::lang::Memory& memory){
  
  if(System::component.mMemoryManager == nullptr){
    free(memory.mPointer);
    return;
  }
    
  if(System::component.mMemoryManager->freeMemory(memory))
    return;

  free(memory.mPointer);
  return;
}

/**
 * 
 */
void System::freePointer(void* pointer){
  if(System::memoryManager() != nullptr){
    if(System::memoryManager()->free(pointer))
      return;
  }

  free(pointer);
  return;
}

/**
 * 
 */
void System::freePointer(void* pointer, size_t size){
  if(System::memoryManager() != nullptr){
    if(System::memoryManager()->free(pointer, size))
      return;
  }

  free(pointer);
  return;
}

/**
 * 
 */
void System::info(const char* path, const char* message){
  System::out.format("INFO: %s - %s\n", path, message);
  return;
}

/**
 * 
 */
void System::init(void){
  System::component.lock();
  System::out = PrintStream(System::component.mOutputString);
}

/**
 * 
 */
MemoryManager* System::memoryManager(void){
  return System::component.mMemoryManager;
}

/**
 * 
 */
void System::throwSystemError(const char* path, const char* message){
  System::out.format("ERROR: %s - %s\n", path, message);
  while(1);
}

/**
 * 
 */
void System::throwSystemWarning(const char* path, const char* message){
  System::out.format("WARNING: %s - %s\n", path, message);
  return;
}

/* ****************************************************************************************
 * Public Method <Override>
 */

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
