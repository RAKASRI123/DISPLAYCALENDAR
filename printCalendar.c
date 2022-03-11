#include <stdio.h>

int printCalender(char *str,int Curr_YYYY,int Curr_MM,int DD,int MM,int YYYY,int End,int weekday)
{
    printf("\n");
    printf("%d %s\n",YYYY,str);
    printf("SUN  MON  TUE  WED  THU  FRI  SAT\n");
    int i;
    for(i=0; i<5*weekday;i++)
    {
        printf(" ");
    }
    
    for(i=1; i<=End; i++)
    {
        if(DD==i && MM==Curr_MM && YYYY==Curr_YYYY)
            printf("\b|%02d|  ",i);
        else
            printf("%02d   ",i);
        weekday++;
        if(weekday%7==0)
            printf("\n");
    }
}

