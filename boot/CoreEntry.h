/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_08C85E2F_B814_4C16_BD4A_05789B0084E4
#define MCUF_08C85E2F_B814_4C16_BD4A_05789B0084E4

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../mcuf/package-info.h"
#include "./../sys/Thread.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace boot{
  class CoreEntry;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class boot::CoreEntry extends sys::Thread{

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
    void (*mSetup)(sys::Thread*);
    void (*mLoop)(sys::Thread*);

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
     * @brief Construct a new Core Entry object
     * 
     */
    CoreEntry(uint32_t stackSize);

    /**
     * @brief Destroy the Core Entry object
     * 
     */
    virtual ~CoreEntry(void) override;

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
     *
     */
    virtual void run(void) override;

  /* **************************************************************************************
   * Public Method
   */
  public:  
    /**
     *
     */
    void setSetup(void (*setup)(sys::Thread*));
  
    /**
     *
     */
    void setLoop(void (*loop)(sys::Thread*));
  
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

#endif /* MCUF_08C85E2F_B814_4C16_BD4A_05789B0084E4 */
