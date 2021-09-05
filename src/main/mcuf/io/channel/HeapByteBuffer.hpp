/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E0B5ECF0_1486_4C83_8BD6_4CCAAD397B12
#define MCUF_E0B5ECF0_1486_4C83_8BD6_4CCAAD397B12

/* ****************************************************************************************
 * Include
 */  
#include "ByteBuffer.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    namespace channel{
      class HeapByteBuffer;
    }
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::io::channel::HeapByteBuffer :
      public mcuf::io::channel::ByteBuffer{

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
  public: HeapByteBuffer(size_t length);

  /**
   * Construct.
   */
  public: HeapByteBuffer(void* pointer, size_t length);

  /**
   * Distruct.
   */
  public: virtual ~HeapByteBuffer(void);

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

#endif/* MCUF_E0B5ECF0_1486_4C83_8BD6_4CCAAD397B12 */
