#include "stdio.h"
#include "stdbool.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

#define MAX_STRING_SIZE     10
#define NUMBER_OF_CARDS     14
#define NUMBER_OF_COLORS    4

typedef struct 
{
    int val;
    unsigned int color;
}card_t;

bool deckArray[53];
const char cards[NUMBER_OF_CARDS][MAX_STRING_SIZE] = {"NULL", "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
const char colors[NUMBER_OF_COLORS][MAX_STRING_SIZE] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES"};

void clearDeck(bool *decArr)
{
    memset(decArr, false, sizeof(decArr));
}

card_t drawCard(void)
{
    card_t card;
    int val;
    bool valid = false;

    srand(time(NULL));

    while(valid != true)
    {        
        val = rand();
        if(val != 0) 
        {        
            val = val %52;
            if(val == 0)    val = 52;
            if(deckArray[val] == false)
            {                
                if(val <=13)  card.color = 0;
                else if(val <= 26)    card.color = 1;
                else if(val <= 39)    card.color = 2;
                else    card.color = 3;
    
                if(val == 13 || val == 26 || val ==39 || val == 52)     card.val = 13;
                else    card.val = val % 13;
                
                deckArray[val] = true;
                valid = true;                
            }   
        }             
    }    
    return card;
}

void printCard(card_t* card)
{        
    printf("%s %s\n", colors[card->color], cards[card->val]);    
}

int main(void)
{    
    clearDeck(deckArray);
    for (int i = 0; i < 52; i++)
    {
        card_t card = drawCard();
        printCard(&card);
    }    
    return 0;
}