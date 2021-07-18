all : main

%.o : %.cpp
	g++ -c -g -Wall -o %@ $^

main : main.o tree234.o
	g++ -g -Wall -o %@ %^

clean :
	rm -f main *.o