/*************************************************************************
	> File Name: Index.h
	> Author: HOUJUN
	> Mail:june506@163.com 
	> Created Time: Fri 21 Aug 2015 11:13:54 PM HKT
 ************************************************************************/

#ifndef _INDEX_H
#define _INDEX_H

#include "MinEditDist.h"
#include <utility>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef struct Result
{
	string word;
	int frequency;
	int distance;
}MyResult;

//优先级队列自定义优先级规则
struct MyCompare
{
	bool operator()(const MyResult &lhs,MyResult &rhs)
	{
		if(lhs.distance > rhs.distance)
			return true;
		else if(lhs.distance == rhs.distance
				&& lhs.frequency > rhs.frequency)
			return true;
		else if(lhs.distance == rhs.distance
				&&lhs.frequency == rhs.frequency
				&&lhs.word > lhs.word)
			return true;
		else
			return false;
	}
};
class Index
{
	public:
		Index(string dictPath);
		string search(string query);
	private:
		 map<char,set<int> > mindex;
		 vector<pair<string,int> > mdict;
		 MinEditDist med;
};
#endif
