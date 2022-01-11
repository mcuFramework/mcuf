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
 
#define abstract =0
#define abstracts 
#define construct :
#define extends :public
#define implements ,public
#define implement :public  
#define interface struct

#ifndef VACCESS
#define VACCESS(type, target) (*(volatile type *) &(target))
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
