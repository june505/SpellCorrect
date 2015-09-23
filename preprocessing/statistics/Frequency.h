/*************************************************************************
	> File Name: freq.h
	> Author: HOUJUN
	> Mail:june506@163.com 
	> Created Time: Fri 21 Aug 2015 03:20:27 PM HKT
 ************************************************************************/

#ifndef _WD_FREQ_H
#define _WD_FREQ_H
#include <fstream>
#include <string>
#include <map>

class Word
{
	public:
		Word(std::string filename);
		~Word();
		void word_counting();

	private:
		std::map<std::string,int> word_map;
		std::ifstream ifs;
};

#endif
