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

MemoryManager memoryManager = MemoryManager(*new HeapMemory(10240));

void show(MemoryManager* m){
  system("cls");
  printf("BlockSize:%4d  capacity:%4d  size:%4d\n", m->entityPool->elementSize(), m->entityPool->capacity(), m->entityPool->size());
  printf("\n");
  for(int i=0; i<MemoryManager::NUMBER_OF_BLOCK_QUANTITY; i++){
    printf("BlockSize:%4d  capacity:%4d  size:%4d\n", m->blocks[i]->elementSize(), m->blocks[i]->capacity(), m->blocks[i]->size());
  }
  printf("\n");
}


void foo(){
  
  system("pause");
  void* m[1024];
  uint32_t pcnt = 0;

  for(int i=0; i<1024; ++i){
    m[i] = new char[32];
    if(m[i] == nullptr){
      pcnt = i;
      break;
    }
    show(&memoryManager);
    system("pause");
  }

  for(int i=0; i<pcnt; ++i){
    delete (void*)m[i];
    show(&memoryManager);
    system("pause");
  }
  
}


int main(){
  System::component.memoryManager(&memoryManager);
  System::init();
  foo();
  
  system("pause");
}
