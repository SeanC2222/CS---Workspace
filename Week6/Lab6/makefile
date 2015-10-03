CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = Lab6.cpp
SRCS = ${SRC1}

PROG = Lab6

default: ${PROG} ${SRCS}


${PROG}: ${SRCS} 
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG}

clean:
	rm -f ${PROG}
