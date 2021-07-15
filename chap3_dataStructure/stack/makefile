all : main

stack.o : stack.cpp
	g++ -c -g -Wall -o stack.o stack.cpp

main.o : main.cpp
	g++ -c -g -Wall -o main.o main.cpp

main : main.o stack.o
	g++ -g -Wall -o $@ $^

clean :
	rm main.o stack.o main
