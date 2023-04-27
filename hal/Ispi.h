/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BA926446_3C77_4E61_B57D_D08B73D10E28
#define MCUF_BA926446_3C77_4E61_B57D_D08B73D10E28

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Base.h"

/* ****************************************************************************************
 * Namespace
 */
namespace hal{
  interface Ispi;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::Ispi extends hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Set the Clock object
   * 
   * @param clock 
   * @return true 
   * @return false 
   */
  virtual bool setClock(uint32_t clock) abstract;

  /**
   * @brief Set the Transfer Bit object
   * 
   * @param bit 
   * @return uint8_t 
   */
  virtual uint8_t setTransferBit(uint8_t bit) abstract;

  /**
   * @brief Get the Transfer Bit object
   * 
   * @return uint8_t 
   */
  virtual uint8_t getTransferBit(void) abstract;

  /**
   * @brief Get the Clock object
   * 
   * @return uint32_t 
   */
  virtual uint32_t getClock(void) abstract;

  /**
   * @brief Set the Chip Select object
   * 
   * @param cs 
   * @return true 
   * @return false 
   */
  virtual bool setChipSelect(uint32_t cs) abstract;

  /**
   * @brief Get the Chip Select object
   * 
   * @return uint32_t 
   */
  virtual uint32_t getChipSelect(void) abstract;

  /**
   * @brief Set the Bit First object
   * 
   * @param config 
   * @return true 
   * @return false 
   */
  virtual bool setBitFirst(bool config) abstract;

  /**
   * @brief Get the Bit First object
   * 
   * @return true 
   * @return false 
   */
  virtual bool getBitFirst(void) abstract;

  /**
   * @brief Set the Mode object
   * 
   * @param mode 
   * @return true 
   * @return false 
   */
  virtual bool setMode(uint8_t mode) abstract;

  /**
   * @brief Get the Mode object
   * 
   * @return uint8_t 
   */
  virtual uint8_t getMode(void) abstract;

  /**
   * @brief Set the Event Transfer object
   * 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool setEventTransfer(void* attachment, uint32_t (*event)(void*)) abstract;

  /**
   * @brief Set the Event Receiver object
   * 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool setEventReceiver(void* attachment, void (*event)(void* ,uint16_t)) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isTrnasferEnable(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isReceiverEnable(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_BA926446_3C77_4E61_B57D_D08B73D10E28 */
