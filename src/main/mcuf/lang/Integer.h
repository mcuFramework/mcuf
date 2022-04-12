/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B13FC504_C653_4436_A427_B6D01A462988
#define MCUF_B13FC504_C653_4436_A427_B6D01A462988

/* ****************************************************************************************
 * Integer
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Number.h"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Integer;
  }
}



/* ****************************************************************************************
 * Class Integer
 */  
class mcuf::lang::Integer extends mcuf::lang::Number{

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
     * @brief Construct a new Integer object
     * 
     */
    Integer(void);

    /**
     * @brief Construct a new Integer object
     * 
     * @param value 
     */
    Integer(int value);
    
    /**
     * @brief Destroy the Integer object
     * 
     */
    ~Integer(void);

  /* **************************************************************************************
   * Operator Method
   */
  public:
    /**
     * @brief 
     * 
     * @return int 
     */
    inline operator int(void){
      return static_cast<int>(this->mValue.u32);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    inline bool operator==(int v){
      return (static_cast<int>(this->mValue.u32) == v);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return inlien 
     */
    inline bool operator==(Integer& v){
      return (this->mValue.u32 == v.mValue.u32);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return int 
     */
    inline int operator=(int v){
      this->mValue.u32 = v;
      return this->mValue.u32;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator+=(int v){
      this->mValue.u32 += v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator-=(int v){
      this->mValue.u32 -= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator*=(int v){
      this->mValue.u32 *= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator/=(int v){
      this->mValue.u32 /= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Integer 
     */
    inline Integer operator++(int){
      Integer tmp = *this;
      ++this->mValue.u32;
      return tmp;
    }

    /**
     * @brief 
     * 
     * @return Integer 
     */
    inline Integer operator++(){
      ++this->mValue.u32;
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Integer 
     */
    inline Integer operator--(int){
      Integer tmp = *this;
      --this->mValue.u32;
      return tmp;
    }

    /**
     * @brief 
     * 
     * @return Integer& 
     */
    inline Integer& operator--(void){
      --this->mValue.u32;
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


#endif/* MCUF_B13FC504_C653_4436_A427_B6D01A462988 */
