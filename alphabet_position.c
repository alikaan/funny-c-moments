#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *buffer;

char *alphabet_position(char *text) {
  buffer = (char*)calloc(strlen(text)*2,sizeof(char));
  char *b = buffer;
  int len = 0;
  do
  {
    if(isalpha(*text))
    {
        if(*text < 91)  len = sprintf(b,"%d ", *text - 64);
        else    len = sprintf(b,"%d ", *text - 96);   
        b += len;
    }
  }while(*text++ != '\0');
  *(b - 1) = '\0';
  return buffer;
}

int main()
{
    char *ptr = alphabet_position("hello from the outside");
    printf("%s", ptr);
}