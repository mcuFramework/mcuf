/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef CORE_ARTERYTEK_AT32F415_B21E95F1_A4B3_4BBD_96AA_E98F66338E8B
#define CORE_ARTERYTEK_AT32F415_B21E95F1_A4B3_4BBD_96AA_E98F66338E8B
#ifndef MCUF_03ECECB0_EFC6_464A_A4FB_833247AF27AB
#define MCUF_03ECECB0_EFC6_464A_A4FB_833247AF27AB

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/Runnable.h"
#include "mcuf/RunnableEvent.h"
#include "mcuf/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    class RunnableEntity;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::function::RunnableEntity final extends mcuf::Object implements
public mcuf::function::Runnable{

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
    mcuf::function::RunnableEvent mRunnableEvent;
    mcuf::function::Runnable* mRunnable;

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
     * @brief Construct a new Runnable Entity object
     * 
     */
    RunnableEntity(void);

    /**
     * @brief Construct a new Runnable Entity object
     * 
     * @param runnable 
     */
    RunnableEntity(mcuf::function::Runnable& runnable);

    /**
     * @brief Construct a new Runnable Entity object
     * 
     * @param function 
     */
    RunnableEntity(void (*function)(void));

    /**
     * @brief 複製建構子
     * 
     * @param source 
     */
    RunnableEntity(const RunnableEntity& source);

    /**
     * @brief Destroy the Runnable Entity object
     * 
     */
    virtual ~RunnableEntity(void) override;

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
     * @brief 
     * 
     */
    virtual void run(void) override;
  
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

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_03ECECB0_EFC6_464A_A4FB_833247AF27AB */


#endif/* CORE_ARTERYTEK_AT32F415_B21E95F1_A4B3_4BBD_96AA_E98F66338E8B */
