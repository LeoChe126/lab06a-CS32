CXX=clang++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES = lab06Test01 lab06Test02 lab06Test03

all: ${BINARIES}

lab06Test01: lab06Test01.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab06Test02: lab06Test02.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab06Test03: lab06Test03.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./lab06Test01
	./lab06Test02
	./lab06Test03

clean:
	/bin/rm -f ${BINARIES} *.o
