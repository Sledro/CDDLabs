// Daniel Hayden
// Date: 4/10/17
// rendezvous is the main class for the program

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Running task A1."<<std::endl;
  theSemaphore->Signal();
  theSemaphore->Wait(); //Thread one is going to wait on thread two
  std::cout << "Run A2."<<std::endl;
 
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "Running task B1."<<std::endl;
  theSemaphore->Signal();
  theSemaphore->Wait(); //Thread one is going to wait on thread two
  std::cout << "Run B2."<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Main method started..\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}



