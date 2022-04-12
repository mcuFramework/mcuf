/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A
#define MCUF_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A

/* ****************************************************************************************
 * Include
 */
 
//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Number.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Boolean;
  }
}



/* ****************************************************************************************
 * Class Boolean
 */  
class mcuf::lang::Boolean extends mcuf::lang::Number{
      
  /* **************************************************************************************
   * Subclass
   */
   
  /* **************************************************************************************
   * valueariable <Public>
   */

  /* **************************************************************************************
   * valueariable <Protected>
   */

  /* **************************************************************************************
   * valueariable <Private>
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
     * @brief Construct a new Boolean object
     * 
     */
    Boolean(void);

    /**
     * @brief Construct a new Boolean object
     * 
     * @param valuealue 
     */
    Boolean(bool valuealue);
    
    /**
     * @brief Destroy the Boolean object
     * 
     */
    virtual ~Boolean(void);

  /* **************************************************************************************
   * Operator Method
   */
  public: 
    /**
     * @brief Construct a new operator bool object
     * 
     */
    operator bool(void){
      return this->mValue.b;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    bool operator==(bool v){
      return (static_cast<bool>(this->mValue.b) == v);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    bool operator==(Boolean& v){
      return (this->mValue.b == v.mValue.b);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    bool operator=(bool v){
      this->mValue.b = v;
      return this->mValue.b;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Boolean 
     */
    Boolean operator+=(int v){
      if(v > 0)
        this->mValue.b = true;
      
      else if(v < 0)
        this->mValue.b = false;
      
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Boolean 
     */
    Boolean operator-=(int v){
      if(v < 0)
        this->mValue.b = true;
      
      else if(v > 0)
        this->mValue.b = false;
      
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Boolean 
     */
    Boolean operator*=(int v){
      this->mValue.b *= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Boolean 
     */
    Boolean operator/=(int v){
      this->mValue.b /= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Boolean 
     */
    Boolean operator++(int){
      Boolean tmp = *this;
      this->mValue.b = true;
      return tmp;
    }

    /**
     * @brief 
     * 
     * @return Boolean 
     */
    Boolean operator++(){
      this->mValue.b = true;
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Boolean 
     */
    Boolean operator--(int){
      Boolean tmp = *this;
      this->mValue.b = false;
      return tmp;
    }
      
    /**
     * @brief 
     * 
     * @return Boolean& 
     */
    Boolean& operator--(){
      this->mValue.b = false;
      return *this;
    }
  
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
 *  End of file
 */ 


#endif/* MCUF_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A */
