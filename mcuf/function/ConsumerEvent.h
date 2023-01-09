/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D2D64DF4_37AF_4608_A7A7_C551E3231977
#define MCUF_D2D64DF4_37AF_4608_A7A7_C551E3231977

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/function/Consumer.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T> class ConsumerEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T>
class mcuf::function::ConsumerEvent extends mcuf::lang::Object implements 
  public mcuf::function::Consumer<T>{

  typedef void (*Method)(T);
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    Method mMethod;

  /* **************************************************************************************
   * Abstract method <Public>
   */
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 

    /**
     * @brief Construct a new Consumer Event object
     * 
     * @param event 
     */
    ConsumerEvent(Method method){
      this->mMethod = method;
      return;
    }
  
    /**
     * @brief Destroy the Consumer Event object
     * 
     */
    virtual ~ConsumerEvent(void) override {
      return;
    }

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

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */
  public:

    /**
     * @brief 
     * 
     * @param t 
     */
    virtual void accept(T t){
      this->mMethod(t);
    }

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

#endif /* MCUF_D2D64DF4_37AF_4608_A7A7_C551E3231977 */
