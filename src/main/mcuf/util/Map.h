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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/function/BiConsumer.h"
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    template<typename K, typename V> interface Map;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename K, typename V>
interface mcuf::util::Map extends virtual mcuf::lang::Interface{
  
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param key 
   * @return true 
   * @return false 
   */
  virtual bool containsKey(K key) abstract;

  /**
   * @brief 
   * 
   * @param value 
   * @return true 
   * @return false 
   */
  virtual bool containsValue(V value) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @return V 
   */
  virtual V get(K key) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @param value 
   * @return V 
   */
  virtual V put(K key, V value) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @return V 
   */
  virtual V remove(K key) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @param value 
   * @return V 
   */
  virtual V replace(K key, V value) abstract;

  /**
   * @brief 
   * 
   */
  virtual void clear(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isEmpty(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual int size(void) abstract;

  /**
   * @brief 
   * 
   * @param function 
   */
  virtual void forEach(mcuf::function::BiConsumer<K, V>& function) abstract;

};



/* *****************************************************************************************
 * End of file
 */ 


#endif /* MCUF_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38 */
