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

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"
#include "./SerialBusEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  interface SerialBus;
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface hal::SerialBus extends hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 終止讀寫
   * 
   * @return true 終止成功
   * @return false 終止失敗
   */
  virtual bool abort(void) abstract;
  
 /**
   * @brief 取得輸出頻率
   * 
   * @return uint32_t Hz
   */
  virtual uint32_t getClockRate(void) abstract;

  /**
   * @brief 設定輸出頻率
   * 
   * @param clock 期望輸出頻率
   * @return uint32_t Hz，實際設定頻率
   */
  virtual uint32_t setClockRate(uint32_t clock) abstract;

  /**
   * @brief 設定讀寫地址
   * 
   * @param address 讀寫地址
   * @return uint16_t 實際設定之讀寫地址
   */
  virtual uint16_t setAddress(uint16_t address) abstract;

  /**
   * @brief 取得已被設定之讀寫地址
   * 
   * @return uint16_t 地址
   */
  virtual uint16_t getAddress(void) abstract;
  
  /**
   * @brief Set the Write Buffer object
   * 
   * @param writeBuffer 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* setWriteBuffer(mcuf::ByteBuffer* writeBuffer) abstract;

  /**
   * @brief Get the Write Buffer object
   * 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* getWriteBuffer(void) abstract;

  /**
   * @brief Set the Read Buffer object
   * 
   * @param readBuffer 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* setReadBuffer(mcuf::ByteBuffer* readBuffer) abstract;

  /**
   * @brief Get the Read Buffer object
   * 
   * @return mcuf::ByteBuffer* 
   */
  virtual mcuf::ByteBuffer* getReadBuffer(void) abstract;

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
  virtual bool read(hal::SerialBusEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param address 
   * @param out 
   * @param event 
   */
  virtual bool write(hal::SerialBusEvent* event) abstract;
  
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
  virtual bool transfer(hal::SerialBusEvent* event) abstract;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
