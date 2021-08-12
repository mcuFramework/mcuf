/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D46FF4AF_578F_427C_B2BC_D33963AD1C03
#define MCUF_D46FF4AF_578F_427C_B2BC_D33963AD1C03

/* ****************************************************************************************
 * Macro
 */

#ifdef DEBUG
  #define THROW_ERROR(message) mcuf::lang::System::throwSystemError(__PRETTY_FUNCTION__, message)
  #define THROW_WARNING(message) mcuf::lang::System::throwSystemWarning(__PRETTY_FUNCTION__, message)
#else
  #ifdef DEBUG_NMSG
    #define THROW_ERROR(message) while(1)
    #define THROW_WARNING(message)
  #else
    #define THROW_ERROR(message)
    #define THROW_WARNING(message)
  #endif
#endif



/* ****************************************************************************************
 * Include
 */



/* ****************************************************************************************
 * Include folder
 */
#include "mcuf\mcuf.h"






/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_D46FF4AF_578F_427C_B2BC_D33963AD1C03 */
