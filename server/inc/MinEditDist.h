#ifndef __MINEDITDIST_H
#define __MINEDITDIST_H

#include <string>

using namespace std;
int min(int a,int b);
class MinEditDist
{
	public:
	//	MinEditDist(/*string target,string source*/);
		int calcMinEditDistance(string target,string source);
	/*private:
		string source_,target_;
		int tarlen,srclen;
		*/
};
#endif
