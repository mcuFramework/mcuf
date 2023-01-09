/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_991E80DC_D455_40D1_9E26_47A976406685
#define MCUF_991E80DC_D455_40D1_9E26_47A976406685

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/util/Fifo.h"

//-----------------------------------------------------------------------------------------
#include "hal/SerialBus.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class SerialBusQueue;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::SerialBusQueue extends mcuf::util::Fifo implements
public hal::serial::SerialBus,
public hal::serial::SerialBusEvent{

  private:
    struct Packet{
      uint16_t reserved;
      uint16_t address;
      mcuf::io::OutputBuffer* out;
      mcuf::io::InputBuffer* in;
      void* attachment;
      hal::serial::SerialBusEvent* event;
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
    hal::serial::SerialBus& mSerialBus;
    Packet mPacket;

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
     * @brief Construct a new Serial Bus Queue object
     * 
     * @param serialBus 
     * @param queueSize 
     */
    SerialBusQueue(hal::serial::SerialBus& serialBus, uint32_t queueSize);

    /**
     * @brief Destroy the Serial Bus Queue object
     * 
     */
    virtual ~SerialBusQueue(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - hal::Base
   */
  public:
    /**
     * @brief uninitialze hardware.
     * 
     * @return true 
     * @return false 
     */
    virtual bool deinit(void) override;

    /**
     * @brief initialze hardware;
     * 
     * @return true 
     * @return false 
     */
    virtual bool init(void) override;

    /**
     * @brief get hardware initialzed status.
     * 
     * @return true not init
     * @return false initd
     */
    virtual bool isInit(void) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::serial::SerialBusControl
   */
  public:
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    virtual uint32_t clockRate(void) override;

    /**
     * @brief 
     * 
     * @param clock 
     * @return uint32_t 
     */
    virtual uint32_t clockRate(uint32_t clock) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::serial::SerialBusTransfer
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool abort(void) override;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool isBusy(void) override;

    /**
     * @brief 
     * 
     * @param address 
     * @param in
     * @param attachment   
     * @param event 
     */
    virtual bool read(uint16_t address, 
                      mcuf::io::InputBuffer& in, 
                      void* attachment,
                      hal::serial::SerialBusEvent* event) override;

    /**
     * @brief 
     * 
     * @param address 
     * @param out
     * @param attachment                      
     * @param event 
     */
    virtual bool write(uint16_t address, 
                       mcuf::io::OutputBuffer& out,
                       void* attachment,
                       hal::serial::SerialBusEvent* event) override;
    
    /**
     * @brief 
     * 
     * @param address 
     * @param out
     * @param in
     * @param attachment                       
     * @param event 
     * @return true 
     * @return false 
     */
    virtual bool transfer(uint16_t address,
                          mcuf::io::OutputBuffer& out, 
                          mcuf::io::InputBuffer& in,
                          void* attachment,
                          hal::serial::SerialBusEvent* event) override;
                          
  /* **************************************************************************************
   * Public Method <Override> - hal::serial::SerialBusEvent
   */
  public:
    /**
     * @brief 
     * 
     * @param status handle status
     * @param result 0 = successful, other = remaining byte count.
     * @param attachment user data
     */
    virtual void onSerialBusEvent(hal::serial::SerialBusStatus status, 
                                  int result,
                                  void* attachment) override;

  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief 
     * 
     */
    virtual void abortAll(void);
  
    /**
     * @brief 
     * 
     * @param packet 
     * @return true 
     * @return false 
     */
    virtual bool handlerConfig(Packet& packet);

    /**
     * @brief 
     * 
     * @param packet 
     */
    virtual void executeFail(Packet& packet);

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

#endif /* MCUF_991E80DC_D455_40D1_9E26_47A976406685 */
