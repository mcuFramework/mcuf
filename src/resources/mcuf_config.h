/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B4D7504F_54A9_496C_92BF_849CCCA491C0
#define MCUF_B4D7504F_54A9_496C_92BF_849CCCA491C0

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h>Core
// =======================

//   <o>Stack size [Byte] <256-65536:8>
#ifndef MCUF_DEFINE_CORE_STACK_SIZE
#define MCUF_DEFINE_CORE_STACK_SIZE 1024
#endif

//   <o>Executor task number <4-1024>
#ifndef MCUF_DEFINE_EXECUTOR_TASK_NUMBER
#define MCUF_DEFINE_EXECUTOR_TASK_NUMBER 16
#endif
// </h>

// <h>Tick
// =======================

//   <o>System tick base time [ms] <5-1000:8>
#ifndef MCUF_DEFINE_TICK_BASE_TIME
#define MCUF_DEFINE_TICK_BASE_TIME 50
#endif

//   <o>System tick task number <4-1024>
#ifndef MCUF_DEFINE_TICK_TASK_NUMBER
#define MCUF_DEFINE_TICK_TASK_NUMBER 16
#endif
// </h>

//------------- <<< end of configuration section >>> ---------------------------


/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B4D7504F_54A9_496C_92BF_849CCCA491C0 */
