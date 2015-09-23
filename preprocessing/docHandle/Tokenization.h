/*************************************************************************
	> File Name: Tokenization.h
	> Author: HOUJUN
	> Mail:june506@163.com 
	> Created Time: Fri 21 Aug 2015 04:26:05 PM HKT
 ************************************************************************/

#ifndef _DOC_HANDLER_H
#define _DOC_HANDLER_H

#include <fstream>
#include <string>
class Tokenization
{
	public:
		Tokenization(std::string sourcePath);
		Tokenization(std::string sourcePath,std::string destPath);
		void handle();
		~Tokenization();
	private:
		std::ifstream ifs_;
		std::ofstream ofs_;
};
#endif

