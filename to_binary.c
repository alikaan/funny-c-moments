#include <stdio.h>
#include <stdlib.h>

int arr[32];
char* buf;

unsigned long long to_binary(unsigned short num)
{
  static int i = 0;
  arr[i++] = num % 2;
  num /= 2;
  if(num == 0) {    
    buf = (char*)calloc(32,1);
    char* pch = buf;
    for(int j = i - 1; j >= 0; j--, i--)
    {
        sprintf(pch++,"%d",arr[j]);    
    }  
    i = 0;
    return strtoull(buf, NULL, 10);
  }
  else  return to_binary(num); 
}

int main()
{ 
  printf("%llu\n",to_binary(18547));
  return 0;
}
