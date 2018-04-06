#include <mutex>
#include <condition_variable>
#include "Semaphore.h"

class SafeBuffer
{
private:
 	int count;
	int n;
    std::mutex m_mutex;

public:

    SafeBuffer();
	void add(char randomChar);
	void remove();
};

