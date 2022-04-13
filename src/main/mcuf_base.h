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

#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#pragma clang diagnostic ignored "-Wdeprecated-copy-dtor"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc++17-extensions"


#define abstract =0
#define extends :public
#define implements ,
#define interface struct

#ifndef VACCESS
#define VACCESS(type, target) (*static_cast<volatile type*>(&target))
#endif

#ifndef ALIGN32BIT
#define ALIGN32BIT(source) if(source&0x3){source = (source & 0xFFFFFFF8) + 4;}
#endif

#ifndef ALIGN64BIT
#define ALIGN64BIT(source) if(source&0x7){source = (source & 0xFFFFFFF8) + 8;}
#endif

#ifdef DEBUG
  #ifndef __CLASSPATH__
  #define __CLASSPATH__ __PRETTY_FUNCTION__
  #endif

  #ifndef ASSERT
  #define ASSERT(expr, m, e) if(!expr) mcuf::lang::System::error(m, e)
  #endif
#else  
  #ifndef __CLASSPATH__
  #define __CLASSPATH__ nullptr
  #endif

  #ifndef ASSERT
  #define ASSERT(expr, m, e) ((void)0)
  #endif
#endif

/* ****************************************************************************************
 * Include
 */
#include <stdint.h>

/* ****************************************************************************************
 * Include folder
 */

/* *****************************************************************************************
 * End of file
 */ 


#endif /* MCUF_AT32F415_D9A3210A_778E_466F_BA3E_7A53ACD9064E */
