/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05
#define MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05

/* ****************************************************************************************
 * Include
 */  
#include <stdarg.h>

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Memory.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/io/OutputStream.h"
#include "mcuf/io/OutputBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class PrintStream;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::PrintStream extends mcuf::lang::Memory implements
public mcuf::io::OutputStream{

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
    mcuf::io::OutputStream& mOutputStream;
    mcuf::io::ByteBuffer mByteBuffer;

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
     * @brief Construct a new Print Stream object
     * 
     * @param outputStream 
     * @param memory 
     */
    PrintStream(mcuf::io::OutputStream& outputStream, const mcuf::lang::Memory& memory);

    /**
     * @brief Construct a new Print Stream object
     * 
     * @param outputStream 
     * @param length 
     */
    PrintStream(mcuf::io::OutputStream& outputStream, uint32_t length);
  
    /**
     * @brief Destroy the Print Stream object
     * 
     */
    virtual ~PrintStream(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::OutputStream
   */
  public:
    /**
     * 
     */
    virtual bool abortWrite(void) override;
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool writeBusy(void) override;
    
    /**
     * @brief 
     * 
     * @param outputBuffer
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(mcuf::io::OutputBuffer& outputBuffer, int timeout) override;  
    
    /**
     * @brief 
     * 
     * @param outputBuffer
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool write(mcuf::io::OutputBuffer& outputBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param outputBuffer
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(mcuf::io::OutputBuffer& outputBuffer, mcuf::io::Future& future) override;
    
  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @param b 
     * @return true 
     * @return false 
     */
    inline bool print(bool b){
      return this->print(b, false);
    }

    /**
     * @brief 
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    inline bool print(char c){
      return this->print(c, false);
    }

    /**
     * @brief 
     * 
     * @param d 
     * @return true 
     * @return false 
     */
    inline bool print(double d){
      return this->print(d, false);
    }

    /**
     * @brief 
     * 
     * @param f 
     * @return true 
     * @return false 
     */
    inline bool print(float f){
      return this->print(f, false);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline bool print(int i){
      return this->print(i, false, false);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline bool print(unsigned int i){
      return this->print(static_cast<int>(i), false, true);
    }    
    
    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline bool print(const mcuf::lang::String& string){
      return this->print(string, false);
    }

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline bool print(const char* string){
      return this->print(string, false);
    }

    /**
     * @brief 
     * 
     * @param outputBuffer 
     * @return true 
     * @return false 
     */
    inline bool print(mcuf::io::OutputBuffer& outputBuffer){
      return this->print(outputBuffer, false);
    }    
    
    /**
     * @brief 
     * 
     * @param b 
     * @return true 
     * @return false 
     */
    inline bool println(bool b){
      return this->print(b, true);
    }

    /**
     * @brief 
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    inline bool println(char c){
      return this->print(c, true);
    }

    /**
     * @brief 
     * 
     * @param d 
     * @return true 
     * @return false 
     */
    inline bool println(double d){
      return this->print(d, true);
    }

    /**
     * @brief 
     * 
     * @param f 
     * @return true 
     * @return false 
     */
    inline bool println(float f){
      return this->print(f, true);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline bool println(int i){
      return this->print(i, true, false);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline bool println(unsigned int i){
      return this->print(static_cast<int>(i), true, true);
    }    
    
    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline bool println(const mcuf::lang::String& string){
      return this->print(string, true);
    }

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline bool println(const char* string){
      return this->print(string, true);
    }
    
    /**
     * @brief 
     * 
     * @param outputBuffer 
     * @return true 
     * @return false 
     */
    inline bool println(mcuf::io::OutputBuffer& outputBuffer){
      return this->print(outputBuffer, true);
    }
    
  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief 
     * 
     * @param b 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(bool b, bool newLine);

    /**
     * @brief 
     * 
     * @param c 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(char c, bool newLine);

    /**
     * @brief 
     * 
     * @param d 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(double d, bool newLine);

    /**
     * @brief 
     * 
     * @param f 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(float f, bool newLine);

    /**
     * @brief 
     * 
     * @param i 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(int i, bool newLine, bool unsign);

    /**
     * @brief 
     * 
     * @param string 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(const mcuf::lang::String& string, bool newLine);

    /**
     * @brief 
     * 
     * @param string 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(const char* string, bool newLine);

    /**
     * @brief 
     * 
     * @param OutputBuffer 
     * @param newLine 
     * @return true 
     * @return false 
     */
    bool print(mcuf::io::OutputBuffer& outputBuffer, bool newLine);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool println(void);

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return true 
     * @return false 
     */
    bool format(const char* format, ...);

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

#endif /* MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05 */
