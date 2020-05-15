#include "stdbool.h"
#include "stdio.h"

#include "stdbool.h"

bool is_even(int n)
{  
  return n & 1;
}

int main()
{
    int n = 5;
    is_even(5) ? printf("even") : printf("odd");
    return 0;
}