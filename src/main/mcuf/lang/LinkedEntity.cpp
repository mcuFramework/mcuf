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
#include "mcuf/lang/LinkedEntity.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::LinkedEntity;

/* ****************************************************************************************
 * Macro
 */
 
/* ****************************************************************************************
 * Variable
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
LinkedEntity::LinkedEntity(void* base){
  this->mBase = base;
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
void* LinkedEntity::get(void){
  return this->mBase;
}

/**
 * 
 */
void LinkedEntity::add(LinkedEntity* LinkedEntity){
  if(this->hasNext())
    this->mNext->add(LinkedEntity);

  else
    this->mNext = LinkedEntity;
}

/**
 * 
 */
void LinkedEntity::insert(LinkedEntity* LinkedEntity){
  if(this->hasNext())
    LinkedEntity->add(this->mNext);
  
  this->mNext = LinkedEntity;
  return;
}

/**
 * 
 */
LinkedEntity* LinkedEntity::next(void){
  return this->mNext;
}

/**
 * 
 */
bool LinkedEntity::hasNext(void){
  return (this->mNext != nullptr);
}

/**
 * 
 */
LinkedEntity* LinkedEntity::remove(void){
  if(!this->hasNext())
    return nullptr;
  
  LinkedEntity* result = this->mNext;
  this->mNext = result->mNext;
  return result;
}

/**
 * 
 */
LinkedEntity* LinkedEntity::removeAll(void){
  LinkedEntity* result = this->mNext;
  this->mNext = nullptr;
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
 * Private Method <Static>
 */
 
/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
