// Daniel Hayden
// Date: 4/10/17
// rendezvous is the main class for the program

#include "Semaphore.h"
#include <iostream>
#include <thread>

/*! An Example function to run an example task called taskOne.  
    \param Semaphore1 Object` 
    \param Semaphore2 Object`
    \return void.
*/  
void taskOne(std::shared_ptr<Semaphore> theSemaphore1, std::shared_ptr<Semaphore> theSemaphore2){
  std::cout << "Queue task A."<<std::endl;
  theSemaphore1->Signal();
  std::cout << "Run A."<<std::endl;
  theSemaphore2->Wait();
  std::cout << "Thread A Complete."<<std::endl;
 
}

/*! An Example function to run an example task called taskOne.  
    \param Semaphore1 Object` 
    \param Semaphore2 Object`
    \return void.
*/  
void taskTwo(std::shared_ptr<Semaphore> theSemaphore1, std::shared_ptr<Semaphore> theSemaphore2){
  std::cout << "Queue task B."<<std::endl;
  theSemaphore2->Signal();
  std::cout << "Run B."<<std::endl;
  theSemaphore1->Wait();
  std::cout << "Thread B Complete."<<std::endl;
  
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> theSemaphore1( new Semaphore);
  std::shared_ptr<Semaphore> theSemaphore2( new Semaphore);
  threadOne=std::thread(taskTwo,theSemaphore1,theSemaphore2);
  threadTwo=std::thread(taskOne,theSemaphore1,theSemaphore2);
  std::cout << "Main method started..\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}






