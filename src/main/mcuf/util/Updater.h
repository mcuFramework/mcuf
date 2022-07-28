/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43
#define MCUF_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/Future.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace util{
    interface Updater;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::util::Updater{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param timeout 
   * @return true 
   * @return false 
   */
  bool update(int timeout);

  /**
   * @brief 
   * 
   * @param future 
   * @return true 
   * @return false 
   */
  bool update(mcuf::io::Future& future);

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43 */
