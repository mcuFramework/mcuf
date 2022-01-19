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
#include "mcuf/io/channel/ByteBuffer.hpp"
#include "mcuf/io/channel/CompletionHandler.hpp"
#include "mcuf/lang/Object.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    interface OutputStream;
  }
}



/* ****************************************************************************************
 * Class Map
 */
interface mcuf::io::OutputStream{
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
   * @brief 
   * 
   */
  virtual void flush(void) abstract;

  /**
   * @brief 
   * 
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool isWriteBusy(void) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.`
   */
  virtual bool write(mcuf::io::channel::ByteBuffer* byteBuffer, 
                     void* attachment,
                     mcuf::io::channel::CompletionHandler<int, void*>* handler) abstract;

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
