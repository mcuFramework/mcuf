/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_5D254320_94DB_4B27_879F_9BDACF1C3A0E
#define MCUF_5D254320_94DB_4B27_879F_9BDACF1C3A0E

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "hal/analog/AnalogInputPin.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class VirtualAnalogInputPin;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::util::VirtualAnalogInputPin extends mcuf::lang::Object implements
public hal::analog::AnalogInputPin{

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
    uint32_t mLevel;
    uint32_t mValue;

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
     * @brief Construct a new Virtual Analog Input Pin object
     * 
     */
    VirtualAnalogInputPin(void);

    /**
     * @brief Destroy the Virtual Analog Input Pin object
     * 
     */
    virtual ~VirtualAnalogInputPin(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - hal::analog::AnalogInputPin
   */
  public:
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t convert(void) override;

    /**
     * @brief Get the adc convert level.
     * 
     * @return uint32_t 
     */
    virtual uint32_t getConvertLevel(void) override;

  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief Set the Value object
     * 
     * @param value 
     */
    virtual void setValue(uint32_t value);

    /**
     * @brief Set the Convert Level object
     * 
     * @param level 
     */
    virtual void setConvertLevel(uint32_t level);

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

#endif /* MCUF_5D254320_94DB_4B27_879F_9BDACF1C3A0E */
