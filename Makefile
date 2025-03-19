
all: sush

sush: src/main.cpp
	g++ -Wall src/main.cpp -o sush