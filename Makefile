CFLAGS = -g -ansi -pedantic-errors -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

program : main.o 
	g++ -g -o program main.o $(LDFLAGS)

main.o : main.cpp
	g++ -c $(CFLAGS) main.cpp

carte.o : carte.cpp
	g++ -c $(CFLAGS) carte.cpp

clean:
	rm -f *.o program
