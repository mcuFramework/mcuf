/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_55715FD2_5F5F_42BC_B7D1_A46F23C6500E
#define MCUF_55715FD2_5F5F_42BC_B7D1_A46F23C6500E

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../mcuf/package-info.h"
#include "./../cli/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./../hal/SerialPort.h"
#include "./../buf/OutputStreamHandler.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace ctrl{
  class ConsoleSerialPort;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class ctrl::ConsoleSerialPort extends mcuf::Object implements
public cli::Console{

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
    hal::SerialPort& mSerialPort;
    buf::OutputStreamHandler mOutputStreamHandler;
    cli::PrintStream mPrintStream;

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
     * @brief Construct a new Console Serial Port object
     * 
     * @param mSerialPort 
     * @param formatSize 
     * @param bufferSize 
     */
    ConsoleSerialPort(hal::SerialPort& serialPort, uint32_t formatSize, uint32_t bufferSize);

    /**
     * @brief Destroy the Console Serial Port object
     * 
     */
    virtual ~ConsoleSerialPort(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - cli::Console
   */
  public:
    /**
     * @brief 
     * 
     * @return cli::PrintStream& 
     */
    virtual cli::PrintStream& out(void) override;

    /**
     * @brief 
     * 
     * @return mcuf::InputStream& 
     */
    virtual mcuf::InputStream& in(void) override;

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

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_55715FD2_5F5F_42BC_B7D1_A46F23C6500E */
