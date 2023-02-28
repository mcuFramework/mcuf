/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_ECCE32BB_1A96_496A_95AD_A35907FC3343
#define MCUF_ECCE32BB_1A96_496A_95AD_A35907FC3343

/* ****************************************************************************************
 * Include
 */  
#include "./mcuf_base.h"
#include "./Supplier.h"
#include "./Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  template<typename T> class SupplierEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T>
class mcuf::SupplierEvent extends mcuf::Object implements 
  public mcuf::Supplier<T>{
  
  typedef T (*Method)(void);
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
     * @brief Construct a new Supplier Event object
     * 
     * @param event 
     */
    SupplierEvent(Method method){
      this->mMethod = method;
      return;
    }
    
    /**
     * @brief Destroy the Supplier Event object
     * 
     */
    virtual ~SupplierEvent(void) override {
      return;
    }

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */
  public:

    /**
     * @brief 
     * 
     * @return T 
     */
    virtual T get(void){
      return this->method();
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
 * End of file
 */ 

#endif /* MCUF_ECCE32BB_1A96_496A_95AD_A35907FC3343 */
