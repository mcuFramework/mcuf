/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_250BB139_7AA6_49B5_A65F_5344E37B3F8A
#define MCUF_250BB139_7AA6_49B5_A65F_5344E37B3F8A

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Object.h"
#include "mcuf/io/PrintStream.h"
#include "mcuf/io/InputStreamBuffer.h"
#include "mcuf/lang/ErrorCode.h"
#include "mcuf/function/RunnableEntity.h"
#include "mcuf/lang/rtos/InterfaceKernel.h"
#include "mcuf/lang/rtos/InterfaceThread.h"
#include "mcuf/lang/rtos/InterfaceTimer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf::lang{
  class System;

  namespace managerment{
    class SystemRegister;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::lang::managerment::SystemRegister extends mcuf::lang::Object{
  
  friend mcuf::lang::System;
  /* **************************************************************************************
   * Typedef
   */
  public:
    typedef bool (*ErrorCodeHandler)(const void* address, ErrorCode code);
    typedef void (*SystemReset)(void);
  
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
    mcuf::function::RunnableEntity mIdleTask;
    ErrorCodeHandler mErrorCodeHandler;
    SystemReset mSystemReset;
    mcuf::io::PrintStream* mPrintStream;
    mcuf::io::InputStreamBuffer* mInputStreamBuffer;
    mcuf::lang::rtos::InterfaceKernel* mInterfaceKernel;
    mcuf::lang::rtos::InterfaceThread* mInterfaceThread;
    mcuf::lang::rtos::InterfaceTimer* mInterfaceTimer;
  
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
     * @brief Construct a new System Register object
     * 
     */
    SystemRegister(void);

    /**
     * @brief Destroy the System Register object
     * 
     */
    virtual ~SystemRegister(void) override;

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
   * Public Method
   */
  public:
    /**
     * @brief Set the InputStreamBuffer object
     * 
     * @param inputStreamBuffer 
     */
    void setInputStreamBuffer(mcuf::io::InputStreamBuffer* inputStreamBuffer);

    /**
     * @brief Set the PrintStream object
     * 
     * @param printStream 
     */
    void setPrintStream(mcuf::io::PrintStream* printStream);
  
    /**
     * @brief Set the Error Code Handler object
     * 
     * @param errorCodeHandler 
     */
    void setErrorCodeHandler(ErrorCodeHandler errorCodeHandler);

    /**
     * @brief Set the System Reset object
     * 
     * @param systemReset 
     */
    void setSystemReset(SystemReset systemReset);
    
    /**
     * @brief Set the Idle Task object
     * 
     * @param task 
     */
    void setIdleTask(mcuf::function::RunnableEntity task);

    /**
     * @brief Set the Interface Kernel object
     * 
     * @param interfaceKernel 
     */
    void setInterfaceKernel(mcuf::lang::rtos::InterfaceKernel* interfaceKernel);

    /**
     * @brief Set the Interface Thread object
     * 
     * @param interfaceThread 
     */
    void setInterfaceThread(mcuf::lang::rtos::InterfaceThread* interfaceThread);
    
    /**
     * @brief Set the Interface Timer object
     * 
     * @param interfaceTimer 
     */
    void setInterfaceTimer(mcuf::lang::rtos::InterfaceTimer* interfaceTimer);

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

#endif /* MCUF_250BB139_7AA6_49B5_A65F_5344E37B3F8A */
