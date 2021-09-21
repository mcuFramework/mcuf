/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D6412968_F88E_43C3_9B72_FA8611376187
#define MCUF_D6412968_F88E_43C3_9B72_FA8611376187

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Pointer;
  }
}

/* ****************************************************************************************
 * Class Pointer
 */  
class mcuf::lang::Pointer extends mcuf::lang::Object{
      
  /* **************************************************************************************
   * Subclass
   */
   
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: void* mPointer;

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

  /**
   * Construct a null pointer.
   */
  public: Pointer(void);

  /**
   * Construct a pointer.
   * 
   * @param pointer pointer.
   */
  public: Pointer(void* pointer);

  /**
   * Construct a pointer.
   * 
   * @param pointer pointer at value.
   */
  public: Pointer(uint32_t pointer);
  
  /**
   * Destructor.
   */
  public: virtual ~Pointer() = default;

  /* **************************************************************************************
   * Operator Method
   */

  /**
   * Operator equal
   */
  public: void* operator=(void* pointer);

  /* **************************************************************************************
   * Public Method <Static>
   */

  /**
   * 
   */
  public: static Pointer nullPointer(void);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: Pointer& copy(const void* source, uint32_t length);

  /**
   * 
   */
  public: Pointer& copy(const void* source, uint32_t shift, uint32_t length);

  /**
   * 
   */
  public: Pointer& copy(const void* source, uint32_t shift, uint32_t start, uint32_t length);

  /**
   * 
   */
  public: char getByte(uint32_t shift);

  /**
   * 
   */
  public: int getInteger(uint32_t shift);

  /**
   * 
   */
  public: short getShort(uint32_t shift);

  /**
   * 
   */
  public: Pointer getPointer(void);

  /**
   * 
   */
  public: Pointer getPointer(uint32_t offset);

  /**
   * 
   */
  public: uint32_t getPointerValue(void);

  /**
   * 
   */
  public: bool isNull(void);

  /**
   * 
   */
  public: void* pointer(void);

  /**
   * 
   */
  public: void* pointer(uint32_t offset);

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


#endif/* MCUF_D6412968_F88E_43C3_9B72_FA8611376187 */
