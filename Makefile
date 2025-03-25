
all: sush

sush: src/main.cpp builtin.o sushHistory.o exec.o sushEnv.o
	g++ -Wall src/main.cpp builtin.o sushHistory.o exec.o sushEnv.o -o sush

builtin.o: src/builtin.cpp 
	g++ -Wall -c src/builtin.cpp 

sushHistory.o: src/sushHistory.cpp
	g++ -Wall -c src/sushHistory.cpp

exec.o: src/exec.cpp
	g++ -Wall -c src/exec.cpp
	
sushEnv.o: src/sushEnv.cpp
	g++ -Wall -c src/sushEnv.cpp

clean:
	rm *.o ./sush .sush_history src/*.orig src/headers/*.orig tests/*.test

tests: tests/helloworld.cpp
	g++ -Wall tests/helloworld.cpp -o tests/hello.test