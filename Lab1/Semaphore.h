#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
    unsigned int m_uiCount;
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    void Wait();
    void Signal();

};
