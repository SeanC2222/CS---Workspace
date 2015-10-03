CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
CXXFLAGS += -g
CXXFLAGS += -pedantic-errors


SRC1 = Lab7.cpp
SRC2 = util.cpp
SRCS = ${SRC1} ${SRC2}

PRO1 = Lab7
PRO2 = Util
PROG = ${PRO1} ${PRO2}

default: ${PRO1} ${PRO2}

${PRO1}: ${SRC1} 
	${CXX} ${CXXFLAGS} ${SRC1} -o ${PRO1}

${PRO2}: ${SRC2} 
	${CXX} ${CXXFLAGS} ${SRC2} -o ${PRO2}

clean:
	rm -f *.txt ${PROG}
