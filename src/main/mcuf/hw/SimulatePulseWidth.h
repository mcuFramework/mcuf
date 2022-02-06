/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BEA5AEC6_7F37_4CCC_B41F_47A23CE2CE85
#define MCUF_BEA5AEC6_7F37_4CCC_B41F_47A23CE2CE85


/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.h"
#include "mcuf/util/TimerTask.h"
#include "mcuf/hal/GeneralPinControl.h"
#include "mcuf/hal/PulseWidth.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hw{
    class SimulatePulseWidth;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::hw::SimulatePulseWidth extends mcuf::util::TimerTask implements 
  public mcuf::hal::PulseWidthConfig,
  public mcuf::hal::PulseWidthControl{

  /* **************************************************************************************
   * Subclass
   */

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
    mcuf::hal::GeneralPinControl* mPin;
    uint32_t mMinnisecondBase;
    uint32_t mMinnisecondChange;
    bool mStats;

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
     * @brief Construct a new Simulate Pulse Width object
     * 
     * @param pin 
     */
    SimulatePulseWidth(mcuf::hal::GeneralPinControl* pin);

  public:

    /**
     * @brief Destroy the Simulate Pulse Width object
     * 
     */
    ~SimulatePulseWidth(void);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::util::TimerTask
   */
  public:

    /**
     * @brief 
     * 
     */
    virtual void run(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::hal::PulseWidthConfig
   */
  public: 

    /**
     * @brief Set the Frequence object
     * 
     * @param hz 
     * @return true 
     * @return false 
     */
    virtual bool setBaseFrequence(uint32_t hz) override;

    /**
     * @brief Set the Base Second object
     * 
     * @param second 
     * @return true 
     * @return false 
     */
    virtual bool setBaseSecond(float second) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::hal::PulseWidthControl
   */
  public:   
    /**
     * @brief Set the Duty object
     * 
     * @param percent 
     * @return true 
     * @return false 
     */
    virtual bool setDuty(float percent) override;
     
    /**
     * @brief Set the Duty8 Bit object
     * 
     * @param duty 
     * @return true 
     * @return false 
     */
    virtual bool setDuty8Bit(uint8_t duty) override;

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool stop(void) override;  
  
  /* **************************************************************************************
   * Public Method
   */

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

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_BEA5AEC6_7F37_4CCC_B41F_47A23CE2CE85 */
