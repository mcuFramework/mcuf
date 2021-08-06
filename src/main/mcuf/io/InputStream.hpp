/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55
#define MCUF_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55

/* ****************************************************************************************
 * Include
 */
#include "../lang/Object.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class InputStream;
  }
}



/* ****************************************************************************************
 * Class Map
 */
class mcuf::io::InputStream : 
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
  public: virtual int available(void) = 0;
  
  /**
   *  read async
   */
  public: virtual bool read(mcuf::io::channel::ByteBuffer* byteBuffer, 
                            mcuf::lang::Pointer& attachment,
                            mcuf::io::channel::CompletionHandler<mcuf::lang::number::Integer, 
                                                                 mcuf::lang::Pointer>) = 0;
    
  /**
   *  
   */
  public: virtual int skip(int skip) = 0;

  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */

  /* **************************************************************************************
   *  Public Method <Static>
   */

  /* **************************************************************************************
   *  Public Method <Override>
   */

  /* **************************************************************************************
   *  Public Method
   */
  
  /**
   * 
   */
  public: InputStream(void) = default;
  
  /**
   * 
   */
  public: virtual ~InputStream() = default;
  
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


#endif/* MCUF_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55 */
