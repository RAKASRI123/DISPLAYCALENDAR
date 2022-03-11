#include <stdio.h>

int DayNumber(int DD,int MM,int YYYY)
{
    int weekday,start=1;
    weekday=(start+= MM < 3 ? YYYY-- : YYYY - 2, 23*MM/9 + start + 4 + YYYY/4- YYYY/100 + YYYY/400)%7;
    return weekday;
}
