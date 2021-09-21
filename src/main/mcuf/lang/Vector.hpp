/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F289C704_EAEA_4650_BD9A_A332BBFC783C
#define MCUF_F289C704_EAEA_4650_BD9A_A332BBFC783C

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    template<typename E> class Vector;
  }
}



/* ****************************************************************************************
 * Class Object
 */  
template<typename E>
class mcuf::lang::Vector extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: Vector<E>* nextVector = nullptr;

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /**
   * 
   */
  public: virtual E* getBase(void) = 0;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  public: Vector(void){
    this->nextVector = nullptr;
    return;
  }

  /**
   * Disconstruct.
   */
  public: virtual ~Vector(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: void vectorAdd(Vector<E>* vector){
    if(this->hasNextVector())
      this->nextVector->vectorAdd(vector);
    
    else
      this->nextVector = vector;
  }

  /**
   * 
   */
  public: void vectorInsert(Vector<E>* vector){
    vector->nextVector = this->nextVector;
    this->nextVector = vector;
  }

  /**
   * 
   */
  public: Vector<E>* getNextVector(void){
    return this->nextVector;
  }

  /**
   * 
   */
  public: bool hasNextVector(void){
    return (this->nextVector != nullptr);
  }

  /**
   * 
   */
  public: Vector<E>* vectorRemove(void){
    if(!this->hasNextVector())
      return nullptr;
    
    Vector<E>* result = nextVector;
    this->nextVector = result->nextVector;
    return result;
  }


  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};



/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_F289C704_EAEA_4650_BD9A_A332BBFC783C */
