all: first server second

realization.o: realization.cpp
	g++ -c realization.cpp

first: realization.o
	g++ -o first client1.cpp realization.o

second: realization.o
	g++ -o second client2.cpp realization.o 

server: realization.o
	g++ -o server server.cpp realization.o

clean:
	rm *.o

