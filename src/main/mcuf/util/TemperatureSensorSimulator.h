/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_9CBF1345_9D97_4C6C_A466_2EF635815DB4
#define MCUF_9CBF1345_9D97_4C6C_A466_2EF635815DB4

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Object.h"
#include "mcuf/util/TemperatureSensor.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class TemperatureSensorSimulator;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::util::TemperatureSensorSimulator extends mcuf::lang::Object implements
public mcuf::util::TemperatureSensor{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:
    float mValue;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 
    /**
     * @brief Construct a new Temperature Sensor Simulator object
     * 
     */
    TemperatureSensorSimulator(void);

    /**
     * @brief Construct a new Temperature Sensor Simulator object
     * 
     * @param value 
     */
    TemperatureSensorSimulator(float value);

    /**
     * @brief Destroy the Temperature Sensor Simulator object
     * 
     */
    virtual ~TemperatureSensorSimulator(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::util::TemperatureSensor
   */
  public:
    /**
     * @brief Get the Celsius object
     * 
     * @return float 
     */
    virtual float getCelsius(void) override;

  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief Get the Celsius object
     * 
     * @return float 
     */
    virtual float setCelsius(float value);
    
  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_9CBF1345_9D97_4C6C_A466_2EF635815DB4 */
