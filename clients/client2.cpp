#include"header.h"

int main(int argc, char **argv)
{
    Message mread, msend;
    int s;
    struct sockaddr_in serv_addr;
    struct hostent *hp;

    int nport = PORTNUM;
    nport = htons((ushort)nport);

   // Преобразует строку имени хоста в ip-адрес   
    if((hp = gethostbyname(argv[1])) == 0)
    {
        perror("Error gethostbyname()"); exit(3);
    }
  
    bzero(&serv_addr, (size_t)sizeof(serv_addr));
    bcopy(hp->h_addr, &(serv_addr.sin_addr), hp->h_length);
    serv_addr.sin_family = hp->h_addrtype;
    serv_addr.sin_port = nport;

    if((s = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror(" Error socket()"); exit(1);
    }

    fprintf(stderr, "Server's host address: %s\n", inet_ntoa(serv_addr.sin_addr));

// Соединение с сервером    
    if(connect(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("Error connect()"); exit(1);
    }


//________________________________________________________
    cout << "You are the player № 2 ;)" << endl;
    cout << "This is the field ->"<< endl;

        printf("%2d | %2d | %2d\n", 7,8,9);
        printf("____________\n");
        printf("%2d | %2d | %2d\n", 4,5,6);
        printf("____________\n");
        printf("%2d | %2d | %2d\n", 1,2,3);
        printf("\n");

    // cout <<"let's start"<<endl;
    cout<<"Your mark is '-1'"<<endl;
    

    do
    {
        if (recv(s, &mread, sizeof(Message), 0) < 0)
        {
            cout<<"Can't read\n";
            exit(2);
        }

        if(mread.end != 14)
        {
            if(mread.end == 1){
                mread.my_field.show_field();
                cout<<"You win! =)\n" ;
            }
            
            if(mread.end == -1){
                mread.my_field.show_field();
                cout<<"You lose! :(\n";
            }
            
            if(mread.end == 0){
                mread.my_field.show_field();
                cout<<"It's a draw!\n";
            }
            close(s);
                       
            exit(3);
        } 
        else
        {

            msend.my_field = mread.my_field;

            msend.my_field.show_field();

            cout << endl;
            
            msend.my_field.make_move(-1);//marker shows what type of mark to use(1 or -1)

            msend.my_field.show_field();

            cout<< "Wait...\n" << endl;

            if ( send(s, &msend, sizeof(Message), 0) < 0)
            {
                cout<<"Can't send\n";
                exit(2);
            }

        }            
    } while (1);        
    


    return 0;
}
