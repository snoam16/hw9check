CXX=g++
CXXFLAGS=-g -Wall -std=c++11 
LIBFLAGS= -fPIC -shared 
LIB1=input
LIB2=firewall
OBJ= main.o string.o field.o ip.o port.o
RM =rm -f

all: firewall.exe libfirewall.so


firewall.exe: $(LIB2) $(OBJ) 
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@  -L. -l$(LIB2) -L. -l$(LIB1) 
	
main.o: main.cpp string.cpp string.h  field.cpp field.h ip.cpp ip.h port.cpp port.h input.h 
	$(CXX) $(CXXFLAGS)  -c main.cpp
string.o: string.cpp string.h
	$(CXX) $(CXXFLAGS)  -c string.cpp
field.o: field.cpp field.h string.cpp string.h  ip.cpp ip.h port.cpp port.h
	$(CXX) $(CXXFLAGS) -c field.cpp
ip.o:   ip.cpp ip.h string.cpp string.h  field.cpp field.h
	$(CXX) $(CXXFLAGS) -c ip.cpp
port.o: port.cpp port.h string.cpp string.h  field.cpp field.h
	$(CXX) $(CXXFLAGS) -c port.cpp 
libfirewall.so:string.o field.o ip.o port.o
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) $^ -o $@ 
clean:
	$(RM) *.0 *.exe *.so
