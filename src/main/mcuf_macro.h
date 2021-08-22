/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D9A3210A_778E_466F_BA3E_7A53ACD9064E
#define MCUF_D9A3210A_778E_466F_BA3E_7A53ACD9064E

/* ****************************************************************************************
 * Macro
 */

#define MCUF_DEBUG

#ifdef MCUF_DEBUG
  #define INFO(message) mcuf::lang::System::info(__PRETTY_FUNCTION__, message)
  #define THROW_ERROR(message) mcuf::lang::System::throwSystemError(__PRETTY_FUNCTION__, message)
  #define THROW_WARNING(message) mcuf::lang::System::throwSystemWarning(__PRETTY_FUNCTION__, message)
  #define ASSERT_THROW_ERROR(expr, message) if(!expr) THROW_ERROR(message)
  #define ASSERT_THROW_WARNING(expr, message) if(!expr) THROW_WARNING(message)
#else
  #ifdef MCUF_DEBUG_NMSG
    #define INFO(message)
    #define THROW_ERROR(message) while(1)
    #define THROW_WARNING(message)
    #define ASSERT_THROW_ERROR(expr, message) if(!expr) THROW_ERROR(message)
    #define ASSERT_THROW_WARNING(expr, message)
  #else
    #define INFO(message)
    #define THROW_ERROR(message)
    #define THROW_WARNING(message)
    #define ASSERT_THROW_ERROR(expr, message)
    #define ASSERT_THROW_WARNING(expr, message)
  #endif
#endif

/* ****************************************************************************************
 * Include
 */

/* ****************************************************************************************
 * Include folder
 */

/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_AT32F415_D9A3210A_778E_466F_BA3E_7A53ACD9064E */
