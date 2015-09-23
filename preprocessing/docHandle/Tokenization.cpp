/*************************************************************************
	> File Name: Tokenization.cpp
	> Author: HOUJUN
	> Mail:june506@163.com 
	> Created Time: Fri 21 Aug 2015 04:55:32 PM HKT
 ************************************************************************/
#include "Tokenization.h"
#include <cctype>

Tokenization::Tokenization(std::string sourcePath)
	:ifs_(sourcePath.c_str(),std::ifstream::in),
	ofs_("filename.txt",std::ofstream::out|std::ofstream::app)
{
}


Tokenization::Tokenization(std::string sourcePath,std::string destPath)
	:ifs_(sourcePath.c_str(),std::ios::in),
	ofs_(destPath.c_str(),std::ofstream::out|std::ofstream::app)
{
}

Tokenization::~Tokenization()
{
	ifs_.close();
	ofs_.close();
}

void Tokenization::handle()
{
	std::string s,temp;
	while(getline(ifs_,s),!ifs_.eof())
	{
		int i=0;
		int size=s.size();
		while(i<size)
		{
			if(ispunct(s[i])&&((int)s[i])!=71)
			{
				s[i]=' ';
			}
			else if(isdigit(s[i]))
			{
				s[i]=' ';
			}
			else if(isalpha(s[i]))
			{
				if(isupper(s[i]))
					s[i]=tolower(s[i]);
			}
			i++;
		}
		ofs_<<s<<std::endl;
	}
}
