#ifndef MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164
#define MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface GeneralPurposePin;
  }
}

/* ****************************************************************************************
 * Class GeneralPurposeIO::Pin
 */  
interface mcuf::hal::GeneralPurposePin{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Enum PinMode
   */
  enum PinMode{
    PinMode_NotSupport,
    PinMode_PushPull,
    PinMode_Pullup,
    PinMode_Pulldown,
    PinMode_opendrain,
  };
   
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */
  
  /**
   * Get io direction.
   * 
   * @return false = input, true = output.
   */
  virtual bool dir(void) abstract;

  /**
   * Set io direction.
   * 
   * @param dir false = input, true = output.
   */
  virtual void dir(bool dir) abstract;
  
  /**
   * 
   */
  virtual PinMode pinMode(void) abstract;

  /**
   * 
   */
  virtual bool pinMode(PinMode mode) abstract; 

  /**
   * Set io pin to high.
   */
  virtual void setHigh(void) abstract;
  
  /**
   * Set io direction to input.
   */
  virtual void setInput(void) abstract;

  /**
   * Set io pin to low.
   */
  virtual void setLow(void) abstract;
  
  /**
   * Set io direction to output.
   */
  virtual void setOutput(void) abstract;

  /**
   * Set io not logic.
   */
  virtual void setToggle(void) abstract;

  /**
   * Get io pin.
   *
   * @return false = low, true = high.
   */
  virtual bool value(void) abstract;

  /**
   * Set io pin to high or low.
   *
   * @param value false = low, true = high.
   */
  virtual void value(bool level) abstract;  

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

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


#endif/* MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164 */
