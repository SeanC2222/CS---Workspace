CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors

OBJS = $(SRCS:.cpp=.o) 

SRCS = lab3.cpp

CLNS = lab3.o Lab3

PROGS = Lab3

all: ${SRCS} ${PROGS} 

${PROGS}: ${OBJS}
	${CXX} ${OBJS} -o ${PROGS} 

.cpp.o:
	${CXX} ${CXXFLAGS} $< -o $@

clean: 
	rm -f *~ *.o ${CLNS}
