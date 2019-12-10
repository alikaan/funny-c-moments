#include <stdio.h>
#include "stdbool.h"

#define CHECKBIT(var,pos)   ( (var) & (1<<(pos)) )

void printBits(int val, int n)
{
    for(int i = n; i >= 0; i--)
    {          
        if(val & 1<< i)     printf("1");        
        else    printf("0");        
    }
    printf("\n");
}

int modifyBit(int n, int p, int b) 
{ 
	int mask = 1 << p; 
    printf("mask : ");
    printBits(mask,8);
	return (n & ~mask) | ((b << p) & mask); 
} 

bool checkBit (int n, int b)
{
    n >>= b;
    if(n & 1)   return true;
    else    return false;    
}

int main(void)
{
    int test = 0;
    test = modifyBit(test, 0,1);
    printf("dec : %d\n", test);
    printf("bin : ");
    printBits(test,7);
    printf("\n");

    test = modifyBit(test, 5,1);
    printf("dec : %d\n", test);
    printf("bin : ");
    printBits(test,7);
    printf("\n");

    test = modifyBit(test, 2,1);
    printf("dec : %d\n", test);
    printf("bin : ");
    printBits(test,7);
    printf("\n");

    test = modifyBit(test, 3,1);
    printf("dec : %d\n", test);
    printf("bin : ");
    printBits(test,7);
    int as=1;
    /*if(checkBit(test, 0) )*/
    if( CHECKBIT(test,1) )  printf("Choised bit is 1");
    else    printf("Choised bit is 0");
    printf("\n");
    return 0;
}

