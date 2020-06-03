This is a realization of tic-tac-toe for remote players using TCP sockets.

To run this code:

-- type "make" in your terminal. this will create executables: "first", "second" and "server".

-- you can run "server" at a web server (port is 8080)

-- "server" does need any comand line parameters and must be executed before both "first" and "second"

-- both "first" and "second" are executed with one cmnd line parameter -> public ip of web server(inet addr: ***.***.*.**)

-- the process of game is simple (there will be some tips). two players use executable files - "first" and "second" - to send and receive messages from "server" that is a mediator between them.

-- at the end of game all three processes are terminated by themselves.
____________________________________________________________________________________________________________________________

Also a library is created over here. It is in lib/ and was created in the current directory using makefile_for_lib in the following way:
> make -f makefile_for_lib

An alternative to the method above to compile server.cpp, for example, you need to type in terminal:
> g++ server.cpp -I./include -Llib -lTictacField -o server
