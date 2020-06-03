#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#include <unistd.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>



// #define PORTNUM 15000
#define PORTNUM 8080
#define FAILED "Failed to shut the server down.\n"
#define OK "Server has been shut down.\n"

using namespace std;

	

class Field{

public:
	int f[9];
	int winner; //1 & -1 - number of winner, 0 - draw  

public:
	Field();
	~Field();

	int sum();
	void check_result();
	void show_field();
	void make_move(int mark);//marker shows what type of mark to use(1 or -1)
	int check_if_full();//return 1 if field is full 	
};


class Message{

	public:
 		Field my_field;
	  	int end;
};

