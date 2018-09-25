XX = g++ 
CXXFLAGS = -std=c++14 -Wall -g -MMD 
EXEC = mapColor
OBJECTS = main.o node.o map.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
