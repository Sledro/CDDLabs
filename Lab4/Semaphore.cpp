//Daniel Hayden
//Date: 4/10/17
//Semaphore class to hold the semaphore funtions
/*! \class Semaphore
    \brief Contains our lock and unlock functions 
*/
#include "Semaphore.h"

/*! This function will lock the thread.  
    \return void.
*/ 
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

/*! This signal function will unlock the thread and allow it to run.  
    \return void.
*/ 
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}