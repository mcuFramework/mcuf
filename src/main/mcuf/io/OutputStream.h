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
    interface OutputStream;
  }
}



/* ****************************************************************************************
 * Class/Interface/Struct
 */
interface mcuf::io::OutputStream{

  /* **************************************************************************************
   *  Method <Public>
   */
  
  /**
   * 
   */
  virtual bool abortWrite(void) abstract;
  
  /**
   * @brief 
   * 
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool writeBusy(void) abstract;

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
                     mcuf::io::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @param feture 
   * @return true 
   * @return false 
   */
  virtual bool write(mcuf::io::ByteBuffer* byteBuffer, mcuf::io::Feture& feture) abstract;

};



/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4 */
