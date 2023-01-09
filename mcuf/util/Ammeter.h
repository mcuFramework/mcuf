/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_9791505C_A013_4AE8_9EF4_F082A616F700
#define MCUF_9791505C_A013_4AE8_9EF4_F082A616F700

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/util/Voltmeter.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class Ammeter;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::util::Ammeter extends mcuf::util::Voltmeter{

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
    float mAmperDelta;

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
     * @brief Construct a new Ammeter object
     * 
     * @param analogPin 
     * @param voltageMin 
     * @param voltageMax 
     * @param amperDelta 1V/Amper
     */
    Ammeter(hal::AnalogInputPin& analogPin, float voltageMin, float voltageMax, float amperDelta);

    /**
     * @brief Construct a new Ammeter object
     * 
     * @param voltmeter 
     * @param amperDelta 
     */
    Ammeter(const mcuf::util::Voltmeter& voltmeter, float amperDelta);

    /**
     * @brief Destroy the Ammeter object
     * 
     */
    virtual ~Ammeter(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief 
     * 
     * @return float 
     */
    float amper(void);

    /**
     * @brief 
     * 
     * @return float 
     */
    float amperDelta(void);

    /**
     * @brief 
     * 
     * @param value 
     */
    void amperDelta(float value);
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

#endif /* MCUF_9791505C_A013_4AE8_9EF4_F082A616F700 */
