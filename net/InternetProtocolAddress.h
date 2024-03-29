/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_9CD16300_B15A_4988_BFCB_DA68322802ED
#define MCUF_9CD16300_B15A_4988_BFCB_DA68322802ED

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace net{
  class InternetProtocolAddress;
}



/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class net::InternetProtocolAddress extends mcuf::Object{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected:
    uint8_t mInternetProtocolAddress[4];
  
  /* **************************************************************************************
   * Variable <Private>
   */

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
     * @brief Construct a new Internet Protocol Address object
     * 
     */
    InternetProtocolAddress(void);

    /**
     * @brief Construct a new Internet Protocol Address object
     * 
     * @param address 
     */
    InternetProtocolAddress(const uint32_t address);

    /**
     * @brief Construct a new Internet Protocol Address object
     * 
     * @param a1 
     * @param a2 
     * @param a3 
     * @param a4 
     */
    InternetProtocolAddress(const uint8_t a1, const uint8_t a2, const uint8_t a3, const uint8_t a4);

    /**
     * @brief Construct a new Internet Protocol Address object
     * 
     * @param address 
     */
    InternetProtocolAddress(const uint8_t address[4]);

    /**
     * @brief Construct a new Internet Protocol Address object
     * 
     * @param address 
     */
    InternetProtocolAddress(const mcuf::Strings& address);

    /**
     * @brief Destroy the Internet Protocol Address object
     * 
     */
    virtual ~InternetProtocolAddress(void) override;

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
     * @brief Get the Address object
     * 
     * @return int 
     */
    virtual uint32_t getAddress(void) const;
  
    /**
     * @brief Get the Address object
     * 
     * @param a1 
     * @param a2 
     * @param a3 
     * @param a4 
     */
    virtual void getAddress(uint8_t& a1, uint8_t& a2, uint8_t& a3, uint8_t& a4) const;

    /**
     * @brief Get the Address object
     * 
     * @param result 
     */
    virtual void getAddress(uint8_t* result) const;
    
    /**
     * @brief Get the Address object
     * 
     * @param address 
     */
    virtual void getAddress(mcuf::Strings& result) const;
    
    /**
     * @brief Set the Address object
     * 
     * @param address 
     */
    virtual void setAddress(const uint32_t address);

    /**
     * @brief Set the Address object
     * 
     * @param a1 
     * @param a2 
     * @param a3 
     * @param a4 
     */
    virtual void setAddress(const uint8_t a1, const uint8_t a2, const uint8_t a3, const uint8_t a4);

    /**
     * @brief Set the Address object
     * 
     * @param address 
     */
    virtual void setAddress(const uint8_t address[4]);

    /**
     * @brief Set the Address object
     * 
     * @param address 
     */
    virtual void setAddress(const mcuf::Strings& address);

    /**
     * @brief 
     * 
     * @return mcuf::Strings 
     */
    virtual mcuf::Strings toStrings(void) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool isNull(void) const;

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

#endif /* MCUF_9CD16300_B15A_4988_BFCB_DA68322802ED */
