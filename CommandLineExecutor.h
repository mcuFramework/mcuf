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
#include "./mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./Iterable.h"
#include "./ByteBuffer.h"
#include "./OutputBuffer.h"
#include "./CommandLineHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class CommandLineExecutor;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::CommandLineExecutor extends mcuf::ByteBuffer implements
public mcuf::Iterable<mcuf::CommandLineHandler>{

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
    mcuf::CommandLineHandler* mCommand[32];
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
   * Public Method <Override> - mcuf::Iterable<mcuf::CommandLineHandler&>
   */
  public:
    /**
     * @brief Performs the given action for each element of the Iterable until all elements 
     *        have been processed or the action throws an exception. Unless otherwise 
     *        specified by the implementing class, actions are performed in the order of 
     *        iteration (if an iteration order is specified).
     * 
     * @param attachment User data.
     * @param action The action to be performed for each element.
     */
    virtual void forEach(void* attachment, 
                        mcuf::function::BiConsumer<mcuf::CommandLineHandler*, void*>& action) const override;
                        
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
    bool addCommand(mcuf::CommandLineHandler& commandLineHandler);

    /**
     * @brief 
     * 
     * @param commandLineHandler 
     * @return true 
     * @return false 
     */
    bool removeCommand(mcuf::CommandLineHandler& commandLineHandler);

    /**
     * @brief Get the Command object
     * 
     * @param command 
     * @return mcuf::CommandLineHandler& 
     */
    mcuf::CommandLineHandler* getCommand(const char* command);

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
