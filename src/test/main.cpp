#include <stdio.h>
#include <stdlib.h>
#include "mcuf.h"

using namespace mcuf::lang::managerment;
using namespace mcuf::lang;
using namespace mcuf::util;
using namespace mcuf::function;
using namespace mcuf::io;
using namespace mcuf::io::channel;
using namespace mcuf::hal;

uint8_t heapMemory[24576];
uint8_t memoryManagerEntity[sizeof(MemoryManager)];

void systemInit(){
  System::component.memoryManager();
  Memory memory = Memory(heapMemory, sizeof(heapMemory));
  MemoryManager* memoryManager = new(memoryManagerEntity) MemoryManager(memory);
  System::component.memoryManager(memoryManager);
  System::init();
}


int main(){
  systemInit();

  system("pause");
}
