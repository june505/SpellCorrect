#ifndef _THREAD_H
#define _THREAD_H
#include "Noncopyable.h"
#include <pthread.h>
class Thread : private Noncopyable
{
	public:
		Thread()
			:pthId_(0),
			isRunning_(false)
		{}
		void start();
		void join();
		virtual void run()=0; 
		~Thread();
		static void *runInThread(void *arg);
	private:
		pthread_t pthId_;
		bool isRunning_;
};
#endif
