// Daniel Hayden
// Date: 4/10/17
// Mutex is the main class for the program
/*! \class ReusableBarrier
	\brief NOTE: These comments are notes to self and taken from The Little Book of Semaphores chapter 3.7.7
    \brief Reusable barrier using turnstiles as in The Little Book of Semaphores chapter 3.7.7 Barrier objects in Python
	\brief When the nth thread arrives, it preloads the first turnstile with one signal for each thread. When the nth thread passes 
	\brief the turnstile, it “takes the last token” and leaves the turnstile locked again.
	\brief The same thing happens at the second turnstile, which is unlocked when the last thread goes through the mutex.
	\brief This solution is sometimes called a two-phase barrier because it forces all the threads to wait twice: once for all the 
	\brief threads to arrive and again for all the threads to execute the critical section.
*/
#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <mutex>

/*! Constructor, takes in the number of threads from the main driver
    \param count - number of threads` 
    \return void.
*/ 
SafeBuffer::SafeBuffer(){
  mutex = std::make_shared<Semaphore>(1);
  items = std::make_shared<Semaphore>(0);
  available = std::make_shared<Semaphore>(200);  
}

/*! Adds a random char onto the buffer
    \param randomChar` 
    \return void.
*/ 
void SafeBuffer::add(char randomChar){
  available->Wait();
  mutex->Wait();
  safeBuffer.push(randomChar);
  mutex->Signal();
  items->Signal();
}

/*! Pop top char off the buffer
    \param null` 
    \return randomChar.
*/ 
char SafeBuffer::remove(){
  items->Wait();
  mutex->Wait();
  char randomChar = safeBuffer.front();
  safeBuffer.pop();
  mutex->Signal();
  available->Signal();
  return randomChar;
}