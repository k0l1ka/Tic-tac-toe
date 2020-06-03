all: first_player second_player clean

realization.o: realization.cpp
	g++ -c realization.cpp

first_player: realization.o
	g++ -o first_player client1.cpp realization.o

second_player: realization.o
	g++ -o second_player client2.cpp realization.o

clean:
	rm *.o
