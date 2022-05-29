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
#include "mcuf/lang/Allocator.h"



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
class mcuf::lang::Object{

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
    virtual ~Object(void);

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
     * @param milliseconds 
     */
    void delay(int milliseconds) const;

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    virtual bool equal(Object* object) const;

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    virtual bool equal(Object& object) const;

    /**
     * @brief 
     * 
     */
    virtual void finalize(void);

    /**
     * @brief 
     * 
     */
    virtual void wait(void) const;
    
    /**
     * @brief 
     * 
     * @param timeout 
     * @return true 
     * @return false 
     */
    virtual bool wait(int timeout) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool yield(void) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool systemLock(void) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool systemUnlock(void) const;

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
