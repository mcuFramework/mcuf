/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D6F50448_94E0_40DA_953B_6531A94F130B
#define MCUF_D6F50448_94E0_40DA_953B_6531A94F130B

/* ****************************************************************************************
 * Include
 */  
#include <stdarg.h>
#include "mcuf_base.h"
#include "mcuf/io/OutputStream.hpp"
#include "mcuf/lang/Object.hpp"
#include "mcuf/lang/String.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class PrintStream;
  }
}

/* ****************************************************************************************
 * Class PrintStream
 */  
class mcuf::io::PrintStream extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */
  public: class CompletionHandlerConst;
  public: class CompletionHandlerHeap;

  /* **************************************************************************************
   * Class CompletionHandlerConst
   */
  public: class CompletionHandlerConst extends mcuf::lang::Object
                implements mcuf::io::channel::CompletionHandler<int, void*>{

    public: CompletionHandlerConst(void) = default;
    public: virtual ~CompletionHandlerConst(void) = default;
                  
    public: virtual void completed(int result, void* attachment) override;
    public: virtual void failed(mcuf::lang::Object& exc, void* attachment) override;
  };

  /* **************************************************************************************
   * Class CompletionHandlerHeap
   */
  public: class CompletionHandlerHeap extends mcuf::lang::Object
                implements mcuf::io::channel::CompletionHandler<int, void*>{

    public: CompletionHandlerHeap(void) = default;
    public: virtual ~CompletionHandlerHeap(void) = default;

    public: virtual void completed(int result, void* attachment) override;
    public: virtual void failed(mcuf::lang::Object& exc, void* attachment) override;
  };  

  /* **************************************************************************************
   * Variable <Public>
   */
  public: static const char textNextLine[];
  public: static const char textTrue[];
  public: static const char textFalse[];

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: mcuf::io::OutputStream* outputStream;
  private: CompletionHandlerConst completionHandlerConst = CompletionHandlerConst();
  private: CompletionHandlerHeap completionHandlerHeap = CompletionHandlerHeap();


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
  public: PrintStream(mcuf::io::OutputStream* outputStream);

  /**
   * Destruct.
   */
  public: virtual ~PrintStream(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: PrintStream& format(const char* format, ...);

  /**
   * 
   */
  public: PrintStream& print(bool b);

  /**
   * 
   */
  public: PrintStream& print(int i);

  /**
   * 
   */
  public: PrintStream& print(const char* string);

  /**
   * 
   */
  public: PrintStream& println(bool b);

  /**
   * 
   */
  public: PrintStream& println(int i);

  /**
   * 
   */
  public: PrintStream& println(const char* string); 
  
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

#endif/* MCUF_D6F50448_94E0_40DA_953B_6531A94F130B */
