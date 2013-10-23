tmp : tmp.o 
	g++ -o tmp -std=c++0x tmp.o 

tmp.o : tmp.cpp
	g++ -c -std=c++0x tmp.cpp

