#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ROMAN_START,
    ROMAN_I,
    ROMAN_V,
    ROMAN_X,
    ROMAN_L,
    ROMAN_C,
    ROMAN_D,
    ROMAN_M,
    ROMAN_END
}romanValues_t;

int romanToDecimal(char *romanVal); // convert roman numeral to decimal value 
romanValues_t getRomanValue(char *val); // get type of roman numeral
int getDecimalValueOfRomanValue(romanValues_t val); // get decimal value of roman numeral


int main(int argc,char* argv[]) 
{ 
    int counter; 
    char *val = argv[0];
    
    printf("You have entered %d arguments\n", argc); 
    printf("Your input is: %s\n", val);
    
    /* Test */
    char romanNumeral[10] = "MCMIV";
    int result = romanToDecimal(romanNumeral);
    
    printf("Input roman numeral : %s\n", romanNumeral);
    printf("Output decimal value : %d\n", result);
    return 0; 
}

int romanToDecimal(char *romanVal)
{
    char *p = romanVal;
    
    romanValues_t prevRomanVal = ROMAN_END;
    romanValues_t currentRomanVal = ROMAN_START;
    int result = 0;
    int len = strlen(p);
    
    for(int i = 0; i < len; i++)
    {
        currentRomanVal = getRomanValue(p);
        if(currentRomanVal > prevRomanVal)
        {
            printf("Current roman val is higher than previous roman val\n");
            result -= getDecimalValueOfRomanValue(prevRomanVal);
            result += ( getDecimalValueOfRomanValue(currentRomanVal) - getDecimalValueOfRomanValue(prevRomanVal) );
            printf("Current Result : %d\n", result);
        }
        else
        {
            result += getDecimalValueOfRomanValue(currentRomanVal);
            printf("Current Result : %d\n", result);
        }
        p++;
        prevRomanVal = currentRomanVal;
    }
    printf("Final Result : %d\n", result);
    return result;
}

romanValues_t getRomanValue(char *val)
{
    if(*val == 'I')         return ROMAN_I;
    else if(*val == 'V')    return ROMAN_V;
    else if(*val == 'X')    return ROMAN_X;
    else if(*val == 'L')    return ROMAN_L;
    else if(*val == 'C')    return ROMAN_C;
    else if(*val == 'D')    return ROMAN_D;
    else if(*val == 'M')    return ROMAN_M;
}

int getDecimalValueOfRomanValue(romanValues_t val)
{
    switch(val)
    {
        case ROMAN_I:   return 1;
        case ROMAN_V:   return 5;
        case ROMAN_X:   return 10;
        case ROMAN_L:   return 50;
        case ROMAN_C:   return 100;
        case ROMAN_D:   return 500;
        case ROMAN_M:   return 1000;
    }
}


