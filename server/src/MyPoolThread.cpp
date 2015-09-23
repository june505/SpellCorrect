#include "../inc/MyPoolThread.h"
#include "../inc/Threadpool.h"   //在.h文件中进行前向声明
MyPoolThread::MyPoolThread(Threadpool & threadpool)
	:threadpool_(threadpool)
{}

void MyPoolThread::run()
{
	threadpool_.threadFunc();
}

