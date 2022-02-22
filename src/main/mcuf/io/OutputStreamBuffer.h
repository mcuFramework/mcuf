/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_773B1369_98E1_4A0E_BE62_135FA19FF875
#define MCUF_773B1369_98E1_4A0E_BE62_135FA19FF875

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/OutputStream.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/io/RingBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class OutputStreamBuffer;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::OutputStreamBuffer extends mcuf::io::RingBuffer implements
  public mcuf::io::OutputStream,
  public mcuf::io::CompletionHandler<int ,void*>{

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
    mcuf::io::OutputStream* mOutputStream;
    mcuf::io::ByteBuffer mByteBuffer;

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
     * @brief Construct a new Output Stream Buffer object
     * 
     * @param memory 
     */
    OutputStreamBuffer(mcuf::io::OutputStream* outputStream ,const mcuf::lang::Memory& memory);

    /**
     * @brief Destroy the Output Stream Buffer object
     * 
     */
    virtual ~OutputStreamBuffer(void);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::OutputStream
   */
  public:

    /**
     * @brief 
     * 
     * @return true successful.
     * @return false fail.
     */
    virtual bool abortWrite(void) override;
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool writeBusy(void) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool write(mcuf::io::ByteBuffer* byteBuffer, 
                       void* attachment,
                       mcuf::io::CompletionHandler<int, void*>* handler) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::CompletionHandler<int ,void*>
   */
  public:
  
    /**
     * @brief 
     * 
     * @param result 
     * @param attachment 
     */
    virtual void completed(int result, void* attachment) override;
    
    /**
     * @brief 
     * 
     * @param exc 
     * @param attachment 
     */
    virtual void failed(void* exc, void* attachment) override;

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
  private:
    
    /**
     *
     */
    void writePacket(void);
  
};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_773B1369_98E1_4A0E_BE62_135FA19FF875 */
