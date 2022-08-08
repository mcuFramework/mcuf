/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C
#define MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/ErrorCode.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Thread.h"
#include "mcuf/lang/managerment/CoreTick.h"
#include "mcuf/lang/managerment/CoreThread.h"
#include "mcuf/lang/managerment/SystemRegister.h"
#include "mcuf/lang/rtos/InterfaceKernel.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class System;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::System final extends mcuf::lang::Object{
  friend Object;
  
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
    static mcuf::lang::rtos::InterfaceKernel* sInterfaceKernel;
    static mcuf::lang::managerment::SystemRegister* mSystemRegister;
    static mcuf::lang::managerment::CoreThread* mCoreThread;

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
     * @brief Construct a new System object
     * 
     */
    System(void);

    /**
     * @brief Destroy the System object
     * 
     */
    virtual ~System(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:

    /**
     * @brief 
     * 
     */
    static void reboot(void);

    /**
     * @brief 
     * 
     * @return mcuf::io::InputStream& 
     */
    static mcuf::io::InputStreamBuffer& in(void);

    /**
     * @brief 
     * 
     * @return mcuf::io::PrintStream& 
     */
    static mcuf::io::PrintStream& out(void);
      
    /**
     * @brief 
     * 
     */
    static void initialize(void);
      
    /**
     * @brief 
     * 
     * @param userThread 
     */
    static void start(mcuf::lang::Thread& userThread);

    /**
     * @brief 
     * 
     * @param address 
     * @param code
     */
    static void error(const void* address, ErrorCode code);
    
    /**
     * @brief Get the Register object
     * 
     * @return mcuf::lang::managerment::SystemRegister 
     */
    static mcuf::lang::managerment::SystemRegister& getRegister(void);
    
    /**
     * @brief Get the Core Clock object
     * 
     * @return uint32_t 
     */
    static uint32_t getCoreClock(void);
    
    /**
     * @brief 
     * 
     * @param times 
     */
    static void lowerDelay(uint32_t times);
  
    /**
     * @brief 
     * 
     * @param runnable 
     * @return true 
     * @return false 
     */
    static void execute(mcuf::function::Runnable& runnable);

    /**
     * @brief 
     * 
     * @param runnable 
     */
    static void tick(mcuf::function::Runnable& runnable);
    
    /**
     * @brief 執行idle是件
     * 
     */
    static void idleTask(void);
  
  /* **************************************************************************************
   * Public Method <Inline Static>
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
  private:
    
    /**
     * @brief 
     *
     */
    static void setInterfaceKernel(mcuf::lang::rtos::InterfaceKernel& interfacrKernel);
  
};

using mcuf::lang::System;

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
