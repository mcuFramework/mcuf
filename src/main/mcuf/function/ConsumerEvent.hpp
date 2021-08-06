/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef frameworl_function_ConsumerEvent_hpp_
#define frameworl_function_ConsumerEvent_hpp_

/* ****************************************************************************************
 * Include
 */  
#include "../function/Consumer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T> class ConsumerEvent;
  }
}



/* ****************************************************************************************
 * Class ConsumerEvent
 */  
template<typename T>
class mcuf::function::ConsumerEvent :
      public mcuf::function::Consumer<T>{

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
  private: void (*event)(T);

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
  public: ConsumerEvent(void (*event)(T)){
    
    this->event = event;
    return;
  }
  
  /**
   * Disconstruct.
   */
  public: virtual ~ConsumerEvent() = default;

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

  /**
   * 
   */
  public: virtual void accept(T t){
    this->event(t);
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



#endif //frameworl_function_ConsumerEvent_hpp_
/* *****************************************************************************************
 * End of file
 */ 
