CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = Lab8.cpp
SRCS = ${SRC1}

OBJ1 = Lab8.o
OBJS = ${OBJ1}

PROG = Maze 

default: ${OBJS} ${PROG} ${SRCS} ${HDRS}

${OBJS}: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} ${SRCS} ${HDRS} -c $(@.o=.cpp)

${PROG}: ${SRCS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${SRC8} -o ${PROG}

clean:
	rm -f  *.o *~ *.gch  ${PROG}
