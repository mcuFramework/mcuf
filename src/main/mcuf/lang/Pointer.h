/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D6412968_F88E_43C3_9B72_FA8611376187
#define MCUF_D6412968_F88E_43C3_9B72_FA8611376187

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
    class Pointer;
  }
}

/* ****************************************************************************************
 * Class Pointer
 */  
class mcuf::lang::Pointer extends mcuf::lang::Object{
      
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
  private: void* mPointer;  
  
  /* **************************************************************************************
   * Abstract method <Public>
   */
   
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct a null pointer.
   */
  public: Pointer(void);

  /**
   * Construct a pointer.
   * 
   * @param pointer pointer.
   */
  public: Pointer(void* pointer);

  /**
   * Construct a pointer.
   * 
   * @param pointer pointer at value.
   */
  public: Pointer(uint32_t pointer);
  
  /**
   * Destruct.
   */
  public: virtual ~Pointer() = default;

  /* **************************************************************************************
   * Operator Method
   */

  /**
   * 
   */
  public: inline operator void*(void){
    return this->mPointer;
  }

  /**
   * Operator equal
   */
  public: inline bool operator==(const void* pointer){
    return (this->mPointer == pointer);
  }
  
  /**
   * Operator equal
   */
  public: inline bool operator==(const Pointer& pointer){
    return (this->mPointer == pointer.mPointer);
  }

  /* **************************************************************************************
   * Public Method <Static>
   */

  /**
   * 
   */
  public: static Pointer nullPointer(void);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: virtual int copy(const void* source, uint32_t length);

  /**
   * 
   */
  public: virtual int copy(const void* source, uint32_t shift, uint32_t length);

  /**
   * 
   */
  public: virtual int copy(const void* source, uint32_t shift, uint32_t start, uint32_t length);

  /* **************************************************************************************
   * Public Method <inline>
   */

  /**
   * 
   */
  public: inline char getByte(uint32_t shift) const{
    return *(char*)this->pointer(shift);
  }

  /**
   * 
   */
  public: inline int getInteger(uint32_t shift) const{
    return *(int*)this->pointer(shift);
  }

  /**
   * 
   */
  public: inline short getShort(uint32_t shift) const{
    return *(short*)this->pointer(shift);
  }

  /**
   * 
   */
  public: inline Pointer getPointer(uint32_t offset) const{
    return Pointer(&((uint8_t*)this->mPointer)[offset]);
  }

  /**
   * 
   */
  public: inline uint32_t getAddress(void) const{
    return reinterpret_cast<uint32_t>(this->mPointer);
  }

  /**
   *
   */
  public: inline bool isAlignment32Bit(void){
    if((this->getAddress() & 0x00000003) != 0)
      return false;
    
    return true;
  }
  
  /**
   *
   */
  public: inline bool isAlignment64Bit(void){
    if((this->getAddress() & 0x00000007) != 0)
      return false;
    
    return true;
  }
  
  /**
   * 
   */
  public: inline bool isNull(void) const{
    return (this->mPointer == nullptr);
  }

  /**
   * 
   */
  public: inline void* pointer(void) const{
    return this->mPointer;
  }

  /**
   * 
   */
  public: inline void* pointer(uint32_t offset) const{
    return &((uint8_t*)this->mPointer)[offset];
  }

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


#endif/* MCUF_D6412968_F88E_43C3_9B72_FA8611376187 */
