CXX=g++
CXXFLAGS=-g -Wall -std=c++11
RM =rm -f

all: firewall.exe

firewall.exe: mainstringtest.o string.o field.o ip.o port.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	
mainstringtest.o: mainstringtest.cpp string.cpp string.h  field.cpp field.h ip.cpp ip.h port.cpp port.h

string.o: string.cpp string.h

field.o: field.cpp field.h string.cpp string.h  ip.cpp ip.h port.cpp port.h

ip.o:   ip.cpp ip.h string.cpp string.h  field.cpp field.h

port.o: port.cpp port.h string.cpp string.h  field.cpp field.h


clean:
	$(RM) *.0 *.exe
