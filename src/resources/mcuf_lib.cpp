/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "stdint.h"
#include "mcuf_config.h"
#include "mcuf.h"
 
/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Extern
 */

/* ****************************************************************************************
 * Struct
 */

/* ****************************************************************************************
 * Static Variable
 */
 
/* ****************************************************************************************
 * Variable
 */

static uint64_t mcufCoreThreadMemoryEntity[(sizeof(mcuf::lang::managerment::CoreThread) + 7) / 8];
void* mcufCoreThreadMemory = mcufCoreThreadMemoryEntity;
uint32_t mcufCoreThreadMemorySize = sizeof(mcufCoreThreadMemoryEntity);

static uint64_t mcufCoreStackMemoryEntity[MCUF_DEFINE_CORE_STACK_SIZE/8];
void* mcufCoreStackMemory = mcufCoreStackMemoryEntity;
uint32_t mcufCoreStackMemorySize = sizeof(mcufCoreStackMemoryEntity);

static uint32_t mcufCoreEcecutorMemoryEntity[MCUF_DEFINE_EXECUTOR_TASK_NUMBER];
void* mcufCoreEcecutorMemory = mcufCoreEcecutorMemoryEntity;
uint32_t mcufCoreEcecutorMemorySize = sizeof(mcufCoreEcecutorMemoryEntity);

/* ****************************************************************************************
 * List
 */
 
/**
 * Inline function list
 */
 
/**
 * Static function list
 */

/* ****************************************************************************************
 * Inline Function
 */

/* ****************************************************************************************
 * Static Function
 */

/* ****************************************************************************************
 * Function
 */
 
/* ****************************************************************************************
 * End of file
 */ 
