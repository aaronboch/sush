
all: sush

sush: src/main.cpp builtin.o
	g++ -Wall src/main.cpp builtin.o -o sush

builtin.o: src/builtin.cpp
	g++ -Wall -c src/builtin.cpp