/*************************************************************************
	> File Name: Task.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri 28 Aug 2015 02:43:57 AM PDT
 ************************************************************************/

#ifndef _TASK_H
#define _TASK_H
#include "Index.h"
#include <string>

using namespace std;
class Index;
class Task
{
	public:
		Task(string query,Index & mIndex);
		void process();
		string getResult();
	private:
		string query;
		Index mIndex;
		string result;
};
#endif
