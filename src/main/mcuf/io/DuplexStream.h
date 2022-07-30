/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_EBD2E882_DAAB_4966_A7B2_17D8C7EFDED7
#define MCUF_EBD2E882_DAAB_4966_A7B2_17D8C7EFDED7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/InputBuffer.h"
#include "mcuf/io/OutputBuffer.h"
#include "mcuf/io/Future.h"
#include "mcuf/io/CompletionHandler.h"
#include "mcuf/lang/Interface.h"


/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace io{
    interface DuplexStream;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::io::DuplexStream extends mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abortTransfer(void) abstract;  
  
  /**
   * @brief 
   * 
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool transferBusy(void) abstract;

  /**
   * @brief 
   * 
   * @param inputBuffer 
   * @param outputBuffer 
   * @param timeout 
   * @return true 
   * @return false 
   */
  virtual bool transfer(mcuf::io::InputBuffer& inputBuffer, 
                        mcuf::io::OutputBuffer& outputBuffer, 
                        int timeout) abstract;

  /**
   * @brief 
   * 
   * @param inputBuffer 
   * @param outputBuffer 
   * @param attachment 
   * @param handler 
   * @return true 
   * @return false 
   */
  virtual bool transfer(mcuf::io::InputBuffer& inputBuffer, 
                        mcuf::io::OutputBuffer& outputBuffer, 
                        void* attachment,
                        mcuf::io::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param inputBuffer 
   * @param outputBuffer 
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool transfer(mcuf::io::InputBuffer& inputBuffer,
                        mcuf::io::OutputBuffer& outputBuffer,
                        mcuf::io::Future& future) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_EBD2E882_DAAB_4966_A7B2_17D8C7EFDED7 */
