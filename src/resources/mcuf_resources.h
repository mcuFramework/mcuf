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

//   <o>System stack size [byte] <256-65536>
#ifndef MCUF_DEFINE_SYSTEM_THREAD_STACK_SIZE
#define MCUF_DEFINE_SYSTEM_THREAD_STACK_SIZE 1024
#endif

//   <o>String format cache [byte] <256-65536>
#ifndef MCUF_DEFINE_SYSTEM_STRING_SIZE
#define MCUF_DEFINE_SYSTEM_STRING_SIZE 1024
#endif

//   <h>Executor
// =======================

//   <o>Stack size [byte] <256-65536>
#ifndef MCUF_DEFINE_EXECUTOR_STACK_SIZE
#define MCUF_DEFINE_EXECUTOR_STACK_SIZE 1024
#endif

//   <o>Task number [byte] <16-65536>
#ifndef MCUF_DEFINE_EXECUTOR_TASK_NUMBER
#define MCUF_DEFINE_EXECUTOR_TASK_NUMBER 64
#endif
//   </h>

//   <h>Timer

//   <o>Task number [byte] <16-65536>
#ifndef MCUF_DEFINE_TIMER_TASK_NUMBER
#define MCUF_DEFINE_TIMER_TASK_NUMBER 64
#endif
//   </h>


// </h>

// <h>Memory
// =======================

//   <h>MemoryManager

//   <o>Page size [byte]
//   <512=> 512 byte <1024=> 1 kbyte <2048=> 2 kbyte <4096=> 4 kbyte <8192=> 8 kbyte <16384=> 16 kbyte <32768=> 32 kbyte
#ifndef MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE
#define MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE 16384
#endif


//   <o>Page quantity <16-65536>
#ifndef MCUF_DEFINE_MEMORYMANAGER_PAGE_QUANTITY
#define MCUF_DEFINE_MEMORYMANAGER_PAGE_QUANTITY 16
#endif



//   </h>

// </h>


//------------- <<< end of configuration section >>> ---------------------------

#endif/* MCUF_C0668BC1_9B68_4DC9_BE82_B998B6CD7B53 */
