/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7
#define MCUF_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Math;
  }
}



/* ****************************************************************************************
 * Class Math
 */  
class mcuf::lang::Math extends mcuf::lang::Object{

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
  private:

    /**
     * @brief Construct a new Math object
     * 
     */
    Math(void);

    /**
     * @brief Destroy the Math object
     * 
     */
    virtual ~Math(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */ 
  
  /* **************************************************************************************
   * Public Method <Static Inline>
   */   
  public:

    /**
     * @brief Returns the absolute value of an int value. If the argument is not negative, 
     *        the argument is returned. If the argument is negative, the negation of the 
     *        argument is returned.
     * 
     *        Note that if the argument is equal to the value of Integer.MIN_VALUE, the 
     *        most negative representable int value, the result is that same value, which 
     *        is negative.
     * 
     * @param a the argument whose absolute value is to be determined
     * @return the absolute value of the argument.
     */
    static inline int abs(int a){
      if(a)
        return ~a;
      
      return a;
    }

    /**
     * @brief Returns the absolute value of a long value. If the argument is not negative, 
     *        the argument is returned. If the argument is negative, the negation of the 
     *        argument is returned.
     * 
     *        Note that if the argument is equal to the value of Long.MIN_VALUE, the most 
     *        negative representable long value, the result is that same value, which is 
     *        negative.
     * 
     * @param a the argument whose absolute value is to be determined
     * @return the absolute value of the argument.
     */
    static inline long abs(long a){
      if(a<0)
        return (a * (-1));
      
      return a;
    }

    /**
     * @brief Returns the absolute value of a float value. If the argument is not negative, 
     *        the argument is returned. If the argument is negative, the negation of the 
     *        argument is returned.
     * 
     *        Note that if the argument is equal to the value of Float.MIN_VALUE, the most 
     *        negative representable float value, the result is that same value, which is
     *        negative.
     * 
     * @param a the argument whose absolute value is to be determined
     * @return the absolute value of the argument.
     */
    static inline float abs(float a){
      if(a<0)
        return (a * (-1));
      
      return a;
    }  
    
    /**
     * @brief 
     * 
     * @param value 
     * @return uint32_t 
     */
    static inline uint32_t align32bit(uint32_t value){
      if(value & 0x00000003)
        return  (value & 0xFFFFFFF4) + 4;
      
      return value;
    }
    
    /**
     * @brief 
     * 
     * @param value 
     * @return uint32_t 
     */
    static inline uint32_t align64bit(uint32_t value){
      if(value & 0x00000007)
        return  (value & 0xFFFFFFF8) + 8;
      
      return value;
    }  
    
    /**
     * @brief 
     * 
     * @param dividend 
     * @param divisor 
     * @return int 
     */
    static inline int ceil(int dividend, int divisor){
      return (dividend + (divisor-1)) / divisor;
    }

    /**
     * @brief 
     * 
     * @param dividend 
     * @param divisor 
     * @return uint32_t 
     */
    static inline uint32_t ceil(uint32_t dividend, uint32_t divisor){
      return (dividend + (divisor-1)) / divisor;
    }  
    
    /**
     * @brief 
     * 
     * @param a 
     * @param b 
     * @return uint32_t 
     */
    static inline uint32_t min(uint32_t a, uint32_t b){
      return ((a)<(b)?(a):(b));
    }
    
    /**
     * @brief 
     * 
     * @param a 
     * @param b 
     * @return int 
     */
    static inline int min(int a, int b){
      return ((a)<(b)?(a):(b));
    }    

    /**
     * @brief 
     * 
     * @param a 
     * @param b 
     * @return uint32_t 
     */
    static inline uint32_t max(uint32_t a, uint32_t b){
      return ((a)>(b)?(a):(b));
    }  

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


#endif /* MCUF_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7 */
