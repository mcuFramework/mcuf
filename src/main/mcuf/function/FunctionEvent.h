/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_F730676C_6AFB_43FF_A269_0F8D00511C5D
#define MCUF_F730676C_6AFB_43FF_A269_0F8D00511C5D

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/function/Function.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T, typename R> class FunctionEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T, typename R>
class mcuf::function::FunctionEvent extends mcuf::lang::Object implements 
  public mcuf::function::Function<T, R>{

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
    R (*event)(T);

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
     * @brief Construct a new Function Event object
     * 
     * @param event 
     */
    FunctionEvent(R (*event)(T)){
      this->event = event;
      return;
    }
  
    /**
     * @brief Destroy the Function Event object
     * 
     */
    virtual ~FunctionEvent() = default;

  /* **************************************************************************************
   * Operator Method
   */

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
     * @param t 
     * @return R 
     */
    virtual R apply(T t){
      return this->event(t);
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

#endif/* MCUF_F730676C_6AFB_43FF_A269_0F8D00511C5D */
