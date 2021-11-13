/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_FCCC3E6F_E524_4464_BA6F_FF9492970DA8
#define MCUF_FCCC3E6F_E524_4464_BA6F_FF9492970DA8

/* ****************************************************************************************
 * Include
 */

#include "mcuf_base.h"
#include "mcuf\lang\ArrayPrototype.hpp"
#include "mcuf\lang\Memory.hpp"
#include "mcuf\lang\Pointer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    template<typename E> class Array;
  }
}



/* ****************************************************************************************
 * Class Array
 */  
template<typename E>
class mcuf::lang::Array extends mcuf::lang::ArrayPrototype{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

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
   *
   */
  public: Array(mcuf::lang::Memory& memory) construct mcuf::lang::ArrayPrototype(memory, sizeof(E)){
    return;
  }

  /**
   * Construct.
   */
  public: Array(E* e, uint32_t length) construct mcuf::lang::ArrayPrototype(e, length * sizeof(E), sizeof(E)){
    return;
  }
  
  /**
   * Construct.
   */
  public: Array(const E* e, uint32_t length) construct mcuf::lang::ArrayPrototype(e, length * sizeof(E), sizeof(E)){
    return;
  }

  /**
   * Destruct.
   */
  public: virtual ~Array() = default;
  
  /* **************************************************************************************
   * Operator Method
   */
  
  /**
   * Operator array.
   */
  public: E operator[](int index) const{
    return static_cast<E*>(this->mPointer)[index];
  }

  /**
   * Operator array.
   */
  public: E& operator[](int index){
    return static_cast<E*>(this->mPointer)[index];
  }
  
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
   * Length
   */
  public: uint32_t length(void) const {
    return this->mElementLength;
  }
  
  /**
   * 
   */
  public: int indexOf(const E& e) const{
    return this->ArrayPrototype::indexOf(&e);
  }
  
  /**
   * 
   */
  public: bool contains(const E& e) const{
    return (this->ArrayPrototype::indexOf(&e) != -1);
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
 
/* ****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_FCCC3E6F_E524_4464_BA6F_FF9492970DA8 */
