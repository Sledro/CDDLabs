#include <mutex>
#include <condition_variable>
#include "Semaphore.h"

class ReusableBarrier
{
private:
 	int count;
	int n;
    std::mutex m_mutex;

public:
	std::shared_ptr<Semaphore>  mutex;
	std::shared_ptr<Semaphore>  turnstile;
	std::shared_ptr<Semaphore>  turnstile2;
    ReusableBarrier(int count);
	void Wait();
	void Phase1();
	void Phase2();
};
