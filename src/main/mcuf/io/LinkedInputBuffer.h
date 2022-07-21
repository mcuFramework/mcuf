/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_87EC67B3_1F8A_47E6_9439_DC0E8A5375CA
#define MCUF_87EC67B3_1F8A_47E6_9439_DC0E8A5375CA

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Object.h"
#include "mcuf/io/InputBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class LinkedInputBuffer;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::LinkedInputBuffer extends mcuf::lang::Object implements
public mcuf::io::InputBuffer{

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
    mcuf::io::InputBuffer& mCurrent;
    mcuf::io::InputBuffer* mNext;

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
     * @brief Construct a new Linked Input Buffer object
     * 
     * @param current 
     */
    LinkedInputBuffer(mcuf::io::InputBuffer& current);

    /**
     * @brief Construct a new Linked Input Buffer object
     * 
     * @param current 
     * @param next 
     */
    LinkedInputBuffer(mcuf::io::InputBuffer& current, mcuf::io::InputBuffer* next);

    /**
     * @brief Destroy the Linked Input Buffer object
     * 
     */
    virtual ~LinkedInputBuffer(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::InputBuffer
   */
  public:
    /**
     * @brief 取得InputBuffer是否已滿
     * 
     * @return true 已滿
     * @return false 未滿，仍有空間
     */
    virtual bool isFull(void) const override;

    /**
     * @brief 取得InputBuffer內資料數量
     * 
     * @return int InputBuffer內資料數量
     */
    virtual int remaining(void) const override;

    /**
     * @brief 將data輸入至InputBuffer
     * 
     * @param data 資料來源
     * @return true 成功將data輸入至InputBuffer
     * @return false InputBuffer已滿
     */
    virtual bool putByte(const char data) override;

    /**
     * @brief 將outputBuffer內資料輸入至InputBuffer
     * 
     * @param byteBuffer 資料來源
     * @return int 移動資料數量(byte)
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer) override;

    /**
     * @brief 將outputBuffer內資料輸入至InputBuffer並指定輸入長度
     * 
     * @param byteBuffer 資料來源
     * @param length 輸入長度
     * @return int 移動資料數量(byte)
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer, int length) override;  

    /**
     * @brief 將buffer內資料輸入至InputBuffer
     * 
     * @param buffer 資料來源
     * @param length 輸入長度
     * @return int 移動資料數量(byte)
     */
    virtual int put(const void* buffer, int length) override;
    
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

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_87EC67B3_1F8A_47E6_9439_DC0E8A5375CA */
