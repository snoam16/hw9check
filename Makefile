CXX=g++
CXXFLAGS=-g -Wall -std=c++11
RM =rm -f

all: firewall.exe

firewall.exe: mainstringtest.o string.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	
mainstringtest.o: mainstringtest.cpp string.cpp string.h
string.o: string.cpp string.h

clean:
	$(RM) *.0 *.exe
