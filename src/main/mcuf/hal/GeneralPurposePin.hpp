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
  public: enum PinMode{
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
  public: virtual bool dir(void) = 0;

  /**
   * Set io direction.
   * 
   * @param dir false = input, true = output.
   */
  public: virtual void dir(bool dir) = 0;
  
  /**
   * 
   */
  public: virtual PinMode pinMode(void) = 0;

  /**
   * 
   */
  public: virtual bool pinMode(PinMode mode) = 0; 

  /**
   * Set io pin to high.
   */
  public: virtual void setHigh(void) = 0;
  
  /**
   * Set io direction to input.
   */
  public: virtual void setInput(void) = 0;

  /**
   * Set io pin to low.
   */
  public: virtual void setLow(void) = 0;
  
  /**
   * Set io direction to output.
   */
  public: virtual void setOutput(void) = 0;

  /**
   * Set io not logic.
   */
  public: virtual void setToggle(void) = 0;

  /**
   * Get io pin.
   *
   * @return false = low, true = high.
   */
  public: virtual bool value(void) = 0;

  /**
   * Set io pin to high or low.
   *
   * @param value false = low, true = high.
   */
  public: virtual void value(bool level) = 0;  

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: GeneralPurposePin(void) = default;
  
  /**
   * 
   */
  public: virtual ~GeneralPurposePin() = default;

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
