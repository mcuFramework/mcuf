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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\InternetProtocolAddress.h"
#include "mcuf\Object.h"
#include "mcuf\String.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace net{
    class SocketAddress;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::net::SocketAddress extends mcuf::net::InternetProtocolAddress{

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
    SocketAddress(const mcuf::net::InternetProtocolAddress& internetProtocolAddress, const uint16_t port);

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
    SocketAddress(const mcuf::String& address, const uint16_t port);

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
   * Public Method <Override> - mcuf::net::InternetProtocolAddress
   */
  public:
    /**
     * @brief 
     * 
     * @return mcuf::String 
     */
    virtual mcuf::String toString(void) const override;

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
    virtual void getSocketAddress(mcuf::String& result) const;

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
