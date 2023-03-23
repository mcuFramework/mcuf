/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_8E9A5E5D_3ACE_4768_A61C_5B35294A00A8
#define MCUF_8E9A5E5D_3ACE_4768_A61C_5B35294A00A8

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./CommandLineHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace cli{
  class CommandLineExecutor;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class cli::CommandLineExecutor extends mcuf::ByteBuffer implements
public mcuf::Iterable<cli::CommandLineHandler>{

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
    mcuf::OutputBuffer& mOutputBuffer;
    cli::CommandLineHandler* mCommand[32];
    char* mArgs[16];
    int mArgsLen;

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
     * @brief Construct a new Command Line Executor object
     * 
     * @param memory 
     * @param outputBuffer 
     */
    CommandLineExecutor(const mcuf::Memory& memory, mcuf::OutputBuffer& outputBuffer);

    /**
     * @brief Construct a new Command Line Executor object
     * 
     * @param length 
     * @param outputBuffer 
     */
    CommandLineExecutor(size_t length, mcuf::OutputBuffer& outputBuffer);

    /**
     * @brief Destroy the Command Line Executor object
     * 
     */
    virtual ~CommandLineExecutor(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
                        
  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief 
     * 
     */
    void action(void);

    /**
     * @brief 
     * 
     * @param commandLineHandler 
     * @return true 
     * @return false 
     */
    bool addCommand(cli::CommandLineHandler& commandLineHandler);

    /**
     * @brief 
     * 
     * @param commandLineHandler 
     * @return true 
     * @return false 
     */
    bool removeCommand(cli::CommandLineHandler& commandLineHandler);

    /**
     * @brief Get the Command object
     * 
     * @param command 
     * @return cli::CommandLineHandler& 
     */
    cli::CommandLineHandler* getCommand(const char* command);

    /**
     * @brief 
     * 
     */
    void clearCommand(void);

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
  private:
    /**
     * @brief 
     * 
     */
    void commandExecute(void);
  
    /**
     * @brief 
     * 
     */
    void bufferClear(void);

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_8E9A5E5D_3ACE_4768_A61C_5B35294A00A8 */
