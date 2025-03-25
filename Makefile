
all: sush

sush: src/main.cpp builtin.o history.o exec.o env.o
	g++ -Wall src/main.cpp builtin.o history.o exec.o env.o -o sush

builtin.o: src/builtin.cpp 
	g++ -Wall -c src/builtin.cpp 

history.o: src/history.cpp
	g++ -Wall -c src/history.cpp

exec.o: src/exec.cpp
	g++ -Wall -c src/exec.cpp
	
env.o: src/env.cpp
	g++ -Wall -c src/env.cpp

clean:
	rm *.o ./sush .sush_history src/*.orig src/headers/*.orig tests/*.test

.PHONY tests: tests/helloworld.cpp 
	g++ -Wall tests/helloworld.cpp -o tests/hello.test

.PHONY astyle: 
	astyle src/headers/*
	astyle src/* 
