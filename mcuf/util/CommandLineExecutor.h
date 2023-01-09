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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Iterable.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/io/OutputBuffer.h"
#include "mcuf/util/CommandLineHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class CommandLineExecutor;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::util::CommandLineExecutor extends mcuf::io::ByteBuffer implements
public mcuf::lang::Iterable<mcuf::util::CommandLineHandler>{

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
    mcuf::io::OutputBuffer& mOutputBuffer;
    mcuf::util::CommandLineHandler* mCommand[32];
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
    CommandLineExecutor(const mcuf::lang::Memory& memory, mcuf::io::OutputBuffer& outputBuffer);

    /**
     * @brief Construct a new Command Line Executor object
     * 
     * @param length 
     * @param outputBuffer 
     */
    CommandLineExecutor(size_t length, mcuf::io::OutputBuffer& outputBuffer);

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
   * Public Method <Override> - mcuf::lang::Iterable<mcuf::util::CommandLineHandler&>
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
                        mcuf::function::BiConsumer<mcuf::util::CommandLineHandler*, void*>& action) const override;
                        
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
    bool addCommand(mcuf::util::CommandLineHandler& commandLineHandler);

    /**
     * @brief 
     * 
     * @param commandLineHandler 
     * @return true 
     * @return false 
     */
    bool removeCommand(mcuf::util::CommandLineHandler& commandLineHandler);

    /**
     * @brief Get the Command object
     * 
     * @param command 
     * @return mcuf::util::CommandLineHandler& 
     */
    mcuf::util::CommandLineHandler* getCommand(const char* command);

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
