/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_9E61DE90_7223_4EE7_BB33_FE3C45509F28
#define MCUF_9E61DE90_7223_4EE7_BB33_FE3C45509F28

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/lang/Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  interface InterruptEvent;
}



/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::InterruptEvent extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void interruptEvent(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_9E61DE90_7223_4EE7_BB33_FE3C45509F28 */
