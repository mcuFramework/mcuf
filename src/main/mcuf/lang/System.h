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
#include "mcuf_base.h"
#include "mcuf/lang/ErrorCode.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Thread.h"
#include "mcuf/lang/managerment/CoreThread.h"
#include "mcuf/lang/managerment/SystemRegister.h"

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
    static mcuf::lang::managerment::SystemRegister mSystemRegister;
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
     * @return mcuf::io::PrintStream& 
     */
    static mcuf::io::PrintStream& out(void);
      
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
  
  /* **************************************************************************************
   * Public Method <Inline Static>
   */
  public: 

    /**
     * @brief 
     * 
     * @param runnable 
     * @return true 
     * @return false 
     */
    inline static bool execute(mcuf::function::Runnable& runnable){
      return System::mCoreThread->mExecutor.execute(&runnable);
    }

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
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
