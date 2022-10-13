GCC=g++
EXT=cpp
SRC=src

SFML_PATH= C:\SFML-2.5.1
SFML_INCLUDE= -I${SFML_PATH}\include
SFML_LIB= -lsfml-graphics -lsfml-window -lsfml-system
SFML_LINK= -L${SFML_PATH}\lib ${SFML_LIB}

all: link clean

compile:
ifeq (${OS},Windows_NT)
	${GCC} -c ${SFML_INCLUDE} ${SRC}/*.${EXT}
else
	${GCC} -c ${SRC}/*.${EXT}
endif

link: compile
ifeq (${OS},Windows_NT)
	${GCC} *.o -o main ${SFML_LINK}
else
	${GCC} *.o -o main ${SFML_LIB}
endif

clean:
ifeq (${OS},Windows_NT)
	del *.o
else
	rm *.o
endif