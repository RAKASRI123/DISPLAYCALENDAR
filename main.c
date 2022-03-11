#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int No_of_Days(int MM,int YYYY);
int DayNumber(int DD,int MM,int YYYY);
int printCalender(char *str,int Curr_YYYY,int Curr_MM,int DD,int MM,int YYYY,int End,int weekday);

int main()
{
    //printf("%s ",__DATE__);
    char mon[5],date[5],year[5],Months[15][5]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int i,DD,MM,YYYY,weekday,End,opt,Curr_YYYY,Curr_MM;
    
    mon[0]=__DATE__[0],mon[1]=__DATE__[1],mon[2]=__DATE__[2],mon[3]='\0';
    date[0]=__DATE__[4],date[1]=__DATE__[5],date[2]='\0';
    year[0]=__DATE__[7],year[1]=__DATE__[8],year[2]=__DATE__[9],year[3]=__DATE__[10],year[4]='\0';
    //printf("%s/%s/%s\n",mon,date,year);
    
    DD=atoi(date);
    for(i=0; i<12; i++)
    {
        if(strcmp(mon,Months[i])==0)
        {
            MM=i+1;
            break;
        }
    }
    YYYY=atoi(year);
    Curr_YYYY=YYYY,Curr_MM=MM;
    
    weekday=DayNumber(DD,MM,YYYY);
    End=No_of_Days(MM,YYYY);
    printCalender(Months[MM-1],Curr_YYYY,Curr_MM,DD,MM,YYYY,End,weekday);
    printf("\n");
    
    do{
        printf("\nOPTIONS:\n*Enter -1 to go 1 Month Back\n*Enter 1 to go 1 Month Front\n*Enter 2 for displaying the Particular month(Ex:2022 Jan)\n*Enter 0 to Exit\n*Enter your Option:");
        scanf("%d",&opt);
        if(opt==-1)
        {
            if(MM==1)
            {
                --YYYY;
                MM=13;
            }
            weekday=DayNumber(DD,--MM,YYYY);
            End=No_of_Days(MM,YYYY);
            printCalender(Months[MM-1],Curr_YYYY,Curr_MM,DD,MM,YYYY,End,weekday);
        }
        
        else if(opt==1)
        {
            if(MM==12)
            {
                ++YYYY;
                MM=0;
            }
            weekday=DayNumber(DD,++MM,YYYY);
            End=No_of_Days(MM,YYYY);
            printCalender(Months[MM-1],Curr_YYYY,Curr_MM,DD,MM,YYYY,End,weekday);
        }
        
        else if(opt==2)
        {
            char Month[5];
            printf("Enter the Year and Month(Ex:2022 Jan):");
            scanf("%d %s",&YYYY,Month);
            for(i=0; i<12; i++)
            {
                if(strcmp(Month,Months[i])==0)
                {
                    MM=i+1;
                    break;
                }
            }
            weekday=DayNumber(DD,MM,YYYY);
            End=No_of_Days(MM,YYYY);
            printCalender(Months[MM-1],Curr_YYYY,Curr_MM,DD,MM,YYYY,End,weekday);
        }
        else if(opt!=0)
            printf("Invalid Option");
        printf("\n");
    }while(opt!=0);
    return 0;
}
