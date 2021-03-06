// Daniel Hayden
// Date: 4/10/17
// signal is the main class for the program
/*! \class Signal
    \brief This main function must create at least two threads where one thread signals the other using a common Semaphore. 
*/
#include "Semaphore.h"
#include <iostream>
#include <thread>

/*! An Example function to run an example task called taskOne.  
    \param Semaphore Object` 
    \return void.
*/  
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "Print me first First then unlock task 2 to run."<<std::endl;
  theSemaphore->Signal();
}

/*! An Example function to run an example task called taskTwo.  
    \param Semaphore Object` 
    \return void.
*/  
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "I have been unlocked, print me now."<<std::endl;
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
