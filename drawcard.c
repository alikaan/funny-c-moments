#include "stdio.h"
#include "stdbool.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"

#define MAX_STRING_SIZE     10
#define NUMBER_OF_CARDS     14
#define NUMBER_OF_COLORS    4

typedef enum{
    NONE,
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
}card_types_t;

typedef enum{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
}card_colors_t;

typedef struct 
{
    card_types_t type;
    card_colors_t color;
}card_t;

bool deckArray[53];
const char cards[NUMBER_OF_CARDS][MAX_STRING_SIZE] = {"NULL", "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
const char colors[NUMBER_OF_COLORS][MAX_STRING_SIZE] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES"};

void clearDeck(bool *decArr)
{
    memset(decArr, false, sizeof(decArr));
}

card_t drawCard(bool *deckArr)
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
            if(deckArr[val] == false)
            {                
                if(val <=13)  card.color = CLUBS;
                else if(val <= 26)    card.color = DIAMONDS;
                else if(val <= 39)    card.color = HEARTS;
                else    card.color = SPADES;
    
                if(val == 13 || val == 26 || val ==39 || val == 52)     card.type = KING;
                else    card.type = val % 13;
                
                deckArr[val] = true;
                valid = true;                
            }   
        }             
    }    
    return card;
}

void printCard(card_t* card)
{        
    printf("%s %s\n", colors[card->color], cards[card->type]);    
}

int main(void)
{    
    clearDeck(deckArray);
    for (int i = 0; i < 52; i++)
    {
        card_t card = drawCard(deckArray);
        printCard(&card);
    }    
    return 0;
}