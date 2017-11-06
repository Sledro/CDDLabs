// Daniel Hayden
// Date: 4/10/17
// rendezvous is the main class for the program

#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Queue task A."<<std::endl;
  theSemaphore1->Signal();
  std::cout << "Run A."<<std::endl;
  theSemaphore2->Wait();
  std::cout << "Thread A Complete."<<std::endl;
 
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Queue task B."<<std::endl;
  theSemaphore1->Signal();
  std::cout << "Run B."<<std::endl;
  theSemaphore2->Wait();
  std::cout << "Thread B Complete."<<std::endl;
  
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  threadOne=std::thread(taskTwo,sem1,sem2);
  threadTwo=std::thread(taskOne,sem1,sem2);
  std::cout << "Main method started..\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}






