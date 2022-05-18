/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_AD68F30C_7CB7_48CC_8520_CDED0C606033
#define MCUF_AD68F30C_7CB7_48CC_8520_CDED0C606033

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
    class InputBufferLimit;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::InputBufferLimit extends mcuf::lang::Object implements
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
    int mLimit;
    int mPosition;
    mcuf::io::InputBuffer* mInputBuffer;

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
     * @brief Construct a new Input Buffer Limit object
     * 
     */
    InputBufferLimit(void);

    /**
     * @brief Destroy the Input Buffer Limit object
     * 
     */
    virtual ~InputBufferLimit(void) override;

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
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool isFull(void) const override;

    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int remaining(void) const override;

    /**
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool putByte(const char result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param length 
     * @return int 
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer, int length) override;  

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int put(const void* buffer, int bufferSize) override;

  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int limit(int value);

    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int limit(void);

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int position(int value);

    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int position(void);

    /**
     * @brief 
     * 
     */
    virtual void flush(void);

    /**
     * @brief Get the Input Buffer object
     * 
     * @return mcuf::io::InputBuffer* 
     */
    virtual mcuf::io::InputBuffer* getInputBuffer(void);

    /**
     * @brief Set the Input Buffer object
     * 
     * @param inputBuffer 
     * @return mcuf::io::InputBuffer* 
     */
    virtual mcuf::io::InputBuffer* setInputBuffer(mcuf::io::InputBuffer* inputBuffer);

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

#endif /* MCUF_AD68F30C_7CB7_48CC_8520_CDED0C606033 */
