/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_403B488E_9F14_4C90_B5ED_6306A951D341
#define MCUF_403B488E_9F14_4C90_B5ED_6306A951D341

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace util{
    interface CommandLineHandler;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::util::CommandLineHandler{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief Get the Command object
   * 
   * @return const char* 
   */
  virtual const char* getCommand(void) const abstract;

  /**
   * @brief Construct a new execute object
   * 
   * @param args 
   * @param length 
   */
  virtual execute(const char* args[], int length) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_403B488E_9F14_4C90_B5ED_6306A951D341 */
