/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/**
 * Copyright (C) CHEN-YO TECHNOLOGY CO., LTD. - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Danny <danny_chang@chenyo-tech.com.tw>, August 2021
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
void* const mcufCoreThreadMemory = mcufCoreThreadMemoryEntity;
const uint32_t mcufCoreThreadMemorySize = sizeof(mcufCoreThreadMemoryEntity);

static uint64_t mcufCoreStackMemoryEntity[MCUF_DEFINE_CORE_STACK_SIZE/8];
void* const mcufCoreStackMemory = mcufCoreStackMemoryEntity;
const uint32_t mcufCoreStackMemorySize = sizeof(mcufCoreStackMemoryEntity);

static uint32_t mcufCoreEcecutorMemoryEntity[MCUF_DEFINE_EXECUTOR_TASK_NUMBER];
void* const mcufCoreEcecutorMemory = mcufCoreEcecutorMemoryEntity;
const uint32_t mcufCoreEcecutorMemorySize = sizeof(mcufCoreEcecutorMemoryEntity);

static uint32_t mcufTimerTaskMemoryEntity[MCUF_DEFINE_TIMER_TASK_NUMBER + ((MCUF_DEFINE_TIMER_TASK_NUMBER+31)/32)];
void* const mcufTimerTaskMemory = mcufTimerTaskMemoryEntity;
const uint32_t mcufTimerTaskMemorySize = sizeof(mcufTimerTaskMemoryEntity);
const uint32_t mcufTimerTick = MCUF_DEFINE_TIMER_TICK;


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