// Daniel Hayden
// Date: 4/10/17
// Mutex is the main class for the program
/*! \class Mutex
    \brief Reusable barrier using turnstiles as in The Little Book of Semaphores 
*/
#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <mutex>

/*! The producer generates random characters from ‘a’ to ‘z’ at random intervals (between 0 and 1 second in length). It adds these to a thread safe buffer 
    that has a finite holding capacity of N characters. It generates a preset number of characters (determined at runtime) and when it has finished it add 
    an ‘X’ character to the buffer and exits.
    \param none` 
    \return void.
*/ 
void makeProducers(std::shared_ptr<SafeBuffer> safeBuff){

    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char randomChar;

    while(randomChar!='X'){

        //pick a random character between 0 and the number of characters stored in the array
        randomChar = letters[rand() % 26];
        safeBuff->add(randomChar);
        std::cout << randomChar << std::endl;
    }
}

/*! The consumer takes these letters from the buffer at random time intervals (between 0 and 1 second in length) and records how many of each letter it 
    consumes. Once it sees an ‘X’ in the buffer it adds its character count to a central buffer and exits.
    \param none` 
    \return void.
*/ 
void makeConsumers(){

}

int main(void){

    return 0;
}