/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_FC6FA4E2_E818_4894_866D_38F6B2541263
#define MCUF_FC6FA4E2_E818_4894_866D_38F6B2541263

/* ****************************************************************************************
 * Include
 */  
#include "./mcuf_base.h"
#include "./BiConsumer.h"
#include "./Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T, typename U> class BiConsumerEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<class T, class U>
class mcuf::function::BiConsumerEvent extends mcuf::Object implements 
  public mcuf::function::BiConsumer<T, U> {

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
    void (*mEvent)(T, U);

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
     * @brief Construct a new Bi Consumer Event object
     * 
     * @param event 
     */
    BiConsumerEvent(void (*event)(T, U)){

      this->mEvent = event;
      return;
    }
  
    /**
     * @brief Destroy the Bi Consumer Event object
     * 
     */
    ~BiConsumerEvent() = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::function::BiConsumer<T, U>
   */
  public:

    /**
     * @brief 
     * 
     * @param t 
     * @param u 
     */
    virtual void accept(T t, U u){
      this->mEvent(t, u);
    }

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

#endif /* MCUF_FC6FA4E2_E818_4894_866D_38F6B2541263 */
