/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6
#define MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"
#include "../mcuf/ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "./SerialPeriphMode.h"
#include "./SerialPeriphEvent.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  interface SerialPeriph;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::SerialPeriph extends hal::Base{
  /* **************************************************************************************
   * Method Get/Set
   */
  
  /**
   * @brief Get the Clock object
   * 
   * @return uint32_t 
   */
  virtual uint32_t getClock(void) abstract;

  /**
   * @brief Set the Clock object
   * 
   * @param clock 
   * @return uint32_t 
   */
  virtual uint32_t setClock(uint32_t clock) abstract;

  /**
   * @brief Get the Mode object
   * 
   * @return hal::SerialPeriphMode 
   */
  virtual hal::SerialPeriphMode getMode(void) abstract;

  /**
   * @brief Set the Mode object
   * 
   * @param mode 
   * @return hal::SerialPeriphMode 
   */
  virtual hal::SerialPeriphMode setMode(hal::SerialPeriphMode mode) abstract;  

  /**
   * @brief Get the Read Buffer object
   * 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* getReadBuffer(void) abstract;

  /**
   * @brief Set the Read Buffer object
   * 
   * @param byteBuffer 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* setReadBuffer(mcuf::ByteBuffer* byteBuffer) abstract;

  /**
   * @brief Get the Write Buffer object
   * 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* getWriteBuffer(void) abstract;

  /**
   * @brief Set the Write Buffer object
   * 
   * @param byteBuffer 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* setWriteBuffer(mcuf::ByteBuffer* byteBuffer) abstract;

  /* **************************************************************************************
   * Method Get/Set
   */

  /**
   * @brief 取消讀取
   * 
   * @return true 取消成功
   * @return false 取消失敗
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
   * @param chipSelect 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool transfer(uint32_t chipSelect, hal::SerialPeriphEvent* event) abstract;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6 */
