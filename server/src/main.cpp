#include "../inc/Threadpool.h"
#include "../inc/Task.h"
#include "../inc/Index.h"
#include "../inc/InetAddress.h"
#include "../inc/Configure.h"
#include "../inc/Socket.h"
#include "../inc/SocketIO.h"
#include <unistd.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#if 1
#include <iostream>
#endif
int main(int argc,char* argv[])
{	
	/*****************************************/
	//从命令行参数读取配置文件
	/*****************************************/
#if 1
	if(argc!=2)
	{
		perror("args error!");
		exit(1);
	}
	Configure conf(argv[1]);
#endif
#if 0
	Configure conf("conf.txt");
#endif
	Index mIndex(conf.getConf("mydict"));
	cout<<"加载配置成功……"<<endl;


	/*****************************************/
	//初始化线程池
	/*****************************************/
	Threadpool threadpool(5,4);
	threadpool.start();
	cout<<"线程池创建成功……"<<endl;


	/*****************************************/
	//初始化TCP服务器
	/*****************************************/
	const string IP =conf.getConf("myip");
	uint16_t PORT = atoi(conf.getConf("myport").c_str());
	InetAddress serverAddr(IP,PORT);
	InetAddress clientAddr;
	Socket socket;
	int servfd = socket.fd();
	socket.ready(serverAddr);
	char buf[32];
	cout<<"服务器启动成功……"<<endl;


	/*****************************************/
	//循环接收请求，并封装成任务，并加入线程池
	/*****************************************/
	Task *ptask ;
	cout<<"等待客户端连接"<<endl;
	while(1)
	{
		SocketIO sockIO(servfd);
		memset(buf,'\0',32);
		sockIO.readn(buf,32,clientAddr);
		/******************************
		 *log
		 */
		cout<<"IP:"<<clientAddr.ip()<<endl;
		cout<<"PORT:"<<clientAddr.port()<<endl;
		cout<<"------------------"<<endl;

		std::string str(buf);
		ptask = new Task(servfd,clientAddr,str,mIndex);
		threadpool.addTask(ptask);
	}
	return 0;
}
