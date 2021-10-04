/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C0668BC1_9B68_4DC9_BE82_B998B6CD7B53
#define MCUF_C0668BC1_9B68_4DC9_BE82_B998B6CD7B53

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h>System
// =======================

//   <o>System stack size [Byte] <256-65536>
#ifndef MCUF_DEFINE_SYSTEM_THREAD_STACK_SIZE
#define MCUF_DEFINE_SYSTEM_THREAD_STACK_SIZE 1024
#endif

//   <o>String format cache [Byte] <256-65536>
#ifndef MCUF_DEFINE_SYSTEM_STRING_SIZE
#define MCUF_DEFINE_SYSTEM_STRING_SIZE 1024
#endif

//   <e>Executor
//   <i> Enables Executor.
#ifndef MCUF_DEFINE_EXECUTOR_ENABLE
#define MCUF_DEFINE_EXECUTOR_ENABLE 1
#endif

//   <o>Stack size [Byte] <256-65536>
#ifndef MCUF_DEFINE_EXECUTOR_STACK_SIZE
#define MCUF_DEFINE_EXECUTOR_STACK_SIZE 1024
#endif

//   <o>Task number [Byte] <16-65536>
#ifndef MCUF_DEFINE_EXECUTOR_TASK_NUMBER
#define MCUF_DEFINE_EXECUTOR_TASK_NUMBER 64
#endif
//   </e>

//   <e>Timer
//   <i> Enables Timer.
#ifndef MCUF_DEFINE_TIMER_ENABLE
#define MCUF_DEFINE_TIMER_ENABLE 1
#endif

//   <o>Task number [Byte] <16-65536>
#ifndef MCUF_DEFINE_TIMER_TASK_NUMBER
#define MCUF_DEFINE_TIMER_TASK_NUMBER 64
#endif
//   </e>


// </h>

// <h>Memory
// =======================

//   <e>MemoryManager
//   <i> Enables MemoryManager.
#ifndef MCUF_DEFINE_MEMORYMANAGER_ENABLE
#define MCUF_DEFINE_MEMORYMANAGER_ENABLE 1
#endif

//   <o>Size [kByte] <16-65536>
#ifndef MCUF_DEFINE_MEMORYMANAGER_SIZE
#define MCUF_DEFINE_MEMORYMANAGER_SIZE 16
#endif
//   </e>

// </h>


//------------- <<< end of configuration section >>> ---------------------------

#endif/* MCUF_C0668BC1_9B68_4DC9_BE82_B998B6CD7B53 */
