#include "../inc/Task.h"
#include "../inc/InetAddress.h"
#include <unistd.h>
//#include <iostream>
Task::Task(int servfd,InetAddress &clientAddr,string query,Index & mIndex)
	:servfd(servfd),
	clientAddr(clientAddr),
	query(query),
	mIndex(mIndex)
{}

void Task::process()
{
	this->result = mIndex.search(query);
}

string Task::getResult()
{
	return this->result;
}
InetAddress &Task::getAddr()
{
	return clientAddr;
}
int Task::getServfd()
{
	return this->servfd;
}
Task::~Task()
{
}
