/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E558154C_6539_46CF_9DFD_8E9891A12C72
#define MCUF_E558154C_6539_46CF_9DFD_8E9891A12C72

/* ****************************************************************************************
 * Include
 */  
#include "mcuf.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace test{
  class TestStream;
}

/* ****************************************************************************************
 * Class Object
 */  
class test::TestStream : 
      public mcuf::io::Stream{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  public: TestStream(void) = default;

  /**
   * Disconstruct.
   */
  public: virtual ~TestStream(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /**
   *
   */
  public: virtual int available(void) override;

  /** 
   * 
   */
  public: virtual void close(void) override;

  /**
   *
   */
  public: virtual void flush(void) override;
  
  /**
   * 
   */
  public: virtual bool isOpen(void) override;  

  /**
   *  read async
   */
  public: virtual bool read(mcuf::io::channel::ByteBuffer& byteBuffer, 
                            void* attachment,
                            mcuf::io::channel::CompletionHandler<int, void*>* handler) override;
    
  /**
   *  
   */
  public: virtual int skip(int skip) override;

  /**
   *  write nonBlocking
   */
  public: virtual bool write(mcuf::io::channel::ByteBuffer& byteBuffer, 
                             void* attachment,
                             mcuf::io::channel::CompletionHandler<int, void*>* handler) override;
																

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

};



/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_E558154C_6539_46CF_9DFD_8E9891A12C72 */
