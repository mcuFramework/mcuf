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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Memory.h"
#include "mcuf\Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class String;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::String final extends mcuf::Memory{

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
    String(const mcuf::Memory& memory);

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
    
    /**
     * @brief 
     * 
     * @param str 
     * @return String& 
     */
    inline String& operator+=(const char* str){
      this->append(str);
      return *this;
    }
    
    /**
     * @brief 
     * 
     * @param str 
     * @return String& 
     */
    inline String& operator=(const char* str){
      this->set(str);
      return *this;
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
    static int format(const mcuf::Memory& memory, const char* format, va_list args);

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
    static int format(const mcuf::Memory& memory, const char* format, ...);
    
    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return String 
     */
    static String format(int bufferSize, const char* format, ...);    
    
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
     * @param src 
     * @return int 
     */
    static int stringLength(const char* src);

  /* **************************************************************************************
   * Public Method <Override> - mcuf::Memory
   */
  public:
  
    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfData(const void* destination, int destinationLen, int start) const override;
  
  /* **************************************************************************************
   * Public Method
   */
  public:
    
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    int size(void) const;
  
    /**
     * @brief 取的String原始空間大小
     * 
     * @return int 
     */
    int bufferSize(void);

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
     * @param oldChar 
     * @param newChar 
     * @return int 
     */
    int replace(char oldChar, char newChar);
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    String& append(const char* str);
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    String& set(const char* str);

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
