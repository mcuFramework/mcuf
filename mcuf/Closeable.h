/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B08DB2A3_7AA4_4166_A88E_E997AA2B0BAD
#define MCUF_B08DB2A3_7AA4_4166_A88E_E997AA2B0BAD


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
  interface Closeable;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::Closeable extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 關閉通道
   * 
   */
  virtual void close(void) abstract;

  /**
   * @brief 通道是否被開啟
   * 
   * @return true 通道是開啟的
   * @return false 通道是關閉的
   */
  virtual bool isOpen(void) abstract;  

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B08DB2A3_7AA4_4166_A88E_E997AA2B0BAD */
