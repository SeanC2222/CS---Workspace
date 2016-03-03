CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = ColiseumGame.cpp 
SRC2 = coliseum.cpp
SRC3 = room.cpp
SRC4 = gate.cpp
SRC5 = opensand.cpp
SRC6 = tigertrap.cpp
SRC7 = spikepit.cpp
SRC8 = item.cpp
SRC9 = sword.cpp
SRC10 = shield.cpp
SRC11 = potion.cpp
SRC12 = herossash.cpp
SRC13 = carcass.cpp
SRC14 = dice.cpp
SRC15 = creature.cpp
SRC16 = gladiator.cpp
SRC17 = barbarian.cpp
SRC18 = creatiger.cpp
SRC19 = creaspike.cpp

SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11} ${SRC12} ${SRC13} ${SRC14} ${SRC15} ${SRC16} ${SRC17} ${SRC18} ${SRC19}

OBJ1 = ColiseumGame.cpp
OBJ2 = coliseum.o
OBJ3 = room.o
OBJ4 = gate.o
OBJ5 = opensand.o
OBJ6 = tigertrap.o
OBJ7 = spikepit.o
OBJ8 = item.o
OBJ9 = sword.o
OBJ10 = shield.o
OBJ11 = potion.o
OBJ12 = herossash.o
OBJ13 = carcass.o
OBJ14 = dice.o
OBJ15 = creature.o
OBJ16 = gladiator.o
OBJ17 = barbarian.o
OBJ18 = creatiger.o
OBJ19 = creaspike.o

OBJS = ${OBJ1} ${OBJ2} ${OBJ3} ${OBJ4} ${OBJ5} ${OBJ6} ${OBJ7} ${OBJ8} ${OBJ9} ${OBJ10} ${OBJ11} ${OBJ12} ${OBJ13} ${OBJ14} ${OBJ15} ${OBJ16} ${OBJ17} ${OBJ18} ${OBJ19}

HDR1 = 
HDR2 = coliseum.h
HDR3 = room.h
HDR4 = gate.h
HDR5 = opensand.h
HDR6 = tigertrap.h
HDR7 = spikepit.h
HDR8 = item.h
HDR9 = sword.h
HDR10 = shield.h
HDR11 = potion.h
HDR12 = herossash.h
HDR13 = carcass.h
HDR14 = dice.h
HDR15 = creature.h
HDR16 = gladiator.h
HDR17 = barbarian.h
HDR18 = creatiger.h
HDR19 = creaspike.h

HDRS = ${HDR1} ${HDR2} ${HDR3} ${HDR4} ${HDR5} ${HDR6} ${HDR7} ${HDR8} ${HDR9} ${HDR10} ${HDR11} ${HDR12} ${HDR13} ${HDR14} ${HDR15} ${HDR16} ${HDR17} ${HDR18} ${HDR19}


PROG = Coliseum 

all: ${OBJS} ${PROG} ${SRCS} ${HDRS}

${OBJS}: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} ${SRCS} -c $(@.o=.cpp)

${PROG}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${HDRS} -o ${PROG}

clean:
	rm -f  *.o *~ *.gch  ${PROG}
