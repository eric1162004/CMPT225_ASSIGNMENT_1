# Full name:    Eric Cheung
# Student ID:   301125805
# Computing-id: hccheung

# Copyright Notice:
# This code is part of the assignment 1b for CSPT 225, Spring 2025.
# Unauthorized copying or distribution is prohibited.

# Purpose of this file:
# Compiles AListTest.cpp
# Compiles assertion tests for AListTestRun
# Includes make clean instruciton

CXX = g++ # Use C++ compiler
CXXFLAGS = -std=c++11 -Wall -g

TEST_SRCS = removeLeftAssertionTest.cpp removeRightAssertionTest.cpp \
			addLeftAssertionTest.cpp addRightAssertionTest.cpp
TEST_EXES = $(TEST_SRCS:.cpp=) # Replace .cpp to empty string

# Rule to compile each test file into an executable
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
	
all: AListTest

# If assertion return non-zero exit code, 
# it means the assertion has passed.
AListTestRun: AListTest $(TEST_EXES)
	@for test in $(TEST_EXES); do \
		echo "============= Running $$test ============="; \
		if ! ./$$test 2>> /dev/null; then \
			echo "Assertion Test PASSED";\
			exit_code=0; \
		else \
			echo "Assertion Test FAILED"; \
			exit_code=1; \
		fi; \
	done; \
	echo "============= Clean up ============="; \
	make clean; \

AListTest: AListTest.cpp AList.h
	$(CXX) $(CXXFLAGS) -o AListTest AListTest.cpp 

clean:
	rm -f AListTest $(TEST_EXES)