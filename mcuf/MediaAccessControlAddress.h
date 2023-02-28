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
#include "./mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./Object.h"
#include "./Strings.h"

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
class mcuf::net::MediaAccessControlAddress extends mcuf::Object{

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
    uint8_t mMediaAccessControlAddress[6];

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
     */
    MediaAccessControlAddress(void);

    /**
     * @brief Construct a new Media Access Control Address object
     * 
     * @param address 
     */
    MediaAccessControlAddress(const uint8_t address[6]);

    /**
     * @brief Construct a new Media Access Control Address object
     * 
     * @param address 
     */
    MediaAccessControlAddress(const mcuf::Strings& address);

    /**
     * @brief Destroy the Media Access Control Address object
     * 
     */
    virtual ~MediaAccessControlAddress(void) override;

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
     * @brief Set the Media Access Control Address object
     * 
     * @param address 
     */
    virtual void setMediaAccessControlAddress(const uint8_t address[6]);
  
    /**
     * @brief Set the Media Access Control Address object
     * 
     * @param address 
     */
    virtual void setMediaAccessControlAddress(const mcuf::Strings& address);
  
    /**
     * @brief Get the Media Access Control Address object
     * 
     * @param result 
     */
    virtual void getMediaAccessControlAddress(uint8_t* result) const;

    /**
     * @brief Get the Media Access Control Address object
     * 
     * @param result 
     */
    virtual void getMediaAccessControlAddress(mcuf::Strings& result) const;
  
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

#endif /* MCUF_E0915DBF_E370_4AE5_A1C1_FABB5C3C4CF0 */
