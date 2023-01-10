/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AE54A221_DC19_452D_9BEB_00BF5CA639E4
#define MCUF_AE54A221_DC19_452D_9BEB_00BF5CA639E4

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"
#include "mcuf/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class LinkedEntity;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::LinkedEntity extends mcuf::Object{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: 
    void* mBase;
    LinkedEntity* mNext;

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
  public:

    /**
     * @brief Construct a new Linked Entity object
     * 
     * @param base 
     */
    LinkedEntity(void* base);

    /**
     * @brief Destroy the Linked Entity object
     * 
     */
    virtual ~LinkedEntity(void) override;

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
     * @brief 
     * 
     * @return void* 
     */
    void* get(void);

    /**
     * @brief 
     * 
     * @param LinkedEntity 
     */
    void add(LinkedEntity* LinkedEntity);

    /**
     * @brief 
     * 
     * @param LinkedEntity 
     */
    void insert(LinkedEntity* LinkedEntity);

    /**
     * @brief 
     * 
     * @return LinkedEntity* 
     */
    LinkedEntity* next(void);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool hasNext(void);

    /**
     * @brief 
     * 
     * @return LinkedEntity* 
     */
    LinkedEntity* remove(void);
    
    /**
     * @brief 
     * 
     * @return LinkedEntity* 
     */
    LinkedEntity* removeAll(void);  

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

#endif /* MCUF_AE54A221_DC19_452D_9BEB_00BF5CA639E4 */
