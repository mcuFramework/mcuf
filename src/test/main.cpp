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

void foo(Memory& memory){
  for(int i=0; i<memory.length(); i++){
    printf("0x%02X ", memory.getByte(i));
    if(((i+1)%8) == 0)
      printf("\n");
  }
}

char data[16];

int main(){
  for(int i=0; i<sizeof(data); i++){
    data[i] = 0x10 + i;
  }
  Memory orig = Memory(data, sizeof(data));
  HeapMemory memory = HeapMemory(64);
  memory.clear();
  memory.getPointer().copy("Hello", 5);

  foo(memory);
  
  system("pause");
}
