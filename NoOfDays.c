#include <stdio.h>

static int Local_No_of_Days(int MM,int YYYY)
{
    int End;
    switch(MM)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            End=31;
            break;
        case 4:case 6:case 9:case 11:
            End=30;
            break;
        case 2:
            if(YYYY%400==0 || (YYYY%4==0 && YYYY%100!=0))
                End=29;
            else
                End=28;
            break;
    }
    return End;
}

int No_of_Days(int MM,int YYYY)
{
	return Local_No_of_Days(MM,YYYY);
}	
