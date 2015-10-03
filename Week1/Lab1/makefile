CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Lab1.o
OBJS2 =  Lab1-2.o f.o g.o

SRCS = Lab1.cpp Lab1-2.cpp f.cpp g.cpp

HEADERS = f.h g.h

PROGS = Lab1-1 Lab1-2 Lab1.o Lab1-2.o f.o g.o

Lab1-1: ${OBJS}  
	${CXX} ${OBJS} -o Lab1-1

Lab1-2: ${OBJS2}
	${CXX} ${OBJS2} -o Lab1-2

clean: ${PROGS}
	rm ${PROGS}
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

${OBJS2}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

