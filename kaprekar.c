#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"

void swap(char *xp, char *yp);
int get_digit(int num);
uint16_t kaprekar_getmax(uint16_t num);
uint16_t kaprekar_getmin(uint16_t num);
int kaprekar(int val);

int main(void)
{
    FILE *fp = fopen("output.txt", "w+");
    fprintf(fp, "Kaprekar Constant, The Magic Number \"6174\"\n\n");
    for (int i = 1000 ; i < 9999; i++)
    {
        int step = kaprekar(i);
        if(step == 0)
        {
            fprintf(fp,"val: %d, step: %d, %d is not VALID number for this theory\n", i, step, i);
            printf("val: %d, step: %d, %d is not VALID number for this theory\n", i, step, i);
        }
        else
        {
            fprintf(fp,"val: %d, step: %d\n", i, step);
            printf("val: %d, step: %d\n", i, step);
        }
        
    }
    fclose(fp);
    return 0;
}

void swap(char *xp, char *yp) 
{ 
    char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int get_digit(int num)
{
    uint16_t digitCount = 0;
    while(num != 0)
    {
        num = num/10;
        if(num != 0) digitCount++;
    }
    if(num = 0) return 1;
    else return digitCount + 1;
}

uint16_t kaprekar_getmax(uint16_t num)
{
    uint16_t res;
    char arr[5];
    bool swapped;
    uint16_t n = get_digit(num);    // how many digits
    if(n > 4)   return 0;
    itoa(num, arr, 10);
    for (int i = 0; i < n-1; i++) 
    { 
        swapped = false; 
        for (int j = 0; j < n-i-1; j++) 
        {   
            if (arr[j] < arr[j+1]) 
            { 
                swap(&arr[j], &arr[j+1]); 
                swapped = true; 
            } 
        } 
    if (swapped == false) break;
    }
    if(n == 3)  arr[3] = '0';
    return atoi(arr);
}

uint16_t kaprekar_getmin(uint16_t num)
{
    uint16_t n = get_digit(num);    // how many digits
    char arr[5];
    if(n > 4)   return 0;
    itoa(num, arr, 10);
    bool swapped; 
    for (int i = 0; i < n-1; i++) 
    { 
        swapped = false; 
        for (int j = 0; j < n-i-1; j++) 
        {   
            if (arr[j] > arr[j+1]) 
            { 
                swap(&arr[j], &arr[j+1]); 
                swapped = true; 
            } 
        }  
    if (swapped == false) break;
    }
    return atoi(arr);
}

int kaprekar(int val)
{
    int stepCount = 0;
    int res = val;
    while(res != 6174)
    {
        res = kaprekar_getmax(res) - kaprekar_getmin(res);
        stepCount++;
        if(stepCount > 7) return 0;
    }
    return stepCount;
}