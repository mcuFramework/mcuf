/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_A35B63D2_8288_4C2E_ACB8_69DAC9906340
#define MCUF_A35B63D2_8288_4C2E_ACB8_69DAC9906340

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
    class Short;
  }
}



/* ****************************************************************************************
 * Class Short
 */  
class mcuf::lang::Short extends mcuf::lang::Number{

  /* **************************************************************************************
   * Subclass
   */

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
   
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 

    /**
     * @brief Construct a new Short object
     * 
     */
    Short(void);

    /**
     * @brief Construct a new Short object
     * 
     * @param value 
     */
    Short(short value);
    
    /**
     * @brief Destroy the Short object
     * 
     */
    virtual ~Short(void);

  /* **************************************************************************************
   * Operator Method
   */
  public:
    /**
     * @brief Construct a new operator short object
     * 
     */
    inline operator short(void){
      return this->mValue.u16[0];
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    inline bool operator==(int v){
      return (this->mValue.u16[0] == (v & 0x0000FFFF));
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    inline bool operator==(Short& v){
      return (this->mValue.u16[0] == v.mValue.u16[0]);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Short 
     */
    Short operator=(Short v){
      this->mValue.u16[0] = v.mValue.u16[0];
      return this->mValue.u16[0];
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Short 
     */
    Short operator+=(int v){
      this->mValue.u16[0] += v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Short 
     */
    Short operator-=(int v){
      this->mValue.u16[0] -= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Short 
     */
    Short operator*=(int v){
      this->mValue.u16[0] *= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Short 
     */
    Short operator/=(int v){
      this->mValue.u16[0] /= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Short 
     */
    Short operator++(int){
      Short tmp = *this;
      ++this->mValue.u16[0];
      return tmp;
    }

    /**
     * @brief 
     * 
     * @return Short 
     */
    Short operator++(void){
      ++this->mValue.u16[0];
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Short 
     */
    Short operator--(int){
      Short tmp = *this;
      --this->mValue.u16[0];
      return tmp;
    }

    /**
     * @brief 
     * 
     * @return Short& 
     */
    Short& operator--(void){
      --this->mValue.u16[0];
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
 * End of file
 */ 


#endif/* MCUF_A35B63D2_8288_4C2E_ACB8_69DAC9906340 */
