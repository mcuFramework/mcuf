/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293
#define MCUF_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../func/package-info.h"
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./ThreadPriority.h"
#include "./ThreadState.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace sys{
  class Thread;
  class System;
}

namespace rtos{
  interface InterfaceThread;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class sys::Thread extends mcuf::Memory implements 
public func::Runnable{

  friend System;
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
    mcuf::Memory mHandlerMemroy;
  
  /* **************************************************************************************
   * Variable <Static Private>
   */  
  private: 
    static rtos::InterfaceThread* sInterfaceThread;

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
     * @brief Construct a new Thread object
     * 
     */
    Thread(uint32_t stackSize);
  
    /**
     * @brief Construct a new Thread object
     * 
     */
    Thread(const mcuf::Data& stackMemory);

    /**
     * @brief Destroy the Thread object
     * 
     */
    virtual ~Thread(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
  
    /**
     * @brief 喚醒指定執行序
     * 
     */
    static void notify(uint32_t threadID);

    /**
     * @brief 取得當前執行序ID;
     * 
     * @return uint32_t 
     */
    static uint32_t getThreadID(void);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method <Inline>
   */

  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    uint32_t getID(void) const;
  
    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setThreadName(const char* name);
  
    /**
     * @brief Get the Thread Name object
     * 
     * @return const char* 
     */
    const char* getThreadName(void) const;
    
    /**
     * @brief Get the Priority object
     * 
     * @return sys::ThreadPriority 
     */
    sys::ThreadPriority getPriority(void) const;

    /**
     * @brief Get the State object
     * 
     * @return sys::ThreadState 
     */
     sys::ThreadState getState(void) const;
    
    /**
     * @brief Get the Stack Size object
     * 
     * @return uint32_t 
     */
    int getStackSize(void) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool start(void);
    
    /**
     * @brief 
     * 
     * @param priority 
     * @return true 
     * @return false 
     */
    bool start(sys::ThreadPriority priority);
    
    /**
     * @brief 
     * 
     */
    void notify(void);
    
    /**
     * @brief Set the Priority object
     * 
     * @param priority 
     * @return true 
     * @return false 
     */
    bool setPriority(sys::ThreadPriority priority);  

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isActive(void);

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
  private:
    /**
     * @brief Set the Interface Thread object
     * 
     * @param interfaceThread 
     */
    static void setInterfaceThread(rtos::InterfaceThread& interfaceThread);
   
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

#endif /* MCUF_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293 */
