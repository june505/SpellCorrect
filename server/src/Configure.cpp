#include "../inc/Configure.h"
#include <fstream>
#include <sstream>
#include <utility>

using namespace std;
Configure::Configure(const std::string confPath)
{
	ifstream ifs(confPath.c_str(),ios::in);
	string line;
	string str;
	int pos;
	string first,second;
	while(getline(ifs,line),!ifs.eof())
	{
		pos = 1;
		istringstream iss(line);
		while(iss>>str)
		{
			if(pos%2==1)
			{
				first = str;
				pos++;
				continue;
			}
			second = str;
		}
		conf_.insert(pair<string,string>(first,second));
	}

}


string Configure::getConf(std::string str)
{
	return conf_[str];
}
