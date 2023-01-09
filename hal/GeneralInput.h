/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_9C655B34_D715_4F1E_957C_F1BFB3213FB8
#define MCUF_9C655B34_D715_4F1E_957C_F1BFB3213FB8

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace hal{
  interface GeneralInput;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::GeneralInput extends virtual mcuf::Interface{
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Set io pin to high or low.
   * 
   * @param level false = low, true = high.
   */
  virtual void value(bool level) abstract; 

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_9C655B34_D715_4F1E_957C_F1BFB3213FB8 */
