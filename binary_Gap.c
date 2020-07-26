#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"

char* buf;

int binaryGap(int N)
{
    int arr[32];
    int maxGap = 0, gap = 0, i = 0;    

    while (N != 0)
    {
        arr[i++] = N % 2;
        N /= 2;
    }    
    buf = (char*)calloc(32,1);
    char* pch = buf;
    for(int j = i - 1; j >= 0; j--, i--)
    {
        sprintf(pch++,"%d",arr[j]);    
    }     
    bool gapStarted = false;    
    char *ptr = buf;
    while(*ptr != NULL)
    {
        if(gapStarted)
        {
            if(*ptr == '0') gap++;
            else if (*ptr == '1')
            {                
                if (gap > maxGap)   maxGap = gap;
                gap = 0;
            }
            
        }
        else if(*ptr == '1')    
        {
            gapStarted = true;
        }
        ptr++;
    }  
    return maxGap;   
}
int main()
{
    binaryGap(529);
    getchar();
    return 0;
}