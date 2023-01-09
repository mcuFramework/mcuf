/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B08DB2A3_7AA4_4166_A88E_E997AA2B0BAD
#define MCUF_B08DB2A3_7AA4_4166_A88E_E997AA2B0BAD


/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf\Interface.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  interface Closeable;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::Closeable extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   */
  virtual void close(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isOpen(void) abstract;  

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B08DB2A3_7AA4_4166_A88E_E997AA2B0BAD */
