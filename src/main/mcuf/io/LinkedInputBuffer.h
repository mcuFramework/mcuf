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
     * @brief ??????InputBuffer????????????
     * 
     * @return true ??????
     * @return false ?????????????????????
     */
    virtual bool isFull(void) const override;

    /**
     * @brief ??????InputBuffer???????????????
     * 
     * @return int InputBuffer???????????????
     */
    virtual int remaining(void) const override;

    /**
     * @brief ???data?????????InputBuffer
     * 
     * @param data ????????????
     * @return true ?????????data?????????InputBuffer
     * @return false InputBuffer??????
     */
    virtual bool putByte(const char data) override;

    /**
     * @brief ???outputBuffer??????????????????InputBuffer
     * 
     * @param byteBuffer ????????????
     * @return int ??????????????????(byte)
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer) override;

    /**
     * @brief ???outputBuffer??????????????????InputBuffer?????????????????????
     * 
     * @param byteBuffer ????????????
     * @param length ????????????
     * @return int ??????????????????(byte)
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer, int length) override;  

    /**
     * @brief ???buffer??????????????????InputBuffer
     * 
     * @param buffer ????????????
     * @param length ????????????
     * @return int ??????????????????(byte)
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
