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
#include "mcuf_base.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/io/CompletionHandler.h"
#include "mcuf/io/Feture.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    interface InputStream;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */
interface mcuf::io::InputStream{

  /* **************************************************************************************
   *  Method <Public>
   */
  
  /**
   * 
   */
  virtual bool abortRead(void) abstract;  
  
  /**
   * @brief 
   * 
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool readBusy(void) abstract;
  
  /**
   * @brief nonblocking
   * 
   * @param byteBuffer 
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.
   */
  virtual bool read(mcuf::io::ByteBuffer* byteBuffer, 
                    void* attachment,
                    mcuf::io::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @param feture 
   * @return true 
   * @return false 
   */
  virtual bool read(mcuf::io::ByteBuffer* byteBuffer, mcuf::io::Feture& feture) abstract;

};

/* *****************************************************************************************
 *    End of file
 */ 

#endif/* MCUF_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55 */
