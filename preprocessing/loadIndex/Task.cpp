/*************************************************************************
	> File Name: Task.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 28 Aug 2015 03:45:34 AM PDT
 ************************************************************************/

#include "Task.h"
Task::Task(string query,Index & mIndex)
	:query(query),
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
