This is a realization of tic-tac-toe for remote players using TCP sockets.

(Server and two players should be in the same local network to run this game)

To run this code:

-- type make in your terminal. this will create executables: first, second and server.

-- you can run this executables inside three different systems

-- server does need any comand line parameters and must be executed before both first and second

-- both first and second are executed each with one parameter -> ip of server (inet addr: ***.***.*.**) of system where server is ran

-- the process of game is simple (there are some tips). two players use executable files - first and second - to send and receive info

-- at the end of game all three processes are terminated by themselves.

(NOTE: to play the game for the second time you should wait for a moment in order socket_adress to be left free by server from the previous time)
____________________________________________________________________________________________________________________________

Also a library is created over here. It is in lib/ and was created in the current directory using makefile_for_lib in the following way:
> make -f makefile_for_lib

To compile,for example, server.cpp as an alternative to the method above you need to type in terminal:
> g++ server.cpp -I./include -Llib -lTictacField -o server
