/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_68E08971_6DB0_4724_A5F9_B11D8FDC7B5B
#define MCUF_68E08971_6DB0_4724_A5F9_B11D8FDC7B5B

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./Object.h"

//-----------------------------------------------------------------------------------------
#include "./hal/AnalogInputPin.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class Voltmeter;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::Voltmeter extends mcuf::Object{

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
    mcuf::hal::AnalogInputPin& mAnalogPin;
    float mVoltageMin;
    float mVoltageMax;
    float mVoltageDelta;

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
     * @brief Construct a new Voltmeter object
     * 
     * @param analogPin 
     * @param voltmeterMin 
     * @param voltmeterMax 
     */
    Voltmeter(mcuf::hal::AnalogInputPin& analogPin, float voltmeterMin, float voltmeterMax);

    /**
     * @brief Destroy the Voltmeter object
     * 
     */
    virtual ~Voltmeter(void) override;

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
    float voltage(void);

    /**
     * @brief 
     * 
     * @return float 
     */
    float voltageMax(void);

    /**
     * @brief 
     * 
     * @param value 
     */
    void voltageMax(float value);

    /**
     * @brief 
     * 
     * @return float 
     */
    float voltageMin(void);

    /**
     * @brief 
     * 
     * @param value 
     */
    void voltageMin(float value);    

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

#endif /* MCUF_68E08971_6DB0_4724_A5F9_B11D8FDC7B5B */
