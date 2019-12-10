#include "stdlib.h"
#include "stdio.h"

int compare_floats(const void *a, const void *b);
int compare_integers(const void *a, const void *b);
int get_size(const void *val);

int main(void)
{
    float floatArray[] = {3.23, 3.56, 3.11, 3.22, 3.87, 3.74};
    int integerArray[] = {8, -2, 3, 12, -14, 1};  
    size_t floatArrayLen = sizeof(floatArray) / sizeof(floatArray[0]);
    size_t integerArrayLen = sizeof(integerArray) / sizeof(integerArray[0]);
    
    qsort(floatArray, floatArrayLen, sizeof(floatArray[0]), compare_floats);    
    for(int i = 0; i < floatArrayLen; i++)
    {
        printf("%f\n", floatArray[i]);
    }
    return EXIT_SUCCESS;
}

int compare_floats(const void *a, const void *b) 
{
    float fa = *((float *)a);
    float fb = *((float *)b);
    if (fa < fb)
    {
        return -1;
    }    
    if (fa > fb)
    {
        return 1;
    }    
    return 0; 
}

int compare_integers(const void *a, const void *b) 
{
    int fa = *((int *)a);
    int fb = *((int *)b);
    if (fa < fb)
    {
        return -1;
    }    
    if (fa > fb)
    {
        return 1;
    }    
    return 0; 
}

int get_size(const void *val)
{
    return ( sizeof(val) / sizeof(val[0]) );
}