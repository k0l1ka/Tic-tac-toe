#include"header.h"

using namespace std;

int mark1, mark2;
int count = 0;
 int s, ns1, ns2;
 int ppid;
 int nport;
 struct sockaddr_in serv_addr, clnt_addr1,clnt_addr2;


Message read1, send1, read2, send2;	//here we store the data for communication

void communicate(int ns, Message *s, Message *r)
{
	if (send(ns, (const void *)s, sizeof(Message), 0) < 0)
    	{
        	cout<<"Can't send\n";
			exit(2);
	    }
	
	if (recv(ns, r, sizeof(Message), 0) < 0)
	{
    	cout<<"Can't read\n";
        exit(2);
    }

}

void if_smb_won(Message mess)
{
              	mess.my_field.check_result();

                if(mess.my_field.winner!=0) // game over
                {
                        if(mess.my_field.winner == mark1)
                        {
                                cout<<"Wins player 1\n";
                                send1.my_field = mess.my_field;
                                send2.my_field = mess.my_field;
                                send1.end = 1;
                                send2.end = -1;
                        }
                        else
                        {
                                if(mess.my_field.winner == mark2)
                                {
                                        cout<<"Wins player 2\n";
                                        send1.my_field = mess.my_field;
                                        send2.my_field = mess.my_field;
                                        send1.end = -1;
                                        send2.end = 1;
                                }
                        }


                        if (send(ns1, &send1, sizeof(Message), 0) < 0)
                        {
                                cout << "Croupier can't send message to player 1\n";
                                exit(1);
                        }

                        if (send(ns2, &send2, sizeof(Message), 0) < 0)
                        {
                                cout << "Croupier can't send message to player 2\n";
                                exit(1);
                        }

                    close(s);
                    close(ns1);
                    close(ns2);

                    cout << "the end!\n";

                    exit(3);
                }

}



void check_for_draw(Message mess)
{
                if(mess.my_field.check_if_full() == 1)
                {
                    send1.end = 0;
                    send2.end = 0;
					send1.my_field = mess.my_field;
				    send2.my_field = mess.my_field;

					if (send(ns1, &send1, sizeof(Message), 0) < 0)
                        {
                                cout << "Croupier can't send message to player 1\n";
                                exit(1);
                        }

                        if (send(ns2, &send2, sizeof(Message), 0) < 0)
                        {
                                cout << "Croupier can't send message to player 2\n";
                                exit(1);
                        }

                    close(s);
                    close(ns1);
                    close(ns2);

                    cout << "the end!\n";

                    exit(3);                        
                }
}


int main(int argc, char **argv)
{
    nport = PORTNUM;
    nport = htons((u_short)nport);
    
   if((s = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error in socket() call"); exit(1);
    }
    bzero(&serv_addr, (size_t)sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = nport;

    if(bind(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror(" Error in bind call\n"); exit(1);
    }

    cout<<"Server ready!"<<endl;

    if(listen(s, 2) == -1)
    {
        perror("Error in listen() call"); exit(1);
    }


	//This was socket initialization to listen players____________________________________________

	int addrlen1, pid1;
	int nbytes1;
    int fout1;

	int addrlen2, pid2;
	int nbytes2;
    int fout2;

    bzero(&clnt_addr1, sizeof(clnt_addr1));
    addrlen1 = sizeof(clnt_addr1);

    //cout<<"players here?\n";

    if((ns1 = accept(s, (struct sockaddr *)&clnt_addr1, (socklen_t*)&addrlen1)) == -1)
    {
        	perror("Error in accept() call 1"); exit(1);
    }

	cout<< "Client @ "<< inet_ntoa(clnt_addr1.sin_addr)<<endl;

   


    bzero(&clnt_addr2, sizeof(clnt_addr2));
    addrlen2 = sizeof(clnt_addr2);

    if((ns2 = accept(s, (struct sockaddr *)&clnt_addr2, (socklen_t*)&addrlen2)) == -1)
    {
    	  	perror("Error in accept() call 1"); exit(1);
    }

	fprintf(stderr, "Client @ %s\n", inet_ntoa(clnt_addr2.sin_addr));

	//we have 2 players 
   
//+====================================	
/*	do
	{
		cout <<"Are players ready? (type y/n)"<<endl;
		char q;
		cin >> q;
	} while (q == 'y');
*/

	do
	{
		cout << "with player1"<<endl;
		
		read1.end = send1.end = read2.end = send2.end = 14;
        
		communicate(ns1, &send1, &read1);

		if (count == 0)
		{
			mark1 = read1.my_field.sum();
			count++;
			if(mark1 == 1)
				mark2 = -1;
			if(mark1 == -1)
				mark2 = 1;
		}

		read1.end = send1.end = read2.end = send2.end = 14;
        		
		if_smb_won(read1);

		read1.end = send1.end = read2.end = send2.end = 14;
     		
		check_for_draw(read1);		

        send2.my_field = read1.my_field;

//_______________________________________________________________________

		cout << "with player2"<< endl;

		read1.end = send1.end = read2.end = send2.end = 14;
        		
        communicate(ns2, &send2, &read2);

		read1.end = send1.end = read2.end = send2.end = 14;
        		
        if_smb_won(read2);

		read1.end = send1.end = read2.end = send2.end = 14;
        		
        check_for_draw(read2);

        send1.my_field = read2.my_field;

        
 	}
	while (1);

	close(s);
	 close(ns1);
	  close(ns2);
	return 0;
}

