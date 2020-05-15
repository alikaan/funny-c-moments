#include "stdio.h"
#include "stdlib.h"

//char buffer[1000];
char *buffer;

char* pattern(const int n){
  if(n < 1)  return "";	  
  long len = ( (n*(n+1)) / 2 ) + n + 1;
  buffer = (char*)malloc( len );
  char *b = buffer;
  for(int i = 1; i <=  n; i++)
  {
    for(int j = 1; j <= i; j++)
    {
        b += sprintf(b, "%d", i);        
    }
    if (i != n)  *b++ = '\n';
  }
  *b = '\0';
  free(buffer);
  return buffer;
}

int main()
{
    char *s = pattern(30);
    printf("%s", s);

    return 0;
}
