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
    virtual ~Pointer(void) override;

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
    inline char operator[](int index) const{
      return static_cast<char*>(this->mPointer)[index];
    }
    
    /**
     * @brief 
     * 
     * @param index 
     * @return char
     */
    inline char operator[](unsigned int index) const{
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
    
    /**
     * @brief 
     * 
     * @param index 
     * @return char&
     */
    char& operator[](unsigned int index){
      return static_cast<char*>(this->mPointer)[index];
    }

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
  public:
    /**
     * @brief 
     * 
     * @param point 
     * @param shift 
     * @return void* 
     */
    static void* pointShift(void* pointer, int shift){
      return static_cast<char*>(pointer) + shift;
    }
    
    /**
     * @brief 
     * 
     * @param point 
     * @param shift 
     * @return void* 
     */
    static const void* pointShift(const void* pointer, int shift){
      return static_cast<const char*>(pointer) + shift;
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
    virtual int copy(const void* source, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, int shift, int start, int length);

    /**
     * @brief 
     * 
     * @param destination 
     * @param length 
     * @return int 
     */
    virtual int copyTo(void* destination, int length) const;

    /**
     * @brief 
     * 
     * @param destination 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copyTo(void* destination, int start, int length) const;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copyTo(void* destination, int shift, int start, int length) const; 
    
    /**
     * @brief 
     * 
     * @param str string
     * @return true equal
     * @return false not equal
     */
    virtual bool compairString(const char* str) const;    
    
    /**
     * @brief 
     * 
     * @param str string
     * @param start 
     * @return true equal
     * @return false not equal
     */
    virtual bool compairString(const char* str, int start) const;
    
    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return true equal
     * @return false not equal
     */
    virtual bool compair(const void* source, int length) const;    
    
    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return true equal
     * @return false not equal
     */
    virtual bool compair(const void* source, int start, int length) const;
    
    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return true equal
     * @return false not equal
     */
    virtual bool compair(const void* source, int shift, int start, int length) const;
    
    /**
     * @brief 
     * 
     * @param ch 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOf(char ch, int start, int limit) const;

    /**
     * @brief 
     * 
     * @param str 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfString(const char* str, int limit) const;

    /**
     * @brief 
     * 
     * @param str 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfString(const char* str, int start, int limit) const;

    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfMemory(const void* destination, int destinationLen, int start, int limit) const;

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
    inline char getByte(int shift) const{
      return *static_cast<char*>(this->pointer(shift));
    }

    /**
     * @brief Get the Integer object
     * 
     * @param shift 
     * @return int 
     */
    inline int getInteger(int shift) const{
      return *static_cast<int*>(this->pointer(shift));
    }

    /**
     * @brief Get the Short object
     * 
     * @param shift 
     * @return short 
     */
    inline short getShort(int shift) const{
      return *static_cast<short*>(this->pointer(shift));
    }

    /**
     * @brief Get the Pointer object
     * 
     * @param offset 
     * @return Pointer 
     */
    inline Pointer getPointer(uint32_t offset) const{
      return Pointer(&(static_cast<char*>(this->mPointer))[offset]);
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
      return static_cast<char*>(this->mPointer) + offset;
    }

    /**
     * @brief 
     * 
     * @param offset 
     * @return void* 
     */
    inline void* pointer(int offset) const{
      return static_cast<char*>(this->mPointer) + offset;
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

#endif /* MCUF_D6412968_F88E_43C3_9B72_FA8611376187 */
