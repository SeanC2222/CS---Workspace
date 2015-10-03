CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = filefilter.cpp
SRC2 = Lab5.cpp
SRCS = ${SRC1} ${SRC2}

OBJ1 = filefilter.o
OBJ2 = Lab5.o
OBJS = ${OBJ1} ${OBJ2}

HDR1 = filefilter.h
HDRS = ${HDR1} ${HDR2}

PROG = Lab5

default: ${OBJS} ${PROG}

${OBJS}: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} ${SRCS} ${HDRS} -c $(@.o=.cpp)

${PROG}: ${SRCS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${PROG}

clean:
	rm -f  *.o *~ *.gch  ${PROG}
