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
#include "mcuf_base.h"
#include "mcuf/function/Supplier.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T> class SupplierEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T>
class mcuf::function::SupplierEvent extends mcuf::lang::Object implements 
  public mcuf::function::Supplier<T>{

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
    T (*event)(void);

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
    SupplierEvent(T (*event)(void)){

      this->event = event;
      return;
    }
    
    /**
     * @brief Destroy the Supplier Event object
     * 
     */
    virtual ~SupplierEvent() = default;

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

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_ECCE32BB_1A96_496A_95AD_A35907FC3343 */
