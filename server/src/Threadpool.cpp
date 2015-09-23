#include "../inc/Threadpool.h"
#include "../inc/Thread.h"
#include "../inc/MyPoolThread.h"
#include "../inc/Task.h"
#include "../inc/SocketIO.h"
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <string>
using namespace std;
Threadpool::Threadpool(int bufsize,int threadNum)
	:size_(bufsize),
	buffer_(size_),			//任务缓存的初始化
	threadNum_(threadNum),
	vecThreads_(threadNum_),
	isExit_(false)
{}

Threadpool::~Threadpool()
{
	stop();
}


void Threadpool::start()
{
	for(int idx = 0;idx!=threadNum_;idx++)
	{
		Thread *pthread = new MyPoolThread(*this);
		vecThreads_.push_back(pthread);
		pthread->start();
	}

}


void Threadpool::stop()
{
	if(isExit_)
	{
		isExit_=true;
		std::vector<Thread*>::iterator iter;
		for(iter = vecThreads_.begin();iter!=vecThreads_.end();iter++)
		{
			(*iter)->join();
			delete *iter;		//释放iter所指向的空间
		}
		vecThreads_.clear();
	}
}

void Threadpool::addTask(Task* task)
{
	buffer_.push(task);
}

Task* Threadpool::getTask()
{
	return buffer_.pop();
}


/*************************************/
/* 这是一个在线程中执行的回调函数
 *************************************
 *
 * 执行查询任务
 * 获取查询结果
 * 创建一个SocketIO对象
 * 通过peerfd向客户端写数据
 * 然后关闭peerfd    (由Task的析构函数负责)
 * 释放task占用的空间
 */
void Threadpool::threadFunc()
{
	while(!isExit_)
	{
		Task *task = getTask();
		if(task != NULL)
		{
			task->process();
			SocketIO sockio(task->getServfd());
			string res = task->getResult();
			InetAddress addr = task->getAddr();
			addr.port();
			int resSize = res.size();
			char ch[resSize+1];
			strcpy(ch,res.c_str());
			sockio.writen(ch,strlen(ch),addr);
		}
		delete task;
		task=NULL;
	}
}
/*************************************/
