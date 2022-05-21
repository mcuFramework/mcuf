/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_5D489452_7B4D_4E44_8969_F33817E5C74F
#define MCUF_5D489452_7B4D_4E44_8969_F33817E5C74F

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/util/Executor.h"
#include "mcuf/util/Timer.h"
#include "mcuf/util/TimerTask.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace managerment{
      class CoreTick;
      class CoreThread;
    }
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::lang::managerment::CoreTick extends mcuf::util::TimerTask{

  friend mcuf::lang::managerment::CoreThread;
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
    mcuf::util::Executor mExecutor;
    uint32_t mTickBase;

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
     * @brief Construct a new Core Tick object
     * 
     * @param executeQueue 
     * @param tickBase 
     */
    CoreTick(uint32_t executeQueue, uint32_t tickBase);

    /**
     * @brief Destroy the Core Tick object
     * 
     */
    virtual ~CoreTick(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::function::Runnable
   */
  public:
    /**
     * @brief 
     * 
     */
    virtual void run(void) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */  
  public:
    /**
     * @brief Get the Tick Base object
     * 
     * @return int 
     */
    int getTickBase(void){
      return static_cast<int>(this->mTickBase);
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

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_5D489452_7B4D_4E44_8969_F33817E5C74F */
