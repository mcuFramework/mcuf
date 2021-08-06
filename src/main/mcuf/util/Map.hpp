/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38
#define MCUF_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38

/* ****************************************************************************************
 * Include
 */  
#include "../lang/Object.hpp"
#include "../function/BiConsumer.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    template<typename K, typename V> class Map;
  }
}



/* ****************************************************************************************
 * Class Map
 */  
template<typename K, typename V>
class mcuf::util::Map :
      mcuf::lang::Object{
  
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /**
   * 
   */
  public: virtual bool containsKey(K key) = 0;

  /**
   * 
   */
  public: virtual bool containsValue(V value) = 0;

  /**
   *
   */
  public: virtual V get(K key) = 0;

  /**
   * 
   */
  public: virtual V put(K key, V value) = 0;

  /**
   * 
   */
  public: virtual V remove(K key) = 0;

  /**
   * 
   */
  public: virtual V replace(K key, V value) = 0;

  /**
   * 
   */
  public: virtual void clear(void) = 0;

  /**
   * 
   */
  public: virtual bool isEmpty(void) = 0;

  /** 
   * 
   */
  public: virtual uint32_t size(void) = 0;

  /**
   * 
   */
  public: virtual void forEach(mcuf::function::BiConsumer<K, V>& function) = 0;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  
  /**
   * Construct.
   */
  public: Map(void) = default;

  /**
   * Disconstruct.
   */
  public: virtual ~Map() = default;

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



/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38 */
