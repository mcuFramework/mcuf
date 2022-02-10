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
#include "mcuf/io/OutputStream.h"

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
class mcuf::io::PrintStream extends mcuf::lang::Memory{

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
     */
    PrintStream(mcuf::io::OutputStream& outputStream, mcuf::lang::Memory& memory);

    /**
     * @brief Destroy the Print Stream object
     * 
     */
    virtual ~PrintStream(void);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

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
    bool print(int i, bool newLine);

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
     * @param b 
     * @return true 
     * @return false 
     */
    bool print(bool b);

    /**
     * @brief 
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    bool print(char c);

    /**
     * @brief 
     * 
     * @param d 
     * @return true 
     * @return false 
     */
    bool print(double d);

    /**
     * @brief 
     * 
     * @param f 
     * @return true 
     * @return false 
     */
    bool print(float f);

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    bool print(int i);

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    bool print(const mcuf::lang::String& string);

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    bool print(const char* string);

    /**
     * @brief 
     * 
     * @param b 
     * @return true 
     * @return false 
     */
    bool println(bool b);

    /**
     * @brief 
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    bool println(char c);

    /**
     * @brief 
     * 
     * @param d 
     * @return true 
     * @return false 
     */
    bool println(double d);

    /**
     * @brief 
     * 
     * @param f 
     * @return true 
     * @return false 
     */
    bool println(float f);

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    bool println(int i);

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    bool println(mcuf::lang::String& string);

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    bool println(const char* string);
    
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
