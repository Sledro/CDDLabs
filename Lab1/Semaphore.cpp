## Daniel Hayden
## Date: 4/10/17
## Semaphore class to hold the semaphore funtions

#include "Semaphore.h"

## The wait funtion will lock the thread
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}

## This signal funtion will unlock the thread and allow it to run
void Semaphore::Signal()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}
