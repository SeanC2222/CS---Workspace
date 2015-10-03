CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -O3
CXXFLAGS += -pedantic-errors


SRC1 = Lab10.cpp
SRCS = ${SRC1}

PROG = Lab10

default: ${PROG} ${SRCS}

${PROG}: ${SRCS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG}

clean:
	rm -f  *.o *~ *.gch  ${PROG}
