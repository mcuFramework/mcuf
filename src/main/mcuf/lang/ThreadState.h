/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_FF6FBB65_4795_467C_8D77_53255923274A
#define MCUF_FF6FBB65_4795_467C_8D77_53255923274A

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    enum struct ThreadState : int;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct mcuf::lang::ThreadState : int{
  INACTIVE        =  0,           ///< Inactive.
  READY           =  1,           ///< Ready.
  RUNNING         =  2,           ///< Running.
  BLOCKED         =  3,           ///< Blocked.
  TERMINATED      =  4,           ///< Terminated.
  ERROR           = -1,           ///< ErrorCode.
  RESERVED        = 0x7FFFFFFF    ///< Prevents enum down-size compiler optimization.
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_FF6FBB65_4795_467C_8D77_53255923274A */
