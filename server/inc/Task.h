#ifndef _TASK_H
#define _TASK_H
#include "Index.h"
#include "InetAddress.h"
#include <string>

using namespace std;
class Index;
class Task
{
	public:
		Task(int servfd,InetAddress &clientAddress,string query,Index & mIndex);
		void process();
		string getResult();
		int getServfd();
		InetAddress  & getAddr();
		~Task();
	private:
		InetAddress clientAddr;
		string query;
		Index mIndex;
		string result;
		int servfd;
};
#endif
