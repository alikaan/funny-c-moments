#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

char *buffer;
const char *src = "Tes+t+";

char *rot13(const char *src)
{
    int len = strlen(src);
    buffer = (char*) calloc (100,sizeof(char));
    char *b = buffer;
    for(int i = 0; i < len; i++)
    {
        if(isalpha(src[i]))
        {
            if(src[i] < 78 )   *b++ = src[i] + 13;
            else if(src[i] < 91) *b++ = src[i] - 13;
            else if(src[i] < 110) *b++ = src[i] + 13;
            else if(src[i] < 123) *b++ = src[i] - 13;           
        }
        else    *b++ = src[i];
    }
    return buffer;
}

int main()
{
    printf("%s",rot13(src));
}