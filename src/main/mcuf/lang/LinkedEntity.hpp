/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AE54A221_DC19_452D_9BEB_00BF5CA639E4
#define MCUF_AE54A221_DC19_452D_9BEB_00BF5CA639E4

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/lang/Object.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class LinkedEntity;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::lang::LinkedEntity extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: void* mBase;
  protected: LinkedEntity* mNext;

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  public: LinkedEntity(void* base);

  /**
   * Disconstruct.
   */
  public: virtual ~LinkedEntity(void) = default;

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
  public: void* get(void);

  /**
   * 
   */
  public: void add(LinkedEntity* LinkedEntity);

  /**
   * 
   */
  public: void insert(LinkedEntity* LinkedEntity);

  /**
   * 
   */
  public: LinkedEntity* next(void);

  /**
   * 
   */
  public: bool hasNext(void);

  /**
   * 
   */
  public: LinkedEntity* remove(void);

  /**
   * 
   */
  public: LinkedEntity* removeAll(void);  

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

#endif/* MCUF_AE54A221_DC19_452D_9BEB_00BF5CA639E4 */