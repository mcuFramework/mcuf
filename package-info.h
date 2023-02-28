/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_C3897905_8196_4807_BA5F_3ABC7022A420
#define MCUF_C3897905_8196_4807_BA5F_3ABC7022A420

/* ****************************************************************************************
 * Include folder
 */
#include "./macro/package-info.h"
#include "./mcuf/package-info.h" 
#include "./hal/package-info.h"
#include "./rtos/package-info.h"

/* ****************************************************************************************
 * Include
 */

/* ****************************************************************************************
 * Reference
 */

/**
 * Module macro
 */
#ifndef MODULE_VER_MACRO
#error "module macro version not found"
#endif
#define VERSION_STATUS_CACHE VERSION_CHECK(MODULE_VER_MACRO, 1, 0, 0)
#if VERSION_STATUS_CACHE != VERSION_PASS
  #if VERSION_STATUS_CACHE == VERSION_WARN
  	#warning "module macro reversion below request"
  #else
  	#error "module macro miner to low or majer not match"
  #endif
#endif
#undef VERSION_STATUS_CACHE

/* ****************************************************************************************
 * Version
 */
#define MODULE_VER_MCUF VERSION_DEFINE(0, 1, 2)


/* ****************************************************************************************
 * Version check
 */
/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_C3897905_8196_4807_BA5F_3ABC7022A420 */
