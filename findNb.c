#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

long long findNb(long long n)
{
    long long result = 0 ;
    while(n != 0)
    {
        result += (n*n*n);
        n--;
    }
    return result;
}

int main(void)
{
    long long n = findNb(45);
    printf("%d",n);
    return 0;
}
