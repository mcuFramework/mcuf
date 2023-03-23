/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_252F628C_C174_4836_88ED_23C33E0C2773
#define MCUF_252F628C_C174_4836_88ED_23C33E0C2773

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./InternetProtocolAddress.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace net{
  class SocketAddress;
}



/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class net::SocketAddress extends net::InternetProtocolAddress{

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
    uint16_t mPort;

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
     * @brief Construct a new Socket Address object
     * 
     */
    SocketAddress(void);
  
    /**
     * @brief Construct a new Socket Address object
     * 
     * @param internetProtocolAddress 
     * @param port 
     */
    SocketAddress(const net::InternetProtocolAddress& internetProtocolAddress, const uint16_t port);

    /**
     * @brief Construct a new Socket Address object
     * 
     * @param address 
     * @param port 
     */
    SocketAddress(const uint32_t address, const uint16_t port);
  
    /**
     * @brief Construct a new Socket Address object
     * 
     * @param address 
     * @param port 
     */
    SocketAddress(const uint8_t a1, const uint8_t a2, const uint8_t a3, const uint8_t a4, const uint16_t port);

    /**
     * @brief Construct a new Socket Address object
     * 
     * @param address 
     * @param port 
     */
    SocketAddress(const uint8_t address[4], const uint16_t port);

    /**
     * @brief Construct a new Socket Address object
     * 
     * @param address 
     * @param port 
     */
    SocketAddress(const mcuf::Strings& address, const uint16_t port);

    /**
     * @brief Destroy the Socket Address object
     * 
     */
    virtual ~SocketAddress(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - net::InternetProtocolAddress
   */
  public:
    /**
     * @brief 
     * 
     * @return mcuf::Strings 
     */
    virtual mcuf::Strings toStrings(void) const override;

  /* **************************************************************************************
   * Public Method
   */
  public:
    
    /**
     * @brief Get the Port object
     * 
     * @return uint16_t 
     */
    virtual uint16_t getPort(void) const;
  
    /**
     * @brief Get the Socket Address object
     * 
     * @param result 
     */
    virtual void getSocketAddress(mcuf::Strings& result) const;

    /**
     * @brief Set the Port object
     * 
     * @param port 
     */
    virtual void setPort(uint16_t port);
    
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

#endif /* MCUF_252F628C_C174_4836_88ED_23C33E0C2773 */
