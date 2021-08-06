/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4
#define MCUF_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4

/* ****************************************************************************************
 * Include
 */
#include "../lang/Object.hpp"
#include "../io/channel/ByteBuffer.hpp"
#include "../function/BiConsumer.hpp"
#include "../function/BiConsumerEvent.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class OutputStream;
  }
}



/* ****************************************************************************************
 * Class Map
 */
class mcuf::io::OutputStream : 
      public mcuf::lang::Object{
  /* **************************************************************************************
   *  Variable <Public>
   */

  /* **************************************************************************************
   *  Variable <Protected>
   */

  /* **************************************************************************************
   *  Variable <Private>
   */

  /* **************************************************************************************
   *  Abstract method <Public>
   */
  
  /**
   *
   */
  public: virtual void flush(void) = 0;
  
  /**
   *  write nonBlocking
   */
  public: virtual bool write(mcuf::io::channel::ByteBuffer* byteBuffer, 
                             mcuf::lang::Pointer& attachment,
                             mcuf::io::channel::CompletionHandler<mcuf::lang::number::Integer, 
                                                                  mcuf::lang::Pointer>) = 0;
  
  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */

  /**
   * 
   */
  public: OutputStream(void) = default;
  
  /**
   * 
   */
  public: virtual ~OutputStream() = default;

  /* **************************************************************************************
   *  Public Method <Static>
   */

  /* **************************************************************************************
   *  Public Method <Override>
   */

  /* **************************************************************************************
   *  Public Method
   */

  /* **************************************************************************************
   *  Protected Method <Static>
   */

  /* **************************************************************************************
   *  Protected Method <Override>
   */

  /* **************************************************************************************
   *  Protected Method
   */

  /* **************************************************************************************
   *  Private Method <Static>
   */

  /* **************************************************************************************
   *  Private Method <Override>
   */
   
  /* **************************************************************************************
   *  Private Method
   */
    
};



/* *****************************************************************************************
 *    End of file
 */ 


#endif/* MCUF_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4 */
