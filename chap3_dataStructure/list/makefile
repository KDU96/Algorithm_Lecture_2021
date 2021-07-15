all : main

list.o : list.cpp
	g++ -c -g -o $@ $<

main.o : main.cpp
	g++ -c -g -o $@ $<

main : main.o list.o
	g++ -g -o $@ $^

clean :
	rm -f main main.o list.o
