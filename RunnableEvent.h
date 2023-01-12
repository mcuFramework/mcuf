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
#include "./mcuf_base.h"
#include "./Runnable.h"
#include "./Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class RunnableEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::RunnableEvent final extends mcuf::Object implements 
public mcuf::Runnable{

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
    void (*mFunction)(void);

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
     */
    RunnableEvent(void);

    /**
     * @brief Construct a new Runnable Event object
     * 
     * @param function 
     */
    RunnableEvent(void (*function)(void));
  
    /**
     * @brief Destroy the Runnable Event object
     * 
     */
    virtual ~RunnableEvent(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::Runnable
   */
  public:
  
    /**
     * @brief 
     * 
     */
    virtual void run(void) override;

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
