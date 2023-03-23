/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_739FA0D6_740F_4CA0_975C_FD713D983D41
#define MCUF_739FA0D6_740F_4CA0_975C_FD713D983D41

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Interface.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface OutputBuffer;
  interface InputBuffer;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mcuf::OutputBuffer :public virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 輸出緩存是否為空?
   * 
   * @return true 輸出緩存為空
   * @return false 輸出緩存不為空
   */
  virtual bool isEmpty(void) const abstract;

  /**
   * @brief 取得輸出緩存內剩餘多少位元組
   * 
   * @return int 緩存內有效位元組數量
   */
  virtual int avariable(void) const abstract;

  /**
   * @brief 輸出一個位元組
   * 
   * @param result 
   * @return true 輸出成功
   * @return false 緩存內為空
   */
  virtual bool getByte(char& result) abstract;

  /**
   * @brief 輸出至InputBuffer
   * 
   * @param inputBuffer 輸出目標緩存空間 
   * @return int 輸出至目標的位元組數量
   */
  virtual int get(mcuf::InputBuffer& inputBuffer) abstract;

  /**
   * @brief 輸出至InputBuffer
   * 
   * @param inputBuffer 輸出目標緩存空間
   * @param length 指定最大輸出位元組數量
   * @return int 輸出至目標的位元組數量
   */
  virtual int get(mcuf::InputBuffer& inputBuffer, int length) abstract;

  /**
   * @brief 輸出目標緩存空間
   * 
   * @param buffer 緩衝區地址
   * @param bufferSize 緩衝區大小
   * @return int 複製的位元組數量
   */
  virtual int get(void* buffer, int bufferSize) abstract;

  /**
   * @brief 跳躍數個緩衝區內位元組
   * 
   * @param value 期望跳躍數量
   * @return int 實際跳躍數量
   */
  virtual int skip(int value) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_739FA0D6_740F_4CA0_975C_FD713D983D41 */
