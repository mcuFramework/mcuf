/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D
#define MCUF_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace lang{
    interface Interface;
    class Object;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Destroy the Interface object
   * 
   */
  virtual ~Interface(void) = default;
  
  /**
   * @brief 
   * 
   * @param milliseconds 
   */
  virtual void delay(int milliseconds) const abstract;

  /**
   * @brief 
   * 
   * @param object 
   * @return true 
   * @return false 
   */
  virtual bool equal(Object* object) const abstract;

  /**
   * @brief 
   * 
   * @param object 
   * @return true 
   * @return false 
   */
  virtual bool equal(Object& object) const abstract;

  /**
   * @brief 
   * 
   */
  virtual void finalize(void) abstract;

  /**
   * @brief 
   * 
   */
  virtual void wait(void) const abstract;

  /**
   * @brief 
   * 
   * @param timeout 
   * @return true 
   * @return false 
   */
  virtual bool wait(int timeout) const abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool yield(void) const abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool systemLock(void) const abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool systemUnlock(void) const abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D */
