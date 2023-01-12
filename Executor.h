/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B33994C2_08DF_4AFD_A659_6CE8721463F1
#define MCUF_B33994C2_08DF_4AFD_A659_6CE8721463F1

/* ****************************************************************************************
 * Include
 */  
#include "./mcuf_base.h"
#include "./Object.h"
#include "./Runnable.h"
#include "./ArrayQueue.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class Executor;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::Executor extends mcuf::ArrayQueue<mcuf::Runnable>{
  
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

  public: 

    /**
     * @brief Construct a new Executor object
     * 
     * @param memory 
     */
    Executor(const mcuf::Memory& memory);

    /**
     * @brief Construct a new Executor object
     * 
     * @param size 
     */
    Executor(uint32_t size);

    /**
     * @brief Destroy the Executor object
     * 
     */
    virtual ~Executor(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::Runnable
   */
   
  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief Add a new task in to executor.
     * 
     * @param runnable task
     * @return true 
     * @return false 
     */
    bool execute(mcuf::Runnable* runnable);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool actionSingle(void);
    
    /**
     * @brief 
     * 
     */
    void actionAll(void);  

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

#endif /* MCUF_B33994C2_08DF_4AFD_A659_6CE8721463F1 */
