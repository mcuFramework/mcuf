/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BB9B7C70_E040_4995_A1F3_1855850093BD
#define MCUF_BB9B7C70_E040_4995_A1F3_1855850093BD

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./mcuf_base.h"
#include "./CoreTick.h"
#include "./Memory.h"
#include "./ThreadEvent.h"
#include "./Executor.h"
#include "./Timer.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class System;
  class CoreThread;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::CoreThread extends mcuf::Thread{
  friend mcuf::System;
  
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
    mcuf::Thread* mUserThread;
    mcuf::CoreTick mCoreTick;
    mcuf::Executor mExecutor;
    uint32_t mTickBase;
    bool mStart;
    bool mOnWait;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  private: 

    /**
     * @brief Construct a new Core Thread object
     * 
     * @param attachment 
     */
    CoreThread(uint32_t executeQueue, uint32_t tickQueue, uint32_t tickBase, mcuf::Thread* userThread);

  public: 

    /**
     * @brief Destroy the Core Thread object
     * 
     */
    virtual ~CoreThread(void) override;

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
   * Public Method <Override> - mcuf::Runnable
   */
  public: 
  
    /**
     * @brief 
     * 
     */
    void run(void) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:   
    bool tick(mcuf::Runnable& runnable){
      return this->mCoreTick.mExecutor.execute(&runnable);
    }
  
  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief 
     * 
     * @param runnable 
     * @return true 
     * @return false 
     */
    bool execute(mcuf::Runnable& runnable);

    /**
     * @brief 
     * 
     */
    void stop(void);

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

#endif /* MCUF_BB9B7C70_E040_4995_A1F3_1855850093BD */
