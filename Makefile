# Full name:    Eric Cheung
# Student ID:   301125805
# Computing-id: hccheung

# Copyright Notice:
# This code is part of the assignment 1b for CSPT 225, Spring 2025.
# Unauthorized copying or distribution is prohibited.

# Purpose of this file:
# Compiles AListTest.cpp - make all 
# Compiles assertion tests for AListTestRun - make run
# Includes make clean instruciton - make clean

CXX = g++ # Use C++ compiler
CXXFLAGS = -std=c++11 -Wall -g

TEST_SRCS = removeLeftAssertionTest.cpp removeRightAssertionTest.cpp \
			addLeftAssertionTest.cpp addRightAssertionTest.cpp
TEST_EXES = $(TEST_SRCS:.cpp=) # Replace .cpp to empty string

# Rule to compile each test file into an executable
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
	
all: AListTest
run: AListTestRun

# If assertion return non-zero exit code, 
# it means the assertion has passed.
AListTestRun: AListTest $(TEST_EXES)
	@ echo ""; \
	for test in $(TEST_EXES); do \
		echo "============= Running $$test ============="; \
		if ! ./$$test; then \
			echo "\033[32mPASS\033[0m Assertion Test";\
		else \
			echo "\033[31mFAIL\033[0m Assertion Test"; \
		fi; \
	done; \
	echo ""; \
	echo "============= Clean up ============="; \
	make clean; \

AListTest: AListTest.cpp AList.h
	$(CXX) $(CXXFLAGS) -o AListTest AListTest.cpp 

clean:
	rm -f AListTest $(TEST_EXES)