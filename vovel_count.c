#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t get_count(const char *s)
{
  char vovels[5] = "aeiou";
  const char *p = s;
  int ct = 0;
  do
  {
    for(int i = 0; i < 5; i++)
    {
        if(*p == vovels[i]) 
        {
            ct++;
            break;
        }
    }
  } while (*p++ != '\0');
  return ct;
}

int main()
{
    char buffer[] ="abracadabra";
    printf("%s ---> vovel count: %d",buffer,get_count(buffer));
    return 0;
}