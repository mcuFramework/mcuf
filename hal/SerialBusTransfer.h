/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D6F51B91_28D1_4137_A132_2CECD1B3E012
#define MCUF_D6F51B91_28D1_4137_A132_2CECD1B3E012

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Interface.h"
#include "mcuf\OutputBuffer.h"
#include "mcuf\InputBuffer.h"

//-----------------------------------------------------------------------------------------
#include "hal\SerialBusEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
 
namespace hal{
  interface SerialBusTransfer;
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface hal::SerialBusTransfer extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abort(void) abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isBusy(void) abstract;

  /**
   * @brief 
   * 
   * @param address 
   * @param in 
   * @param event 
   */
  virtual bool read(uint16_t address, 
                    mcuf::InputBuffer& in,
                    void* attachment,
                    hal::SerialBusEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param address 
   * @param out 
   * @param event 
   */
  virtual bool write(uint16_t address, 
                     mcuf::OutputBuffer& out,
                     void* attachment,
                     hal::SerialBusEvent* event) abstract;
  
  /**
   * @brief 
   * 
   * @param address 
   * @param out 
   * @param in 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool transfer(uint16_t address, 
                        mcuf::OutputBuffer& out, 
                        mcuf::InputBuffer& in,
                        void* attachment,
                        hal::SerialBusEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_D6F51B91_28D1_4137_A132_2CECD1B3E012 */