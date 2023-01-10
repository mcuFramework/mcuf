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
#include "mcuf/mcuf_base.h"
#include "mcuf/Number.h"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class Integer;
}



/* ****************************************************************************************
 * Class Integer
 */  
class mcuf::Integer extends mcuf::Number{

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
    virtual ~Integer(void) override;

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
      return this->mValue.s32;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return true 
     * @return false 
     */
    inline bool operator==(int v){
      return (this->mValue.s32 == v);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return inlien 
     */
    inline bool operator==(Integer& v){
      return (this->mValue.s32 == v.mValue.s32);
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return int 
     */
    inline int operator=(int v){
      this->mValue.s32 = v;
      return this->mValue.s32;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator+=(int v){
      this->mValue.s32 += v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator-=(int v){
      this->mValue.s32 -= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator*=(int v){
      this->mValue.s32 *= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @param v 
     * @return Integer 
     */
    inline Integer operator/=(int v){
      this->mValue.s32 /= v;
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Integer 
     */
    inline Integer operator++(int){
      Integer tmp = *this;
      ++this->mValue.s32;
      return tmp;
    }

    /**
     * @brief 
     * 
     * @return Integer 
     */
    inline Integer operator++(){
      ++this->mValue.s32;
      return *this;
    }

    /**
     * @brief 
     * 
     * @return Integer 
     */
    inline Integer operator--(int){
      Integer tmp = *this;
      --this->mValue.s32;
      return tmp;
    }

    /**
     * @brief 
     * 
     * @return Integer& 
     */
    inline Integer& operator--(void){
      --this->mValue.s32;
      return *this;
    }  
  
  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    static int valueOf(const char* str);

    /**
     * @brief 
     * 
     * @param str 
     * @return Integer 
     */
    static Integer valueOfInteger(const char* str);

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


#endif /* MCUF_B13FC504_C653_4436_A427_B6D01A462988 */
