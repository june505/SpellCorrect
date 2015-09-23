/*************************************************************************
	> File Name: test.cpp
	> Author: HOUJUN
	> Mail:june506@163.com 
	> Created Time: Fri 21 Aug 2015 07:47:04 PM HKT
 ************************************************************************/

#include "Tokenization.h"

int main(int argc,char *argv[])
{
	Tokenization token(argv[1],argv[2]);
	token.handle();
	return 0;
}
