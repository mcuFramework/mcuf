/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BE3E4DBC_AECB_44D9_B32A_7170E9B82E69
#define MCUF_BE3E4DBC_AECB_44D9_B32A_7170E9B82E69

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf\Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface TemperatureSensor;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::TemperatureSensor extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Celsius object
   * 
   * @return float 
   */
  virtual float getCelsius(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_BE3E4DBC_AECB_44D9_B32A_7170E9B82E69 */
