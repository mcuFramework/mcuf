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
#include "./../mcuf/package-info.h"
#include "./../rtos/package-info.h"
#include "./../boot/package-info.h"
//-----------------------------------------------------------------------------------------
#include "./ErrorCode.h"
#include "./Thread.h"
#include "./SystemRegister.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace sys{
  class System;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class sys::System final extends mcuf::Object{
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
    static rtos::InterfaceKernel* sInterfaceKernel;
    static sys::SystemRegister* mSystemRegister;
    static mcuf::CoreThread* mCoreThread;

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
     * @return mcuf::InputStream& 
     */
    static mcuf::InputStreamBuffer& in(void);

    /**
     * @brief 
     * 
     * @return cli::PrintStream& 
     */
    static cli::PrintStream& out(void);
      
    /**
     * @brief 
     * 
     */
    static void initialize(void);
    
    /**
     * @brief 
     * 
     */
    static void setup(void);    
      
    /**
     * @brief 
     * 
     * @param userThread 
     */
    static void start(sys::Thread& userThread);

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
     * @return sys::SystemRegister 
     */
    static sys::SystemRegister& getRegister(void);
    
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
    static void execute(func::Runnable& runnable);

    /**
     * @brief 
     * 
     * @param runnable 
     */
    static void tick(func::Runnable& runnable);
    
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
    static void setInterfaceKernel(rtos::InterfaceKernel& interfacrKernel);
  
};

using sys::System;

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
