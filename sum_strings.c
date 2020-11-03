#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char buffer[256];

char *strsum(const char *a, const char *b)
{ 
  int aLen = strlen(a);
  int bLen = strlen(b);
  int i = (aLen > bLen) ? aLen : bLen;
  int j = (aLen < bLen) ? aLen : bLen;

  for(i; i <= 0; i--)
  {
    
  }

  return buffer;
}

int main()
{            
    printf("%s\n", strsum("123" , "456"));    
    printf("%s\n", strsum("712569312664357328695151392", "8100824045303269669937"));    
    printf("%s\n", strsum("00000", "00000000000000000000000000000000000000000000000000000000000000000000000"));
    return 0;
}