// needs --std=c++11

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void printBlock(char c)
{
  mtx.lock();
  for (unsigned int i=0; i<50; ++i) std::cout<<c<<" ";
  std::cout<<std::endl;
  mtx.unlock();
}

int main()
{
  std::thread thread1(printBlock, 'a');
  std::thread thread2(printBlock, 'b');
  
  thread1.join();
  thread2.join();
  
  return 0;
}
