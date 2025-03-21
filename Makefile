
all: sush

sush: src/main.cpp builtin.o sushHistory.o
	g++ -Wall src/main.cpp builtin.o sushHistory.o -o sush

builtin.o: src/builtin.cpp 
	g++ -Wall -c src/builtin.cpp 

sushHistory.o: src/sushHistory.cpp
	g++ -Wall -c src/sushHistory.cpp

clean:
	rm *.o ./sush .sush_history