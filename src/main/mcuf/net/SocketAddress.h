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
#include "mcuf/net/InternetProtocolAddress.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/String.h"

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
     * @param address 
     * @param port 
     */
    SocketAddress(uint32_t address, uint16_t port);
  
    /**
     * @brief Construct a new Socket Address object
     * 
     * @param address 
     * @param port 
     */
    SocketAddress(uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4, uint16_t port);

    /**
     * @brief Construct a new Socket Address object
     * 
     * @param address 
     * @param port 
     */
    SocketAddress(uint8_t* address, uint16_t port);

    /**
     * @brief Construct a new Socket Address object
     * 
     * @param address 
     * @param port 
     */
    SocketAddress(const mcuf::lang::String& address, uint16_t port);

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
     * @return mcuf::lang::String 
     */
    virtual mcuf::lang::String toString(void) override;

  /* **************************************************************************************
   * Public Method
   */
  public:
    
    /**
     * @brief Get the Port object
     * 
     * @return uint16_t 
     */
    uint16_t getPort(void);
    
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
