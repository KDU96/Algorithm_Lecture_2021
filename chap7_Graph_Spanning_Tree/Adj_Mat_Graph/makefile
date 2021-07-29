all : main

%.o : %.cpp
	g++ -c -g -Wall -o $@ $^

main : adjMat_graph.o main.o
	g++ -g -Wall -o $@ $^

clean :
	rm -f *.o main
