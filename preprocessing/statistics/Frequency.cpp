/*************************************************************************
	> File Name: Frequency.cpp
	> Author: HOUJUN
	> Mail:june506@163.com 
	> Created Time: Fri 21 Aug 2015 03:23:26 PM HKT
 ************************************************************************/


#include "Frequency.h"
#include<iostream>
#include<iomanip>

Word::Word(std::string filename)
	:ifs(filename.c_str(),std::ios::in)
{}



Word::~Word()
{
	ifs.close();
}


void Word::word_counting()
{
	std::string s;
	int cnt=0;
	while(ifs>>s,!ifs.eof())
	{
		cnt++;
		std::map<std::string,int>::iterator iter;
		iter=word_map.find(s);
		if(iter==word_map.end())
		{
			word_map.insert(std::map<std::string,int>::value_type(s,1));
			continue;
		}
		iter->second++;
	}
	std::ofstream ofs("dict.txt");
	std::map<std::string,int>::iterator iter = word_map.begin();
	while(iter!=word_map.end())
	{
		//ofs<<std::left<<std::setw(16)<<iter->first<<std::right<<std::setw(6)<<iter->second<<std::endl;
		ofs<<iter->first<<" "<<iter->second<<std::endl;
		iter++;
	}
	std::cout<<"total:"<<cnt<<" words"<<std::endl;
	std::cout<<"result is saved in file : dict.txt"<<std::endl;
	ofs.close();
}
