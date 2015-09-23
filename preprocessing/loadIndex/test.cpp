/*************************************************************************
	> File Name: test.cpp
	> Author: HOUJUN
	> Mail:june506@163.com 
	> Created Time: Mon 24 Aug 2015 09:01:33 PM HKT
 ************************************************************************/

#include "Task.h"
#include"Index.h"
#include<iostream>
int main()
{
	string s,str;
	Index index("dict.txt");
	while(1)
	{
		cout<<"please input: ";
		cin>>str;
		Task task(str,index);
		task.process();
		cout<<" ------>  "<<task.getResult()<<endl;	
	}
	return 0;
}
