#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *buffer;

typedef struct
{
  bool start;
  int count;
  int start_index;
  int end_index;
}repeat_t;

char *range_extraction(const int *args, size_t n)
{    
  const int *ptr = args;  
  buffer = (char*) malloc(sizeof(char)*1000);
  char* b = buffer;  

  repeat_t repeat  = { .start = false, .count = 0, .start_index = 0, .end_index = 0 };
    
  for(int i = 0; i < (int)n; i++)
  {
    if(ptr[i] + 1 == (ptr[i+1] )) 
    {
      repeat.start = true;
      repeat.count++;
      if(repeat.count == 1) 
      {        
        repeat.start_index = i;
      }      
    }
    else
    {
      if(repeat.start)
      {        
        repeat.end_index = i;
        if(repeat.count >= 2)
        {
          b += sprintf(b, "%d-%d,", ptr[repeat.start_index], ptr[repeat.end_index] );
        }
        else
        {
          b += sprintf(b, "%d,%d,", ptr[repeat.start_index], ptr[i]);
        }        
        repeat.start = false;
        repeat.count = 0;
      }      
      else
      {
        b += sprintf(b, "%d,", ptr[i]);
      }      
    }              
  }
  *(b-1) = '\0';
  printf("%s\n", buffer);
  return buffer;
}

int main()
{
    range_extraction((const int[]){ -6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20 }, 20ul);
    range_extraction((const int[]){ -6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20 }, 20ul);
    range_extraction((const int[]){ -3,-2,-1,2,10,15,16,18,19,20 }, 10ul);
    range_extraction((const int[]){ -5,-4,-3,-2,-1,0,1,2,3,4,5 }, 11ul);
    range_extraction((const int[]){ -5,-4,-2,-1,1,2,4,5 }, 8ul);
    range_extraction((const int[]){ 9 }, 1ul);
    return 0;
}