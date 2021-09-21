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
class mcuf::lang::Array extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: E* e;
  protected: uint32_t mLength;

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

  public: Array(mcuf::lang::Memory& memory){
    this->e = (E*)memory.pointer();
    this->mLength = (memory.length() / sizeof(E));
  }

  /**
   * Construct.
   */
  public: Array(E* e, uint32_t length){
    
    this->e = e;
    this->mLength = length;
    return;
  }

  /**
   * Disconstruct.
   */
  public: virtual ~Array() = default;
  
  /* **************************************************************************************
   * Operator Method
   */
  
  /**
   * Operator array.
   */
  public: inline E& operator[](int index){
    return this->e[index];
  }

  /**
   * Operator array.
   */
  public: inline E& operator[](int index) const{
    return this->e[index];
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
    return this->mLength;
  }

  /**
   * 
   */
  public: Array<E>& clear(void){
    memset(this->e, 0x00, sizeof(e) * this->mLength);
    return *this;
  }

  /**
   * 
   */
  public: Array<E>& clear(uint32_t shift){
    memset(&this->e[shift], 0x00, sizeof(E));
    return *this;
  }

  /**
   * 
   */
  public: mcuf::lang::Memory getMemory(){
    return mcuf::lang::Memory(this->e, this->mLength * sizeof(E));
  }

  /**
   * 
   */
  public: mcuf::lang::Pointer getPointer(void){
    return mcuf::lang::Pointer(this->e, sizeof(E));
  }

  /**
   * 
   */
  public: int indexOf(const E e){
    int result = -1;

    for(int i=0; i<this->mLength; i++){
      if(memcmp(&this->e[i], &e, sizeof(E)) != 0)
        continue;

      result = i;
      break;
    }

    return result;
  }

  /**
   * 
   */
  public: bool contains(const E e){
    return (this->indexOf(e) != -1);
  }

  /**
   * 
   */
  public: Array<E>& put(E e, uint32_t shift){
    this->e[shift] = e;
    return *this;
  }

  /**
   * 
   */
  public: Array<E>& put(const E& e, uint32_t shift){
    this->e[shift] = e;
    return *this;
  }

  /**
   * 
   */
  public: E get(uint32_t shift){
    return this->e[ shift];
  }

  /**
   * 
   */
  public: E* getArray(){
    return this->e;
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
 *  End of file
 */ 


#endif/* MCUF_FCCC3E6F_E524_4464_BA6F_FF9492970DA8 */
