#include "stdio.h"
#include "stdlib.h"

int persistence(int n)
{    
    int calc = 1; 
    int ct = 0;
    if(n < 10) return 0;
    while(n != 0)
    {
        int digit = n%10;
        calc *= digit;
        n = n / 10;
        if(n == 0)
        {
            ct++;
            n = calc;
            calc = 1;   
            if(n < 10)  break;         
        }
    }
    return ct;
}

int main()
{
    int n = persistence(39);
    printf("%d", n);
    return 0;
}