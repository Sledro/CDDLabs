// Daniel Hayden
// Date: 4/10/17
// Mutex is the main class for the program
/*! \class Mutex
    \brief Reusable barrier using turnstiles as in The Little Book of Semaphores 
*/
#include "ReusableBarrier.h"
#include <iostream>
#include <thread>
#include <mutex>

/*! Critical task example
    \param rBarrier is an instance of our ReusableBarrier class` 
    \return void.
*/ 
void criticalQueueFunction(std::shared_ptr<ReusableBarrier> rBarrier){
    rBarrier->Phase1();
    std::cout << "Threads reached Phase 1...\n";
    rBarrier->Phase2();
    std::cout << "Threads reached Phase 2...\n" ;
}

int main(void){
    int numThreads = 5;
    std::thread threadOne, threadTwo, threadThree, threadFour, threadFive;
    std::shared_ptr<ReusableBarrier> rBarrier(new ReusableBarrier(numThreads));

    threadOne=std::thread(criticalQueueFunction, rBarrier);
    threadTwo=std::thread(criticalQueueFunction, rBarrier);
    threadThree=std::thread(criticalQueueFunction, rBarrier);
    threadFour=std::thread(criticalQueueFunction, rBarrier);
    threadFive=std::thread(criticalQueueFunction, rBarrier);

    std::cout << "Main method started..\n";
    threadOne.join();
    threadTwo.join();
    threadThree.join();
    threadFour.join();
    threadFive.join();
    return 0;
}