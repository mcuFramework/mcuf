/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MACRO_525E4881_CEEE_4334_877B_A902825D94EA
#define MACRO_525E4881_CEEE_4334_877B_A902825D94EA

/* ****************************************************************************************
 * Include
 */

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Macro
 */
 
#define VERSION_DEFINE(major, minor, reversion) \
  (((major     & 0x000000FF) << 24) |   \
   ((minor     & 0x000000FF) << 16) |    \
   ((reversion & 0x000000FF) <<  0))

#define VERSION_GET_MAJOR(major)         ((major >> 24) & 0x000000FF)
#define VERSION_GET_MINOR(minor)         ((minor >> 16) & 0x000000FF)
#define VERSION_GET_REVERSION(reversion) (reversion & 0x000000FF)

#define VERSION_ERROR 2
#define VERSION_WARN 1
#define VERSION_PASS 0

#define VERSION_CHECK_MAJOR(ver, major)                ((VERSION_GET_MAJOR(ver) == major)?VERSION_PASS:VERSION_ERROR)
#define VERSION_CHECK_MINER(ver, minor, reversion)     (((ver & 0x00FFFFFF) > VERSION_DEFINE(0, minor, reversion))?VERSION_PASS:VERSION_ERROR)

#define VERSION_CHECK_REVERSION(ver, minor, reversion) ((VERSION_GET_MINOR(ver) == minor)?                                     \
													                              ((VERSION_GET_REVERSION(ver) >= reversion)?VERSION_PASS:VERSION_WARN): \
													                              ((VERSION_GET_MINOR(ver) < minor)?VERSION_ERROR:VERSION_PASS))  


#define VERSION_CHECK_SIZE(ver, major, minor, reversion) ((VERSION_CHECK_MINER(ver, minor, reversion) != VERSION_PASS)? \
                                                           VERSION_CHECK_REVERSION(ver, minor, reversion):\
														                               VERSION_PASS)

#define VERSION_CHECK(ver, major, minor, reversion)   ((VERSION_CHECK_MAJOR(ver, major) == VERSION_PASS)?\
                                                        VERSION_CHECK_SIZE(ver, major, minor, reversion):\
														                            VERSION_ERROR)
/* *****************************************************************************************
 * End of file
 */ 

#endif /* MACRO_525E4881_CEEE_4334_877B_A902825D94EA */
