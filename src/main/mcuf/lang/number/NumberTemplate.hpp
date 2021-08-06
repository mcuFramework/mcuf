/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C155091E_C0E7_4C0C_8C88_BD5E336199FE
#define MCUF_C155091E_C0E7_4C0C_8C88_BD5E336199FE

/* ****************************************************************************************
 * Include
 */  
#include "Number.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace number{
      template<typename E> class NumberTemplate;
    }
  }
}



/* ****************************************************************************************
 * Class NumberTemplate
 */  
template<typename E>
class mcuf::lang::number::NumberTemplate :
      public mcuf::lang::number::Number{
  
  /* **************************************************************************************
   * Subclass
   */
  
  /* **************************************************************************************
   * Variable <Public>
   */
  public: E value;

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
   * Construct.
   */
  public: NumberTemplate(void){
    this->value = 0;
    return;
  }

  /**
   * Construct.
   */
  public: NumberTemplate(E value){
    this->value = value;
    return;
  }
  
  /**
   * Disconstruct.
   */
  public: virtual ~NumberTemplate() = default;

  /* **************************************************************************************
   * Operator Method
   */

  /**
   * 
   */
  public: inline operator E(){
    return this->value;
  }

  /**
   * 
   */  
  public: inline bool operator==(int value){
    return (this->value == (int)value);
  }

  /**
   * 
   */
  public: inline bool operator==(E& value){
    return (this->value == value.value);
  }

  /**
   * 
   */
  public: inline bool operator==(Number& value){
    return (this->value == value.intValue());
  }

  /**
   * 
   */
  public: inline E operator=(E value){
    this->value = value;
    return this->value;
  }

  /**
   * 
   */
  public: inline NumberTemplate operator+=(int value){
    this->value += value;
    return *this;
  }

  /**
   * 
   */
  public: inline NumberTemplate operator-=(int value){
    this->value -= value;
    return *this;
  }

  /**
   * 
   */
  public: inline NumberTemplate operator*=(int value){
    this->value *= value;
    return *this;
  }

  /**
   * 
   */
  public: inline NumberTemplate operator/=(int value){
    this->value /= value;
    return *this;
  }
  
  /**
   * 
   */
  public: inline NumberTemplate operator++(int){
    NumberTemplate tmp = *this;
    ++this->value;
    return tmp;
  }
  
  /**
   * 
   */
  public: inline NumberTemplate operator++(){
    ++this->value;
    return *this;
  }

  /**
   * 
   */
  public: inline NumberTemplate operator--(int){
    NumberTemplate tmp = *this;
    --this->value;
    return tmp;
  }
  
  /**
   * 
   */
  public: inline NumberTemplate& operator--(){
    --this->value;
    return *this;
  }

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /**
   * 
   */
  public: inline virtual bool booleanValue(void){
    return this->value;
  }
  
  /**
   * 
   */
  public: inline virtual char byteValue(void){
    return this->value;
  }

  /**
   * 
   */
  public: inline virtual unsigned char unsignedByteValue(void){
    return this->value;
  }
  
  /**
   * 
   */
  public: inline virtual short shortValue(void){
    return this->value;
  }

  /**
   * 
   */                                  
  public: inline virtual unsigned short unsignedShortValue(void){
    return this->value;
  }

  /**
   * 
   */
  public: inline virtual int intValue(void){
    return this->value;
  }

  /**
   * 
   */
  public: inline virtual unsigned int unsignedIntValue(void){
    return this->value;
  }

  /**
   * 
   */
  public: inline virtual long long longValue(void){
    return this->value;
  }

  /**
   * 
   */
  public: inline virtual unsigned long long unsignedLongValue(void){
    return this->value;
  }

  /**
   * 
   */
  public: inline virtual float floatValue(void){
    return this->value;
  }

  /**
   * 
   */
  public: inline virtual double doublevalue(void){
    return this->value;
  }

  /* **************************************************************************************
   * Public Method
   */

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


#endif/* MCUF_C155091E_C0E7_4C0C_8C88_BD5E336199FE */
