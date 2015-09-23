#ifndef _CONFIGURE_H
#define _CONFIGURE_H

#include <map>
#include <string>


class Configure
{
	public:
		Configure(std::string confPath);
		std::string getConf(std::string str);
		private:
		std::map<std::string,std::string> conf_;
};
#endif
