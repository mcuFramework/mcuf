/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D1252B5D_6B55_4E2D_AE75_2DA3B9DD3604
#define MCUF_D1252B5D_6B55_4E2D_AE75_2DA3B9DD3604

/* ****************************************************************************************
 * Include folder
 */
#include "./hal/package-info.h"
#include "./rtos/package-info.h"

/* ****************************************************************************************
 * Include
 */
#include "./mcuf_base.h"
#include "./Allocator.h"
#include "./Ammeter.h"
#include "./Array.h"
#include "./ArrayPrototype.h"
#include "./ArrayQueue.h"
#include "./ArrayQueuePrototype.h"
#include "./BiConsumer.h"
#include "./BiConsumerEvent.h"
#include "./BlockPool.h"
#include "./Boolean.h"
#include "./Buffer.h"
#include "./Byte.h"
#include "./ByteBuffer.h"
#include "./Character.h"
#include "./Closeable.h"
#include "./Collection.h"
#include "./CommandLineExecutor.h"
#include "./CommandLineHandler.h"
#include "./CompletionHandler.h"
#include "./Console.h"
#include "./ConsoleSerialPort.h"
#include "./Consumer.h"
#include "./ConsumerEvent.h"
#include "./CoreThread.h"
#include "./CoreTick.h"
#include "./Data.h"
#include "./DuplexStream.h"
#include "./ErrorCode.h"
#include "./Executor.h"
#include "./Fifo.h"
#include "./Function.h"
#include "./FunctionEvent.h"
#include "./Future.h"
#include "./InputBuffer.h"
#include "./InputBufferLimit.h"
#include "./InputStream.h"
#include "./InputStreamBuffer.h"
#include "./InputStreamHandler.h"
#include "./Integer.h"
#include "./Interface.h"
#include "./InternetProtocolAddress.h"
#include "./Iterable.h"
#include "./Linked.h"
#include "./LinkedEntity.h"
#include "./LinkedInputBuffer.h"
#include "./LinkedOutputBuffer.h"
#include "./Map.h"
#include "./Math.h"
#include "./MediaAccessControlAddress.h"
#include "./Memory.h"
#include "./NioExecuteMethod.h"
#include "./Number.h"
#include "./Object.h"
#include "./OutputBuffer.h"
#include "./OutputBufferLimit.h"
#include "./OutputStream.h"
#include "./OutputStreamBuffer.h"
#include "./OutputStreamHandler.h"
#include "./Pointer.h"
#include "./Pool.h"
#include "./PrintStream.h"
#include "./Queue.h"
#include "./ReadonlyOutputBuffer.h"
#include "./RingBuffer.h"
#include "./RingBufferInputStream.h"
#include "./RingBufferOutputStream.h"
#include "./Runnable.h"
#include "./RunnableEntity.h"
#include "./RunnableEvent.h"
#include "./SerialBusQueue.h"
#include "./SerialBusStream.h"
#include "./Short.h"
#include "./SocketAddress.h"
#include "./Stacker.h"
#include "./StreamSkipper.h"
#include "./String.h"
#include "./Supplier.h"
#include "./SupplierEvent.h"
#include "./System.h"
#include "./SystemRegister.h"
#include "./TemperatureSensor.h"
#include "./Thread.h"
#include "./ThreadEvent.h"
#include "./ThreadPriority.h"
#include "./ThreadState.h"
#include "./Throwable.h"
#include "./Timer.h"
#include "./TimerTask.h"
#include "./TimerTick.h"
#include "./Updater.h"
#include "./VirtualAnalogInputPin.h"
#include "./VirtualGeneralPin.h"
#include "./VirtualTemperatureSensor.h"
#include "./Voltmeter.h"

/* ****************************************************************************************
 * Reference
 */

/**
 * Module macro
 */
#include "macro/package-info.h"
#ifndef MODULE_VER_MACRO
#error "module macro version not found"
#endif
#define VERSION_STATUS_CACHE VERSION_CHECK(MODULE_VER_MACRO, 1, 0, 0)
#if VERSION_STATUS_CACHE != VERSION_PASS
  #if VERSION_STATUS_CACHE == VERSION_WARN
  	#warning "module macro reversion below request"
  #else
  	#error "module macro miner to low or majer not match"
  #endif
#endif
#undef VERSION_STATUS_CACHE

/* ****************************************************************************************
 * Version
 */
#define MODULE_VER_MCUF VERSION_DEFINE(0, 1, 1)


/* ****************************************************************************************
 * Version check
 */
/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_D1252B5D_6B55_4E2D_AE75_2DA3B9DD3604 */
