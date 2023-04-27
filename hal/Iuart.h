/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_45E407BD_9AB0_4D35_81C0_365F86A5FFAE
#define MCUF_45E407BD_9AB0_4D35_81C0_365F86A5FFAE

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
  interface Iuart;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::Iuart extends hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 啟動傳送
   * 
   * @return true 啟動成功
   * @return false 啟動失敗，可能已經啟動
   */
  virtual bool transferEnable(void) abstract;
  
  /**
   * @brief 啟動接收
   * 
   * @return true 啟動成功
   * @return false 啟動失敗，可能已經啟動
   */
  virtual bool receiverEnable(void) abstract;
  
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

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t getBaudrate(void) abstract;

  /**
   * @brief Set the Baudrate object
   * 
   * @param baudrate 期望的輸出鮑率
   * @return uint32_t 實際的輸出鮑率
   */
  virtual uint32_t setBaudrate(uint32_t baudrate) abstract;
  
  /**
   * @brief Set the Receiver Event object
   * 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool setReceiverEvent(void* attachment, void(*event)(void*, uint8_t)) abstract;
  
  /**
   * @brief 
   * 
   * @param out 
   * @return true 傳送數值
   * @return false 停止傳送並關閉
   */
  virtual bool setTransferEvent(void* attachment, uint16_t(*event)(void*)) abstract;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_45E407BD_9AB0_4D35_81C0_365F86A5FFAE */
