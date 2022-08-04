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
#include "mcuf_base.h"
#include "mcuf/function/Runnable.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/ThreadPriority.h"
#include "mcuf/lang/ThreadState.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Thread;
    class System;
    
    namespace rtos{
      interface InterfaceThread;
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::Thread extends mcuf::lang::Memory implements 
public mcuf::function::Runnable{

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
    mcuf::lang::Memory mHandlerMemroy;
    Thread* mNextNode;
  
  /* **************************************************************************************
   * Variable <Static Private>
   */  
  private: 
    static mcuf::lang::rtos::InterfaceThread* sInterfaceThread;
    static Thread* threadNodeHead;

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
    Thread(const mcuf::lang::Data& stackMemory);

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
     * @brief Get the Thread object
     * 
     * @param threadID 
     * @return Thread* 
     */
    static Thread* getThread(uint32_t threadID);
  
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
     * @return mcuf::lang::ThreadPriority 
     */
    mcuf::lang::ThreadPriority getPriority(void) const;

    /**
     * @brief Get the State object
     * 
     * @return mcuf::lang::ThreadState 
     */
     mcuf::lang::ThreadState getState(void) const;
    
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
    bool start(mcuf::lang::ThreadPriority priority);
    
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
    bool setPriority(mcuf::lang::ThreadPriority priority);  

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
    static void setInterfaceThread(mcuf::lang::rtos::InterfaceThread& interfaceThread);

    /**
     * @brief 
     * 
     * @param attachment 
     */
    static void entryPoint(void* attachment);
    
    /**
     * @brief 
     * 
     * @param thread 
     * @return true 
     * @return false 
     */
    static bool nodeAdd(Thread* thread);
    
    /**
     * @brief 
     * 
     * @param thread 
     * @return true 
     * @return false 
     */
    static bool nodeRemove(Thread* thread);
   
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
