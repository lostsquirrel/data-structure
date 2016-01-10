OBJS = TestCompare.o VectorUtils.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: TestCompare.o TestCompare 

TestCompare: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS)
	
VectorUtils.h:
	Vector.h

VectorUtils.o: VectorUtils.h VectorUtils.cpp
	$(CC) $(CFLAGS) VectorUtils.cpp
	
TestCompare.o: VectorUtils.h TestCompare.cpp
	$(CC) $(CFLAGS) TestCompare.cpp
	
TestFib: TestFibDev.o
	$(CC) $(LFLAGS) TestFibDev.o
	
TestFibDev.o: FibDev.h TestFibDev.cpp
	$(CC) $(CFLAGS) TestCompare.cpp
clean:
	\rm *.o *~ TestCompare