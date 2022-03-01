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
 * Class/Interface/Struct
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
  private: 
    void* mPointer;  
  
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
     * @brief Construct a new Pointer object
     * 
     */
    Pointer(void);

    /**
     * @brief Construct a new Pointer object
     * 
     * @param pointer 
     */
    Pointer(void* pointer);

    /**
     * @brief Construct a new Pointer object
     * 
     * @param pointer 
     */
    Pointer(uint32_t pointer);
    
    /**
     * @brief Destroy the Pointer object
     * 
     */
    virtual ~Pointer() = default;

  /* **************************************************************************************
   * Operator Method
   */
  public:

    /**
     * @brief 
     * 
     */
    inline operator void*(void){
      return this->mPointer;
    }

    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    inline bool operator==(const void* pointer){
      return (this->mPointer == pointer);
    }
    
    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    inline bool operator==(const Pointer& pointer){
      return (this->mPointer == pointer.mPointer);
    }
    
    /**
     * @brief 
     * 
     * @param index 
     * @return char
     */
    char operator[](int index) const{
      return static_cast<char*>(this->mPointer)[index];
    }

    /**
     * @brief 
     * 
     * @param index 
     * @return char&
     */
    char& operator[](int index){
      return static_cast<char*>(this->mPointer)[index];
    }    

  /* **************************************************************************************
   * Public Method <Static>
   */
  public: 

    /**
     * @brief 
     * 
     * @return Pointer 
     */
    static Pointer nullPointer(void);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief 
     * 
     * @param source 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, uint32_t length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, uint32_t shift, uint32_t length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, uint32_t shift, uint32_t start, uint32_t length);

  /* **************************************************************************************
   * Public Method <inline>
   */
  public:

    /**
     * @brief Get the Byte object
     * 
     * @param shift 
     * @return char 
     */
    inline char getByte(uint32_t shift) const{
      return *(char*)this->pointer(shift);
    }

    /**
     * @brief Get the Integer object
     * 
     * @param shift 
     * @return int 
     */
    inline int getInteger(uint32_t shift) const{
      return *(int*)this->pointer(shift);
    }

    /**
     * @brief Get the Short object
     * 
     * @param shift 
     * @return short 
     */
    inline short getShort(uint32_t shift) const{
      return *(short*)this->pointer(shift);
    }

    /**
     * @brief Get the Pointer object
     * 
     * @param offset 
     * @return Pointer 
     */
    inline Pointer getPointer(uint32_t offset) const{
      return Pointer(&((uint8_t*)this->mPointer)[offset]);
    }

    /**
     * @brief Get the Address object
     * 
     * @return uint32_t 
     */
    inline uint32_t getAddress(void) const{
      return reinterpret_cast<uint32_t>(this->mPointer);
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isAlignment32Bit(void){
      if((this->getAddress() & 0x00000003) != 0)
        return false;
      
      return true;
    }
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isAlignment64Bit(void){
      if((this->getAddress() & 0x00000007) != 0)
        return false;
      
      return true;
    }
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isNull(void) const{
      return (this->mPointer == nullptr);
    }

    /**
     * @brief 
     * 
     * @return void* 
     */
    inline void* pointer(void) const{
      return this->mPointer;
    }

    /**
     * @brief 
     * 
     * @param offset 
     * @return void* 
     */
    inline void* pointer(uint32_t offset) const{
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
