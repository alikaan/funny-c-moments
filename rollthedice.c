#include "stdio.h"
#include "stdbool.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

bool rollTheDice(int *buf, int turn, int diceNumber);

#define DICE_NUM        8
#define TURN_NUM        8

int main(void)
{
    int tbuf[TURN_NUM];
    rollTheDice(tbuf,TURN_NUM,DICE_NUM);    
    for(int i = 0; i < TURN_NUM; i++ )
    {
        printf("%d\n", tbuf[i]);
    }
    return 0;
}

bool rollTheDice(int *buf, int turn, int maxDiceNumber)
{
    int tval = 0;    
    if(maxDiceNumber > 8) return false;
    srand(time(NULL));
    for(int i = 0; i < turn; i++)
    {
        tval = (rand()) % maxDiceNumber;
        if(tval == 0)   
        {
            *(buf + i) = maxDiceNumber;
        }
        else
        {
            *(buf + i) = tval;
        }    
    }    
    return true;
}