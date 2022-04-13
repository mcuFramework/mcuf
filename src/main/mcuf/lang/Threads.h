/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_EE4D20CF_E390_4820_8EDB_28EB54FA83B7
#define MCUF_EE4D20CF_E390_4820_8EDB_28EB54FA83B7

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Thread.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Threads;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::Threads extends mcuf::lang::Object{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

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
     * @brief Construct a new Threads object
     * 
     */
    Threads(void);


  public: 
    /**
     * @brief 
     * 
     */
    virtual ~Threads(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */ 
  public:

    /**
     * @brief Get the Thread I D object
     * 
     * @return uint32_t 
     */
    static uint32_t getThreadID(void);

    /**
     * @brief Get the Name object
     * 
     * @param threadID 
     * @return const char* 
     */
    static const char* getName(uint32_t threadID);

    /**
     * @brief Get the Count object
     * 
     * @return uint32_t 
     */
    static uint32_t getCount(void);

    /**
     * @brief Get the State object
     * 
     * @param threadID 
     * @return mcuf::lang::Thread::State 
     */
    static mcuf::lang::ThreadState getState(uint32_t threadID);
    
    /**
     * @brief Get the Priority object
     * 
     * @param threadID 
     * @return mcuf::lang::Thread::Priority 
     */
    static mcuf::lang::ThreadPriority getPriority(uint32_t threadID);
    
    /**
     * @brief 
     * 
     * @param threadID 
     */
    static void notify(uint32_t threadID);
    
    /**
     * @brief Set the Priority object
     * 
     * @param threadID 
     * @param priority 
     * @return true 
     * @return false 
     */
    static bool setPriority(uint32_t threadID, mcuf::lang::ThreadPriority priority);  
  
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

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_EE4D20CF_E390_4820_8EDB_28EB54FA83B7 */
