CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = Lab9.cpp
SRC2 = stack.cpp
SRC3 = queue.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

OBJ1 = Lab9.o
OBJ2 = stack.o
OBJ3 = queue.o
OBJS = ${OBJ1} ${OBJ2} ${OBJ3}

HDR1 = stack.h
HDR2 = queue.h
HRDS = ${HRD1} ${HDR2}

PROG = Lab9

default: ${OBJS} ${PROG} ${SRCS} ${HDRS}

${OBJS}: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} ${SRCS} ${HDRS} -c $(@.o=.cpp)

${PROG}: ${OBJS} ${HDRS} 
	${CXX} ${CXXFLAGS} ${OBJS} ${HDRS} -o ${PROG}

clean:
	rm -f  *.o *~ *.gch  ${PROG}
