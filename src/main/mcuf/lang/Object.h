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
  private:
    uint32_t objectHashCode;

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
  public:
    inline bool classAvariable(void){
      return (this->objectHashCode == this->hashCode());
    }


  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief 
     * 
     * @param milliseconds 
     */
    void delay(int milliseconds);

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    virtual bool equal(Object* object);

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    virtual bool equal(Object& object);

    /**
     * @brief 
     * 
     */
    virtual void finalize(void);

    /**
     * @brief 
     * 
     */
    virtual void wait(void);
    
    /**
     * @brief 
     * 
     * @param timeout 
     * @return true 
     * @return false 
     */
    virtual bool wait(int timeout);
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool yield(void);
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool systemLock(void);
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool systemUnlock(void);
    
    /**
     * @brief Get the Name object
     * 
     * @return const char* 
     */
    virtual const char* getName(void) const;

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t hashCode(void) const;

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
