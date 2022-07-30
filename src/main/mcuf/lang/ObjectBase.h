/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B0EFE97E_F383_4FE8_AE4B_A7E2C331F56E
#define MCUF_B0EFE97E_F383_4FE8_AE4B_A7E2C331F56E

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
    interface ObjectBase;
    class Object;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::lang::ObjectBase{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Destroy the Object Base object
   * 
   */
  virtual ~ObjectBase(void) abstract;

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

#endif /* MCUF_B0EFE97E_F383_4FE8_AE4B_A7E2C331F56E */
