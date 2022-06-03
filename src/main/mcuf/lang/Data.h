/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_031134DB_6B71_465A_A2FE_2CC0EF880BA0
#define MCUF_031134DB_6B71_465A_A2FE_2CC0EF880BA0

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Pointer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Data;
    class Memory;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::lang::Data extends mcuf::lang::Pointer{

  friend Memory;
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
    uint32_t mLength;

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
     * @brief Construct a new Data object
     * 
     */
    Data(void);

    /**
     * @brief Construct a new Memory object
     * 
     * @param pointer 
     * @param length 
     */
    Data(const void* pointer, size_t length);

    /**
     * @brief Construct a new Memory object
     * 
     * @param pointer 
     * @param length 
     */
    Data(void* pointer, size_t length);

    /**
     * @brief Construct a new Data object
     * 
     * @param other 
     */
    Data(const Data& other);

    /**
     * @brief Destroy the Data object
     * 
     */
    virtual ~Data(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
    /**
     * @brief 
     * 
     * @param pointer 
     * @param value 
     * @param length 
     */
    static void wipe(void* pointer, uint8_t value, int length);

    /**
     * @brief 
     * 
     * @param pointer 
     * @param length 
     */
    static void wipe(void* pointer, int length);

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Pointer
   */
  public:

    /**
     * @brief 
     * 
     * @param source 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, int length) override;

    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, int start, int length) override;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, int shift, int start, int length) override;
  
  /* **************************************************************************************
   * Public Method <Inline>
   */
  public: 

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual inline bool isReadOnly(void) const{
      return (this->mLength & 0x80000000);
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isEmpty(void) const{
      return (this->isNull()) || (this->length() == 0);
    }

    /**
     * @brief 
     * 
     * @return int 
     */
    inline int length(void) const{
      return static_cast<int>(this->mLength & 0x7FFFFFFF);
    }
    
  /* **************************************************************************************
   * Public Method
   */
  public:
    using Pointer::indexOf;
    using Pointer::indexOfString;
    using Pointer::indexOfData;
  
    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int wipe(void);

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int wipe(uint8_t value);
  
    /**
     * @brief 
     * 
     * @param value 
     * @param length 
     * @return int 
     */
    virtual int wipe(uint8_t value, int length);
  
    /**
     * @brief 
     * 
     * @param value 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int wipe(uint8_t value, int start, int length);

    /**
     * @brief 
     * 
     * @param address 
     * @return true in range.
     * @return false isn't range.
     */
    virtual bool inRange(void* address) const;

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @return mcuf::lang::Memory 
     */
    virtual mcuf::lang::Data subData(uint32_t beginIndex) const;

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @param length 
     * @return mcuf::lang::Memory 
     */
    virtual mcuf::lang::Data subData(uint32_t beginIndex, uint32_t length) const;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int insertArray(const void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int insertArray(const void* source, int shift, int start, int length);

    /**
     * @brief 
     * 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int popArray(int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int popArray(void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return true 
     * @return false 
     */
    virtual int popArray(void* source, int shift, int start, int length);

    /**
     * @brief 
     * 
     * @param ch 
     * @return int 
     */
    virtual int indexOf(char ch) const;
    
    /**
     * @brief 
     * 
     * @param ch 
     * @param offset 
     * @return int 
     */
    virtual int indexOf(char ch, int offset) const;
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    virtual int indexOfString(const char* str) const;
    
    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfData(const void* destination, int destinationLen, int start) const;
    
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

#endif /* MCUF_031134DB_6B71_465A_A2FE_2CC0EF880BA0 */
