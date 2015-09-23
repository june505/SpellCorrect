#include "../inc/Index.h"
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>
/****************************************/
			 //Index
/****************************************/
Index::Index(string dictPath)
	:med()
{
/****************************************/
           //从文件读取字典到内存
/****************************************/
	ifstream ifs(dictPath.c_str(), ios::in);
	pair<string,int> p;
	string line;
	string str;
	int pos;
	while(getline(ifs,line),!ifs.eof())
	{
		pos=1;
		istringstream iss(line);
		while(iss>>str)
		{
			if(pos%2==1)
			{
				p.first=str;
				pos++;
				continue;
			}
			p.second=atoi(str.c_str());
		

		}
		mdict.push_back(p);

	}
	ifs.close();

/****************************************/
           //遍历字典创建索引
/****************************************/

	int dict_size=mdict.size();
	int word_len;
	int idx=0;
	string word;
	pair<string,int> pr;
	map<char,set<int> >::iterator iter;

	while(idx<dict_size)// 遍历字典数组
	{
		int i=0;
		pr=mdict[idx];
		word=pr.first;
		word_len=word.size();
		while(i<word_len)
		{
			iter=mindex.find(word[i]);
			if(iter == mindex.end())
			{
				pair<char,set<int> > p1;
				p1.first = word[i];
				p1.second.insert(idx);
				mindex.insert(p1);
				i++;
				continue;
			}
			(iter->second).insert(idx);
			i++;
		}
		idx++;
	}
}

/***************************************/
			//查询函数
/***************************************/
string Index::search(string query)
{
	priority_queue<MyResult,vector<MyResult>,MyCompare> pq;
	int i=0;
	set<int> union_set;									//声明一个并集
	map<char,set<int> >::iterator iter;
	MyResult res;
	while(i<query.size())								//遍历字串，获得并集
	{
		iter = mindex.find(query[i]);					//查找字母对应的单词的下标集合
		if(iter==mindex.end())
		{
			i++;
			continue;
		}
		union_set.insert((iter->second).begin(),
						(iter->second).end());
		i++;
	}
	set<int>::iterator it;
	it=union_set.begin();					//获得包含的单词下标集合的迭代器
	pair<string,int> pr;					//用于接收“词/词频”对
	while(it!=union_set.end())				//遍历set
	{
		pr = mdict[*it];					//根据下标获取“词/词频”对；
		int dis = med.calcMinEditDistance(pr.first,query);
											//计算最小编辑距离
		if(dis>3)							//丢弃最小编辑距离大于3的词
		{	
			it++;
			continue;
		}
		/***********************************/
		//将符合要求的单词封装到结构体并保
		//存到优先级队列中
		/***********************************/

		res.word = pr.first;
		res.frequency = pr.second;
		res.distance = dis;
		pq.push(res);
		/**********************************/
		it++;
	}

	/*string s = pq.top().word;
	while(!pq.empty())
	{
		pq.pop();
	}
	*/

	if(!pq.empty())	
		return pq.top().word;
	else
		return string("Not Found !");

}



