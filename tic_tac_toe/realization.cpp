#include "header.h"


Field::Field()
{
	for (int i = 0; i < 9; i++)
	{
		f[i] = 0;	
	}
	
	winner = 0;
};

int Field:: sum()
{
        int s = 0;
        for (int i = 0; i < 9; i++)
                s += f[i];

        return s;      
} 

int Field:: check_if_full()
{
	int count = 0;
	for (int i = 0; i < 9; i++)
        {
                if (f[i] == 0)
			count++;
        }
	if (count == 0)
		return 1;
	else 
		return 0;

}



void Field::check_result()
{
    
	if(f[0] == f[1] && f[1] == f[2] && f[0] != 0 && f[0] == 1)
        {
                winner =  1;
        }
        if(f[3] == f[4] && f[4] == f[5] && f[3] != 0 && f[3] == 1)
        {
                winner =  1;
        }
        if(f[6] == f[7] && f[7] == f[8] && f[6] != 0 && f[6] == 1)
        {
                winner =  1;
        }
        if(f[0] == f[3] && f[3] == f[6] && f[0] != 0 && f[0] == 1)
        {
                winner =  1;
        }
        if(f[1] == f[4] && f[4] == f[7] && f[1] != 0 && f[1] == 1)
        {
                winner =  1;
        }
        if(f[2] == f[5] && f[5] == f[8] && f[2] != 0 && f[2] == 1)
        {
                winner =  1;
        }
        if(f[0] == f[4] && f[4] == f[8] && f[0] != 0 && f[0] == 1)
        {
                winner =  1;
        }
 	if(f[6] == f[4] && f[4] == f[2] && f[6] != 0 && f[6] == 1)
        {
                winner =  1;
        }
	
//___________________________________________________________________
	if(f[0] == f[1] && f[1] == f[2] && f[0] != 0 && f[0] == -1)
        {
                winner = -1;
        }
        if(f[3] == f[4] && f[4] == f[5] && f[3] != 0 && f[3] == -1)
        {
                winner =  -1;
        }
        if(f[6] == f[7] && f[7] == f[8] && f[6] != 0 && f[6] == -1)
        {
                winner =  -1;
        }
        if(f[0] == f[3] && f[3] == f[6] && f[0] != 0 && f[0] == -1)
        {
                winner =  -1;
        }
        if(f[1] == f[4] && f[4] == f[7] && f[1] != 0 && f[1] == -1)
        {
                winner =  -1;
        }
        if(f[2] == f[5] && f[5] == f[8] && f[2] != 0 && f[2] == -1)
        {
                winner =  -1;
        }
        if(f[0] == f[4] && f[4] == f[8] && f[0] != 0 && f[0] == -1)
        {
                winner = -1;
        }
 	if(f[6] == f[4] && f[4] == f[2] && f[6] != 0 && f[6] == -1)
        {
                winner =  -1;
        }
        	
};

void Field::show_field()
{
        printf("%2d | %2d | %2d\n", f[6], f[7], f[8]);
        printf("____________\n");
        printf("%2d | %2d | %2d\n", f[3], f[4], f[5]);
        printf("____________\n");
        printf("%2d | %2d | %2d\n", f[0], f[1], f[2]);
        printf("\n");
//        fflush(stdout);
};

void Field::make_move(int mark)
{
	int pos;
	
	cout << "It's your turn!\n" << "Enter position:" << endl;
	cin >> pos;
	
	while( (pos < 1) or (pos > 9) or (f[pos-1]!= 0) )
	{
		cout << "Enter the correct one!!!\n";
		cin >> pos;
	}			
	
	f[pos-1] = mark;
};



Field::~Field()
{
	//nothong to do
};

