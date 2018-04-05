// Daniel Hayden
// Date: 4/10/17
// Mutex is the main class for the program
/*! \class Mutex
    \brief Method Wait() decrements the counter of the semaphore. As long as the counter value is positive (>0) a call to Wait() has no effect on 
    \brief the execution. Any call to Wait() with a counter value of zero will suspend the calling thread. Each subsequent call of Signal() 
    \brief increments the counter of the semaphore by one and wakes exactly one of the waiting threads (if any) in the order of their arrival (FIFO order). 
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 1; 

/*! criticalQueueFunction is an example critical queue. Increases counter as threads are queued.
    \param Semaphore Object` 
    \return void.
*/  
void criticalQueueFunction(std::shared_ptr<Semaphore> mutex){
  mutex->Wait();
  std::cout << count << " queued/ran\n";
  count++;
  mutex->Signal();
}

int main(void){
  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  threadOne=std::thread(criticalQueueFunction,mutex);
  threadTwo=std::thread(criticalQueueFunction,mutex);
  threadThree=std::thread(criticalQueueFunction,mutex);
  std::cout << "Main method started..\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}






