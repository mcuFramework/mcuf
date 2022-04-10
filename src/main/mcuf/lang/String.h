/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F115800B_0B0A_4795_ABFB_A37BD1DE2055
#define MCUF_F115800B_0B0A_4795_ABFB_A37BD1DE2055

/* ****************************************************************************************
 * Include
 */  
#include <stdarg.h>

#include "mcuf_base.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class String;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::String extends mcuf::lang::Memory{

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
    uint32_t mSize;
  
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
     * @brief Construct a new String object
     * 
     * @param pointer 
     * @param size 
     */
    String(void* pointer, uint32_t size);

    /**
     * @brief Construct a new String object
     * 
     * @param str 
     */
    String(const char* str);
    
    /**
     * @brief Construct a new String object
     * 
     * @param memory 
     */
    String(const mcuf::lang::Memory& memory);

    /**
     * @brief Construct a new String object
     * 
     * @param length 
     */
    String(uint32_t length);

    /**
     * @brief Destroy the String object
     * 
     */
    virtual ~String(void) = default;

  /* **************************************************************************************
   * Operator Method
   */
  public:

    /**
     * @brief 
     * 
     * @return operator const* 
     */
    inline operator const char*(void) const{
      return static_cast<const char*>(this->pointer());
    }

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @param format 
     * @param arg 
     * @return int 
     */
    static int format(void* buffer, uint32_t bufferSize, const char* format, va_list args);

    /**
     * @brief 
     * 
     * @param memory 
     * @param format 
     * @param arg 
     * @return int 
     */
    static int format(const mcuf::lang::Memory& memory, const char* format, va_list args);

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @param format 
     * @param ... 
     * @return int 
     */
    static int format(void* buffer, uint32_t bufferSize, const char* format, ...);

    /**
     * @brief 
     * 
     * @param memory 
     * @param format 
     * @param ... 
     * @return int 
     */
    static int format(const mcuf::lang::Memory& memory, const char* format, ...);

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return String 
     */
    static String format(int bufferSize, const char* format, ...);

  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief 
     * 
     * @param format 
     * @param arg 
     * @return int 
     */
    int format(const char* format, va_list arg);

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return int 
     */
    int format(const char* format, ...);  
  
  /* **************************************************************************************
   * Public Method <Inline>
   */  
  public:

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline uint32_t size(void) const{
      return this->mSize;
    }

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
 
#endif /* MCUF_F115800B_0B0A_4795_ABFB_A37BD1DE2055 */
