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
#include "mcuf\InputBuffer.h"
#include "mcuf\CompletionHandler.h"
#include "mcuf\Future.h"
#include "mcuf\Object.h"
#include "mcuf\Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  interface InputStream;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */
interface mcuf::InputStream extends virtual mcuf::Interface{

  /* **************************************************************************************
   *  Method <Public>
   */
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
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
   * @brief 
   * 
   * @param outputBuffer 
   * @return int 
   */
  virtual bool read(mcuf::InputBuffer& inputBuffer, int timeout) abstract;
  
  /**
   * @brief nonblocking
   * 
   * @param outputBuffer 
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.
   */
  virtual bool read(mcuf::InputBuffer& inputBuffer, 
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
  virtual bool read(mcuf::InputBuffer& inputBuffer, mcuf::Future& future) abstract;

  /**
   * @brief 
   * 
   * @param value 
   * @param attachment 
   * @param handler 
   * @return true 
   * @return false 
   */
  virtual bool skip(int value, 
                    void* attachment,
                    mcuf::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param value 
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool skip(int value, mcuf::Future& future) abstract;

};

/* *****************************************************************************************
 *    End of file
 */ 

#endif /* MCUF_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55 */
