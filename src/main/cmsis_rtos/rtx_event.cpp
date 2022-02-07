/*
 * Copyright (c) 2013-2018 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * -----------------------------------------------------------------------------
 *
 * $Revision:   V5.1.0
 *
 * Project:     CMSIS-RTOS RTX
 * Title:       RTX Configuration
 *
 * -----------------------------------------------------------------------------
 */
 
#include "cmsis_compiler.h"
#include "rtx_os.h"
#include "mcuf.h"

using mcuf::lang::ErrorCode;
using mcuf::lang::System;

uint32_t osRtxIdleThreadCount = 0;

// OS Idle Thread
extern "C" __WEAK __NO_RETURN void osRtxIdleThread (void *argument) {
  (void)argument;

  for (;;) {
    ++osRtxIdleThreadCount;
  }
}
 
// OS Error Callback function
extern "C" __WEAK uint32_t osRtxErrorNotify (uint32_t code, void *object_id) {
  (void)object_id;

  switch (code) {
    case osRtxErrorStackUnderflow:
      System::error(object_id, ErrorCode::RTX_STACK_UNDERFLOW);
      // Stack overflow detected for thread (thread_id=object_id)
      break;
    
    case osRtxErrorISRQueueOverflow:
      System::error(object_id, ErrorCode::RTX_ISR_QUEUE_OVERFLOW);
      // ISR Queue overflow detected when inserting object (object_id)
      break;
    
    case osRtxErrorTimerQueueOverflow:
      System::error(object_id, ErrorCode::RTX_TIMER_QUEUE_OVERFLOW);
      // User Timer Callback Queue overflow detected for timer (timer_id=object_id)
      break;
    
    case osRtxErrorClibSpace:
      System::error(object_id, ErrorCode::RTX_CLIB_SPACE);
      // Standard C/C++ library libspace not available: increase OS_THREAD_LIBSPACE_NUM
      break;
    
    case osRtxErrorClibMutex:
      System::error(object_id, ErrorCode::RTX_CLIB_MUTEX);
      // Standard C/C++ library mutex initialization failed
      break;
    
    default:
      // Reserved
      System::error(object_id, ErrorCode::HARD_FAULT);
      break;
  }
  for (;;) {}
//return 0U;
}
