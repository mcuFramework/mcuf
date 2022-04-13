/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE
#define MCUF_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/function/Runnable.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    class RunnableEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::function::RunnableEvent extends mcuf::lang::Object implements 
  public mcuf::function::Runnable{

  typedef void (*Method)(void);
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
     * @brief Construct a new Runnable Event object
     * 
     * @param event 
     */
    RunnableEvent(Method method){
      this->mMethod = method;
      return;
    }
  
    /**
     * @brief Destroy the Runnable Event object
     * 
     */
    ~RunnableEvent(void) override {
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
  public:
  
    /**
     * @brief 
     * 
     */
    virtual void run(void) override {
      this->mMethod();
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

#endif /* MCUF_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE */
