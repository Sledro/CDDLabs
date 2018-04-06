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
	  
}

/*! Barrier 1
    \param null` 
    \return void.
*/ 
void SafeBuffer::add(char randomChar){

}

/*! Barrier 1
    \param null` 
    \return void.
*/ 
void SafeBuffer::remove(){

}