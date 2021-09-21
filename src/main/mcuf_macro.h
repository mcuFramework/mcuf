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

#ifndef VACCESS
#define VACCESS(type, target) (*(volatile type *) &(target))
  
#endif

#ifndef MESSAGE_OUT_OF_ENUM
#define MESSAGE_OUT_OF_ENUM "Out of enum."
#endif

#ifndef MESSAGE_OUT_OF_MEMORY
#define MESSAGE_OUT_OF_MEMORY "Out of memory."
#endif

#ifndef MESSAGE_OUT_OF_RANGE
#define MESSAGE_OUT_OF_RANGE "Out of range."
#endif

#ifndef MESSAGE_NULL_POINTER
#define MESSAGE_NULL_POINTER "Null pointer."
#endif

#ifdef MCUF_DEBUG
  #define INFO(message) mcuf::lang::System::info(__PRETTY_FUNCTION__, message)
  #define THROW_ERROR(message) mcuf::lang::System::throwSystemError(__PRETTY_FUNCTION__, message)
  #define THROW_WARNING(message) mcuf::lang::System::throwSystemWarning(__PRETTY_FUNCTION__, message)
  #define ASSERT_THROW_ERROR(expr, message) if(!(expr)) THROW_ERROR(message)
  #define ASSERT_THROW_WARNING(expr, message) if(!(expr)) THROW_WARNING(message)
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


#endif /* MCUF_AT32F415_D9A3210A_778E_466F_BA3E_7A53ACD9064E */
