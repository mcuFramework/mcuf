/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474
#define MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474

/* ****************************************************************************************
 * Include
 */  
#include "..\hal\Base.hpp"
#include "..\io\channel\ByteBuffer.hpp"
#include "..\io\channel\CompletionHandler.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    class InterIntegratedCircuit;
  }
}



/* ****************************************************************************************
 * Class InterIntegratedCircuit
 */  
class mcuf::hal::InterIntegratedCircuit :
      public mcuf::hal::Base{

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
   * 
   */
  public: InterIntegratedCircuit(void) = default;

  /**
   * 
   */
  public: virtual ~InterIntegratedCircuit() = default;

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
  public: virtual uint32_t clockRate(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t clockRate(uint32_t clock) = 0;

  /**
   * 
   */
  public: void read(uint8_t address, 
                    mcuf::io::channel::ByteBuffer* bytebuffer,
                    void* attachment,
                    mcuf::io::channel::CompletionHandler<int, void*>* handler);

  /**
   * 
   */
  public: void write(uint8_t address, 
                     mcuf::io::channel::ByteBuffer* bytebuffer,
                     void* attachment,
                     mcuf::io::channel::CompletionHandler<int, void*>* handler);

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


#endif/* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
