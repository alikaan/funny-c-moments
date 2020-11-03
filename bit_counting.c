#include "stdio.h"

size_t countBits(unsigned int value)
{
    unsigned int ct = 0;
    while(value)
    {
        ct += value & 1;
        value >>= 1;
    }
    return ct;
}

int main(void)
{
    int val = 1234;
    printf("%d , %d\n", val, countBits(val));
    return 0;
}