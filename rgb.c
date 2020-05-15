#include <stdio.h>
#include <string.h>

const char hexes[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'};
char tbuf[10];

int rgb(int r, int g, int b, char *output)
{
   int list[3] = {r, g, b};
   
   for(int i = 0; i < 3; i++)
   {
     int first = list[i] / 16;
     double percent = list[i]/16.00 - first;
     int second = first * percent;
     *output++ = hexes[first];
     *output++ = hexes[second];
   }
   *output = '\0';
   return 0; 
}

int main(void)
{
    rgb(123,213,163,tbuf);
    printf("%s",tbuf);
    return 0;
}