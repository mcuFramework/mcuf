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
    String(void* pointer, unsigned int size);

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
    String(size_t length);

    /**
     * @brief Destroy the String object
     * 
     */
    virtual ~String(void) override;

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
     * @return String 
     */
    static String empty(void);

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @param format 
     * @param arg 
     * @return int 
     */
    static int format(void* buffer, size_t bufferSize, const char* format, va_list args);

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
    static int format(void* buffer, unsigned int bufferSize, const char* format, ...);

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
     * @param src 
     * @param format 
     * @param args 
     * @return int 
     */
    static int scanFormat(const char* src, const char* format, va_list args);
    
    /**
     * @brief 
     * 
     * @param src 
     * @param format 
     * @param ... 
     * @return int 
     */
    static int scanFormat(const char* src, const char* format, ...);

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return String 
     */
    static String format(int bufferSize, const char* format, ...);

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Memory
   */
  public:
    /**
     * @brief 
     * 
     * @param ch 
     * @return int 
     */
    virtual int indexOf(char ch) const override;
    
    /**
     * @brief 
     * 
     * @param ch 
     * @param offset 
     * @return int 
     */
    virtual int indexOf(char ch, int offset) const override;
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    virtual int indexOfString(const char* str) const override;  
  
    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfMemory(const void* destination, int destinationLen, int start) const override;
  
  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return int 
     */
    int scanFormat(const char* format, ...);
  
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

    /**
     * @brief 
     * 
     */
    void convertUpper(void);

    /**
     * @brief 
     * 
     */
    void convertLower(void);

    /**
     * @brief 
     * 
     * @return String 
     */
    String toUpper(void) const;

    /**
     * @brief 
     * 
     * @return String 
     */
    String toLower(void) const;
    
    /**
     * @brief 
     * 
     * @return String 
     */
    String clone(void) const;
    
    /**
     * @brief 
     * 
     * @param length 
     * @return String 
     */
    String clone(int length) const;
    
    /**
     * @brief 
     * 
     * @param offset  
     * @return String 
     */
    String clone(int offset, int length) const;
  
    /**
     * @brief 
     * 
     * @return int 
     */
    int size(void) const; 

    /**
     * @brief 
     * 
     * @param oldChar 
     * @param newChar 
     * @return int 
     */
    int replace(char oldChar, char newChar);

  /* **************************************************************************************
   * Public Method <Inline>
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
 
#endif /* MCUF_F115800B_0B0A_4795_ABFB_A37BD1DE2055 */
