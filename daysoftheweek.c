// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#include "stdio.h"
#include "string.h"

char days[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat","Sun"};

int GetDayIndex(char *day)
{
    for(int i = 0; i < 7; i++)
    {
        if(memcmp(day, &days[i][0], 3) == 0)
        {
            printf("input index : %d\n", (i+1));
            return i + 1;
        }
    }
}

char * solution(char *S, int K) {
    // write your code in C99 (gcc 6.2.0)
    int currentIndex, nextIndex = 0;
    currentIndex = GetDayIndex(S);
    nextIndex += (K+7)%7;
    if(nextIndex > 7) nextIndex -= 7;
    nextIndex += currentIndex;
    if(nextIndex > 7) nextIndex -= 7;
    return &days[nextIndex - 1][0];
}

int main(void)
{
    char today[4] = "Sat";
    int count = 23;
    printf("Today is %s. After %d days, It's %s", today, count, solution(today, count) );
    return 1;
}