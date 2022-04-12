/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_E0915DBF_E370_4AE5_A1C1_FABB5C3C4CF0
#define MCUF_E0915DBF_E370_4AE5_A1C1_FABB5C3C4CF0

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Object.h"
#include "mcuf/lang/String.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace net{
    class MediaAccessControlAddress;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::net::MediaAccessControlAddress extends mcuf::lang::Object{

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
    uint8_t mAddress[6];

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
     * @brief Construct a new Media Access Control Address object
     * 
     * @param address 
     */
    MediaAccessControlAddress(uint8_t address[6]);

    /**
     * @brief Construct a new Media Access Control Address object
     * 
     * @param address 
     */
    MediaAccessControlAddress(const char* address);

    /**
     * @brief Destroy the Media Access Control Address object
     * 
     */
    virtual ~MediaAccessControlAddress(void);

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

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_E0915DBF_E370_4AE5_A1C1_FABB5C3C4CF0 */
