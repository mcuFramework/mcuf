/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D05E4481_5CDE_46E0_A44E_D0955341F7B6
#define MCUF_D05E4481_5CDE_46E0_A44E_D0955341F7B6

/* ****************************************************************************************
 * Include
 */  
#include "Fifo.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class HeapFifo;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::util::HeapFifo : 
      public mcuf::util::Fifo{

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
  public: HeapFifo(uint32_t elementSize, uint32_t capacity);

  /**
   * Disconstruct.
   */
  public: ~HeapFifo(void);

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
#endif /* MCUF_D05E4481_5CDE_46E0_A44E_D0955341F7B6 */
