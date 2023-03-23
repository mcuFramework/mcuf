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
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace cli{
  interface CommandLineHandler;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface cli::CommandLineHandler extends virtual mcuf::Interface{

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
   * @brief Get the Help object
   * 
   * @return const char* 
   */
  virtual const char* getHelp(void) const abstract;

  /**
   * @brief Construct a new execute object
   * 
   * @param args 
   * @param length 
   */
  virtual void execute(char* const args[], int length) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_403B488E_9F14_4C90_B5ED_6306A951D341 */
