/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_4E76CD8C_2BE4_404C_97CE_3D2E84E2E1D7
#define MCUF_4E76CD8C_2BE4_404C_97CE_3D2E84E2E1D7

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/Object.h"
#include "mcuf/OutputBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class OutputBufferLimit;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::OutputBufferLimit extends mcuf::Object implements
public mcuf::OutputBuffer{

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
    mcuf::OutputBuffer* mOutputBuffer;

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
     * @brief Construct a new Output Buffer Limit object
     * 
     */
    OutputBufferLimit(void);

    /**
     * @brief Destroy the Output Buffer Limit object
     * 
     */
    virtual ~OutputBufferLimit(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   *  Public Method <Override> - mcuf::OutputBuffer
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool isEmpty(void) const override;

    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int avariable(void) const override;

    /**
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool getByte(char& result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int get(mcuf::InputBuffer& inputBuffer) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int get(mcuf::InputBuffer& inputBuffer, int length) override;

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int get(void* buffer, int bufferSize) override;

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int skip(int value) override;

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
     * @brief Get the Output Buffer object
     * 
     * @return mcuf::OutputBuffer* 
     */
    virtual mcuf::OutputBuffer* getOutputBuffer(void);

    /**
     * @brief Set the Output Buffer object
     * 
     * @param outputBuffer 
     * @return mcuf::OutputBuffer* 
     */
    virtual mcuf::OutputBuffer* setOutputBuffer(mcuf::OutputBuffer* outputBuffer);

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

#endif /* MCUF_4E76CD8C_2BE4_404C_97CE_3D2E84E2E1D7 */
