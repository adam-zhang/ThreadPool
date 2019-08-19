#include "Semaphore.h"

Semaphore::Semaphore(unsigned int count)
	:m_count(count)
{
}

Semaphore::~Semaphore()
{
}

void Semaphore::wait()
{
        std::unique_lock<std::mutex> unique_lock(m_mutex);
        --m_count;
        while (m_count < 0)
                m_condition_variable.wait(unique_lock);
}

void Semaphore::signal()
{
        std::lock_guard<std::mutex> lock(m_mutex);
        if (++m_count < 1)
                m_condition_variable.notify_one();
}
