CXX = g++ # C++ compiler
CXXFLAGS = -std=c++11 -Wall -g

all: AListTest

AListTest: AListTest.cpp
	$(CXX) $(CXXFLAGS) -o AListTest AListTest.cpp 

clean:
	rm -f AListTest