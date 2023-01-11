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
#include "./mcuf_base.h"
#include "./OutputBuffer.h"
#include "./CompletionHandler.h"
#include "./Future.h"
#include "./Object.h"
#include "./Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  interface OutputStream;
}



/* ****************************************************************************************
 * Class/Interface/Struct
 */
interface mcuf::OutputStream extends virtual mcuf::Interface{

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
  virtual bool write(mcuf::OutputBuffer& outputBuffer, int timeout) abstract;  
  
  /**
   * @brief 
   * 
   * @param outputBuffer
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.
   */
  virtual bool write(mcuf::OutputBuffer& outputBuffer, 
                     void* attachment,
                     mcuf::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param outputBuffer
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool write(mcuf::OutputBuffer& outputBuffer, mcuf::Future& future) abstract;

};



/* *****************************************************************************************
 * End of file
 */ 


#endif /* MCUF_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4 */
