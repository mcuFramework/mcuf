/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_58C89839_4FBA_4C6E_BDF8_4387141D879B
#define MCUF_58C89839_4FBA_4C6E_BDF8_4387141D879B

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace buf{
  class ReadonlyOutputBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class buf::ReadonlyOutputBuffer extends mcuf::Data implements
public mcuf::OutputBuffer{

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
    int mPosition;

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
     * @brief Construct a new Readonly Output Buffer object
     * 
     * @param str 
     */
    ReadonlyOutputBuffer(const char* str);

    /**
     * @brief Construct a new Readonly Output Buffer object
     * 
     * @param pointer 
     * @param length 
     */
    ReadonlyOutputBuffer(const void* pointer, size_t length);

    /**
     * @brief Destroy the Readonly Output Buffer object
     * 
     */
    virtual ~ReadonlyOutputBuffer(void) override;

  /* **************************************************************************************
   * Operator Method
   */
  public:
    /**
     *
     */
    inline int operator=(int v){
      this->position(v);
      return this->position();
    }
    
    /**
     *
     */
    inline void operator+=(int shift){
      this->position(this->position() + shift);
    }
    
    /**
     *
     */
    inline void operator-=(int shift){
      this->position(this->position() - shift);
    }
    
    /**
     *
     */
    inline unsigned int operator++(void){
      this->position(this->position() + 1);
      return static_cast<unsigned int>(this->position());
    }
    
    /**
     *
     */
    inline unsigned int operator--(void){
      this->position(this->position() - 1);
      return static_cast<unsigned int>(this->position());
    }

        /**
     *
     */
    inline unsigned int operator++(int){
      unsigned int result = static_cast<unsigned int>(this->position());
      this->position(this->position() + 1);
      return result;
    }
    
    /**
     *
     */
    inline unsigned int operator--(int){
      unsigned int result = static_cast<unsigned int>(this->position());
      this->position(this->position() - 1);
      return result;
    }
  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::OutputBuffer
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline virtual bool isEmpty(void) const override{
      return (this->mPosition >= this->length());
    }

    /**
     * @brief 
     * 
     * @return int 
     */
    inline virtual int avariable(void) const override{
      return (this->length() - this->mPosition);
    }

    /**
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool getByte(char& result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int get(mcuf::InputBuffer& inputBuffer) override;

	  /**
	   * @brief 
	   * 
	   * @param byteBuffer 
	   * @return int 
	   */
	  virtual int get(mcuf::InputBuffer& inputBuffer, int length) override;    
    
    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int get(void* buffer, int bufferSize) override;

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int skip(int value) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:
    /**
     * @brief 
     * 
     * @return unsigned int 
     */
    inline int capacity(void) const{
      return this->length();
    }
    
    /**
     * @brief 
     * 
     * @return unsigned int 
     */
    inline int position(void) const{
      return this->mPosition;
    }  

    /**
     * @brief 
     * 
     */
    virtual void rewind(void){
      this->mPosition = 0;
    }
    

  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief 
     * 
     * @param newPosition 
     * @return true 
     * @return false 
     */
    bool position(int newPosition);

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

#endif /* MCUF_58C89839_4FBA_4C6E_BDF8_4387141D879B */
