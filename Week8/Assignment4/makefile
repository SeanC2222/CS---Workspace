CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = dice.cpp
SRC2 = creature.cpp
SRC3 = barbarian.cpp
SRC4 = goblin.cpp
SRC5 = reptile.cpp
SRC6 = blueman.cpp
SRC7 = shadow.cpp
SRC8 = Assignment4.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8}

OBJ1 = dice.o
OBJ2 = creature.o
OBJ3 = barbarian.o
OBJ4 = goblin.o
OBJ5 = reptile.o
OBJ6 = blueman.o
OBJ7 = shadow.o
OBJS = ${OBJ1} ${OBJ2} ${OBJ3} ${OBJ4} ${OBJ5} ${OBJ6} ${OBJ7}

HDR1 = dice.h
HDR2 = creature.h
HDR3 = barbarian.h
HDR4 = goblin.h
HDR5 = reptile.h
HDR6 = blueman.h
HDR7 = shadow.h
HDRS = ${HDR1} ${HDR2} ${HDR3} ${HDR4} ${HDR5} ${HDR6} ${HDR7}

PROG = CreatureCombat

default: ${OBJS} ${PROG} ${SRCS} ${HDRS}

${OBJS}: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} ${SRCS} ${HDRS} -c $(@.o=.cpp)

${PROG}: ${SRCS} ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${SRC8} -o ${PROG}

clean:
	rm -f  *.o *~ *.gch  ${PROG}
