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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/Console.h"
#include "mcuf/io/PrintStream.h"
#include "mcuf/io/OutputStreamHandler.h"

//-----------------------------------------------------------------------------------------
#include "hal/SerialPort.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class ConsoleSerialPort;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::ConsoleSerialPort extends mcuf::lang::Object implements
public mcuf::io::Console{

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
    mcuf::io::OutputStreamHandler mOutputStreamHandler;
    mcuf::io::PrintStream mPrintStream;

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
   * Public Method <Override> - mcuf::io::Console
   */
  public:
    /**
     * @brief 
     * 
     * @return mcuf::io::PrintStream& 
     */
    virtual mcuf::io::PrintStream& out(void) override;

    /**
     * @brief 
     * 
     * @return mcuf::io::InputStreamBuffer& 
     */
    virtual mcuf::io::InputStreamBuffer& in(void) override;

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
