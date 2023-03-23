/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_A640D444_DED9_463A_8F4A_E407A682DBAC
#define MCUF_A640D444_DED9_463A_8F4A_E407A682DBAC

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
  interface Allocator;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::Allocator extends virtual mcuf::Interface{
  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param size 
   */
  virtual void* alloc(uint32_t size) abstract;

  /**
   * @brief 
   * 
   * @param ptr 
   * @return true 
   * @return false 
   */
  virtual bool free(void* ptr) abstract;

  /**
   * @brief 
   * 
   * @param ptr 
   * @param size 
   * @return true 
   * @return false 
   */
  virtual bool free(void* ptr, uint32_t size) abstract;  
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A640D444_DED9_463A_8F4A_E407A682DBAC */
