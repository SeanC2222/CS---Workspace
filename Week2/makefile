CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = cell.o Assignment1.o board.o

SRCS = cell.cpp Assignment1.cpp board.cpp

HEADERS = cell.h board.h

CLN = Assignment1.o cell.o board.o Ass1

default: ${OBJS}  
	${CXX} ${CXXFLAGS} ${OBJS} -o Ass1

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: 
	rm ${CLN}
