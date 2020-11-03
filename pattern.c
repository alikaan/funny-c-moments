#include "stdio.h"
#include "stdlib.h"

char buffer[1000];

char* pattern(const int n){
  char *b = buffer;

  if(n < 1)  return "";	  
  for(int i = 1; i <=  n; i++)
  {
    for(int j = 1; j <= i; j++)
    {
        b += sprintf(b, "%d", i);                
    }
    if (i != n)  *b++ = '\n';
    //*b++ = '\n';
  }
  *b = '\0';
  return buffer;
}

int main()
{
    char *s = pattern(64);
    printf("%s", s);

    return 0;
}
