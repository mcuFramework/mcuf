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
#include "mcuf/io/OutputBuffer.h"
#include "mcuf/io/CompletionHandler.h"
#include "mcuf/io/Future.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Interface.h"

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
interface mcuf::io::OutputStream extends virtual mcuf::lang::Interface{

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
   * @param outputBuffer
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool write(mcuf::io::OutputBuffer& outputBuffer, int timeout) abstract;  
  
  /**
   * @brief 
   * 
   * @param outputBuffer
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.
   */
  virtual bool write(mcuf::io::OutputBuffer& outputBuffer, 
                     void* attachment,
                     mcuf::io::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param outputBuffer
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool write(mcuf::io::OutputBuffer& outputBuffer, mcuf::io::Future& future) abstract;

};



/* *****************************************************************************************
 * End of file
 */ 


#endif /* MCUF_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4 */
