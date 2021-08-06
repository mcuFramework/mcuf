/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef frameworl_function_SupplierEvent_hpp_
#define frameworl_function_SupplierEvent_hpp_

/* ****************************************************************************************
 * Include
 */  
#include "../function/Supplier.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T> class SupplierEvent;
  }
}



/* ****************************************************************************************
 * Class SupplierEvent
 */  
template<typename T>
class mcuf::function::SupplierEvent :
      public mcuf::function::Supplier<T>{

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
  private: T (*event)(void);

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
  public: SupplierEvent(T (*event)(void)){

    this->event = event;
    return;
  }
  
  /**
   * 
   */
  public: virtual ~SupplierEvent() = default;

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /**
   * 
   */
  public: virtual T get(void){
    return this->event();
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



#endif //frameworl_function_SupplierEvent_hpp_
/* *****************************************************************************************
 * End of file
 */ 
