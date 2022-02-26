/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_858D7963_BBA9_4496_8D4B_B2D77E1330CC
#define MCUF_858D7963_BBA9_4496_8D4B_B2D77E1330CC

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/CompletionHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class Feture;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::Feture extends mcuf::lang::Object implements 
  public CompletionHandler<int, void*>
{

  /* **************************************************************************************
   * Enum
   */
  public:
    enum struct Status : uint32_t{
      IDLE,
      WAIT,
      DONE
    };

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
    Status mStatus;
    uint32_t mThreadID;
    uint32_t mResult;

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
     * @brief Construct a new Feture object
     * 
     */
    Feture(void);

    /**
     * @brief Destroy the Feture object
     * 
     */
    virtual ~Feture(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::CompletionHandler<int ,void*>
   */
  public:
  
    /**
     * @brief 
     * 
     * @param result 
     * @param attachment 
     */
    virtual void completed(int result, void* attachment) override;
    
    /**
     * @brief 
     * 
     * @param exc 
     * @param attachment 
     */
    virtual void failed(void* exc, void* attachment) override;

  /* **************************************************************************************
   * Public Method
   */
  public:
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool setWait(void);
  
    /**
     * @brief 
     * 
     * @return int 
     */
    int get(void);
  
    /**
     * @brief 
     * 
     * @param timeout 
     * @return int 
     */
    int get(uint32_t timeout);
  
    /**
     * @brief 
     * 
     */
    void reset(void);
  
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isDone(void);
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isIdle(void);

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

#endif /* MCUF_858D7963_BBA9_4496_8D4B_B2D77E1330CC */
