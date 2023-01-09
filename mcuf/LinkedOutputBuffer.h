/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_07DC8820_F55B_43CA_BF40_7C0813A5DBEB
#define MCUF_07DC8820_F55B_43CA_BF40_7C0813A5DBEB

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Object.h"
#include "mcuf\OutputBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class LinkedOutputBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::LinkedOutputBuffer extends mcuf::Object implements
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
    mcuf::OutputBuffer& mCurrent;
    mcuf::OutputBuffer* mNext;

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
     * @brief Construct a new Linked Output Buffer object
     * 
     * @param current 
     */
    LinkedOutputBuffer(mcuf::OutputBuffer& current);

    /**
     * @brief Construct a new Linked Output Buffer object
     * 
     * @param current 
     * @param next 
     */
    LinkedOutputBuffer(mcuf::OutputBuffer& current, mcuf::OutputBuffer& next);
    
    /**
     * @brief Destroy the Linked Output Buffer object
     * 
     */
    virtual ~LinkedOutputBuffer(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::OutputBuffer
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

#endif /* MCUF_07DC8820_F55B_43CA_BF40_7C0813A5DBEB */
