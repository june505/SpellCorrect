TARGET = server
OBJ = main.o Buffer.o Configure.o Condition.o Index.o InetAddress.o MinEditDist.o MutexLock.o MyPoolThread.o Socket.o SocketIO.o Task.o Thread.o Threadpool.o

$(TARGET) : $(OBJ)
	g++ -o $(TARGET) $(OBJ) -std=c++11 -lpthread
main.o : main.cpp ../inc/Threadpool.h ../inc/Task.h ../inc/Index.h ../inc/InetAddress.h ../inc/Configure.h ../inc/Socket.h ../inc/SocketIO.h
	g++ -c main.cpp
Threadpool.o : Threadpool.cpp ../inc/Threadpool.h ../inc/Thread.h ../inc/MyPoolThread.h ../inc/Task.h ../inc/SocketIO.h
	g++ -c Threadpool.cpp
Buffer.o : Buffer.cpp ../inc/Buffer.h ../inc/Task.h
	g++ -c Buffer.cpp
Configure.o : Configure.cpp ../inc/Configure.h
	g++ -c Configure.cpp
Condition.o : Condition.cpp ../inc/Condition.h ../inc/MutexLock.h
	g++ -c Condition.cpp
Index.o : Index.cpp ../inc/Index.h
	g++ -c Index.cpp
InetAddress.o : InetAddress.cpp ../inc/InetAddress.h
	g++ -c InetAddress.cpp
MinEditDist.o : MinEditDist.cpp ../inc/MinEditDist.h
	g++ -c MinEditDist.cpp
MutexLock.o : MutexLock.cpp ../inc/MutexLock.h 
	g++ -c MutexLock.cpp
MyPoolThread.o : MyPoolThread.cpp ../inc/MyPoolThread.h ../inc/Threadpool.h
	g++ -c MyPoolThread.cpp
Socket.o : Socket.cpp ../inc/Socket.h ../inc/InetAddress.h
	g++ -c Socket.cpp
SocketIO.o : SocketIO.cpp ../inc/SocketIO.h 
	g++ -c SocketIO.cpp
Task.o : Task.cpp ../inc/Task.h ../inc/InetAddress.h
	g++ -c Task.cpp
Thread.o : Thread.cpp ../inc/Thread.h
	g++ -c Thread.cpp

.PHONY :clean install
install:
	mv $(TARGET) ../bin
clean:
	rm -f $(TARGET) $(OBJ)


