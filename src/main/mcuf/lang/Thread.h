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
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
abstracts class mcuf::lang::Thread extends mcuf::lang::Memory implements 
  public mcuf::function::Runnable{

  friend System;

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
    void* mThreadID = nullptr;
    Thread* mNextNode;
  
  /* **************************************************************************************
   * Variable <Static Private>
   */  
  private: 
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
     * @param memory 
     */
    Thread(const Memory& memory);

    /**
     * @brief Construct a new Thread object
     * 
     * @param memory 
     * @param name 
     */
    Thread(const Memory& memory, const char* name);

    /**
     * @brief Destroy the Thread object
     * 
     */
    virtual ~Thread(void);

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
     * @brief Get the Name object
     * 
     * @return const char* 
     */
    const char* getName(void) const;
    
    /**
     * @brief Get the Priority object
     * 
     * @return Priority 
     */
    mcuf::lang::ThreadPriority getPriority(void);

    /**
     * @brief Get the State object
     * 
     * @return State 
     */
     mcuf::lang::ThreadState getState(void);
    
    /**
     * @brief Get the Stack Size object
     * 
     * @return uint32_t 
     */
    uint32_t getStackSize(void);  
    
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

#endif/* MCUF_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293 */
