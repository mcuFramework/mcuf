/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE
#define MCUF_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE

/* ****************************************************************************************
 * Include
 */  
#include <stdint.h>
#include <string.h>

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Allocator.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Object;
  }
}



/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::Object : virtual public mcuf::lang::Interface{
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
  public:

    /**
     * @brief Construct a new Object object
     * 
     */
    Object(void);

    /**
     * @brief Destroy the Object object
     * 
     */
    virtual ~Object(void) override;

  /* **************************************************************************************
   * Operator Method
   */
  public:

    /**
     * @brief 
     * 
     * @param n 
     * @return void* 
     */
    void* operator new(size_t n);

    /**
     * @brief 
     * 
     * @param n 
     * @param p 
     * @return void* 
     */
    void* operator new(size_t n, void* p);
    
    /**
     * @brief 
     * 
     * @param n 
     * @param allocator 
     * @return void* 
     */
    void* operator new(size_t n, mcuf::lang::Allocator& allocator);  

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::ObjectBase
   */
  public:
    /**
     * @brief 
     * 
     * @param milliseconds 
     */
    virtual void delay(int milliseconds) const override;

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    virtual bool equal(Object* object) const override;

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    virtual bool equal(Object& object) const override;

    /**
     * @brief 
     * 
     */
    virtual void finalize(void) override;

    /**
     * @brief 
     * 
     */
    virtual void wait(void) const override;

    /**
     * @brief 
     * 
     * @param timeout 
     * @return true 
     * @return false 
     */
    virtual bool wait(int timeout) const override;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool yield(void) const override;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool systemLock(void) const override;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool systemUnlock(void) const override;

  /* **************************************************************************************
   * Public Method <Inline>
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

#endif /* MCUF_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE */
