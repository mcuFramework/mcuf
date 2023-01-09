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
#include "mcuf\Object.h"
#include "mcuf\PrintStream.h"
#include "mcuf\InputStreamBuffer.h"
#include "mcuf\ErrorCode.h"
#include "mcuf\RunnableEntity.h"
#include "mcuf\InterfaceKernel.h"
#include "mcuf\InterfaceThread.h"
#include "mcuf\InterfaceTimer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class System;
  class SystemRegister;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::SystemRegister extends mcuf::Object{
  
  friend mcuf::System;
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
    mcuf::PrintStream* mPrintStream;
    mcuf::InputStreamBuffer* mInputStreamBuffer;
    mcuf::InterfaceKernel* mInterfaceKernel;
    mcuf::InterfaceThread* mInterfaceThread;
    mcuf::InterfaceTimer* mInterfaceTimer;
  
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
    void setInputStreamBuffer(mcuf::InputStreamBuffer* inputStreamBuffer);

    /**
     * @brief Set the PrintStream object
     * 
     * @param printStream 
     */
    void setPrintStream(mcuf::PrintStream* printStream);
  
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
    void setInterfaceKernel(mcuf::InterfaceKernel* interfaceKernel);

    /**
     * @brief Set the Interface Thread object
     * 
     * @param interfaceThread 
     */
    void setInterfaceThread(mcuf::InterfaceThread* interfaceThread);
    
    /**
     * @brief Set the Interface Timer object
     * 
     * @param interfaceTimer 
     */
    void setInterfaceTimer(mcuf::InterfaceTimer* interfaceTimer);

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