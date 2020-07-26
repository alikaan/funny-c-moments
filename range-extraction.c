#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *buf;

char *range_extraction(const int* args, size_t n)
{    
  const int* ptr = args;
  buf = (char*) malloc(n*2);
  char* b = buf;
  
  int inc_ct = 0;  
  bool firstValue = true;
  
  while( n != 0 )
  {
    n--;
    if(firstValue)
    {
        firstValue = false;
        continue;
    }
    if( *ptr == *(ptr - 1) + 1 ) inc_ct++;
    else 
    {
      int ct = 0;
      if(inc_ct == 0)
      {
        ct = sprintf(b, "%d,", *ptr);
      }
      else
      {
        ct = sprintf(b, "%d-%d,", *(ptr - inc_ct), *ptr );
      }
      b += ct;
      inc_ct = 0;
    }    
    ptr++;
  }
  return buf;
}


int main()
{
    char* p = range_extraction((const int []){ -6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20 }, 20ul);
    printf("%s",p);
    return 0;
}