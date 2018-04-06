#include <mutex>
#include <queue>
#include "Semaphore.h"

class SafeBuffer
{
public:
	std::queue<char> safeBuffer;
    std::shared_ptr<Semaphore> mutex;
	std::shared_ptr<Semaphore> items;
	std::shared_ptr<Semaphore> available;
    SafeBuffer();
	void add(char randomChar);
	char remove();
	
};

