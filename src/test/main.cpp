#include <stdio.h>
#include <stdlib.h>
#include "mcuf.h"
#include "TestStream.hpp"

using namespace mcuf::lang::managerment;
using namespace mcuf::lang;
using namespace mcuf::util;
using namespace mcuf::function;
using namespace mcuf::io;
using namespace mcuf::io::channel;
using namespace mcuf::hal;

uint8_t heapMemory[24576];
uint8_t memoryManagerEntity[sizeof(MemoryManager)];
test::TestStream testStream = test::TestStream();

void systemInit(){
  System::component.memoryManager();
  Memory memory = Memory(heapMemory, sizeof(heapMemory));
  MemoryManager* memoryManager = new(memoryManagerEntity) MemoryManager(memory);
  
  System::component.memoryManager(memoryManager);
  System::component.outputString(&testStream);
  System::init();
}

uint8_t bf[8];

int main(){
  systemInit();

  System::out.format("Hello mcuf %d\n", 1234);

  system("pause");
}
