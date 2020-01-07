#include "stdio.h"
#include "stdbool.h"
#include "time.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"

#define MAX_STRING_SIZE     10
#define NUMBER_OF_CARDS     14
#define NUMBER_OF_COLORS    4

#define END_OF_CLUBS        13
#define END_OF_DIAMONDS     26
#define END_OF_HEARTS       39
#define END_OF_SPADES       52

#define NUMBER_OF_PLAYERS   2

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

typedef enum{
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH,
}ranks_t;

typedef struct {
    card_types_t type;
    card_colors_t color;
}card_t;

typedef struct 
{
    char name[20];
    card_t cards[5];
    ranks_t rank;
    uint16_t highCard;
}player_t;

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
                if(val <= END_OF_CLUBS)  card.color = CLUBS;
                else if(val <= END_OF_DIAMONDS)    card.color = DIAMONDS;
                else if(val <= END_OF_HEARTS)    card.color = HEARTS;
                else    card.color = SPADES;
    
                if(val == END_OF_CLUBS || val == END_OF_DIAMONDS || val ==END_OF_HEARTS || val == END_OF_SPADES)     card.type = KING;
                else    card.type = val % 13;
                
                deckArr[val] = true;
                valid = true;                
            }   
        }             
    }    
    return card;
}

void startMatch(player_t *player, card_t *board, unsigned int numberOfPlayer)
{
    clearDeck(&deckArray[0]);
    for (int i = 0; i < numberOfPlayer; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            player[i].cards[j] = drawCard(deckArray); 
            printf("%s's %d. card is %s %s\n", player[i].name, j, 
                                colors[player[i].cards[j].color], cards[player[i].cards[j].type]);            
        }
    } 
}

void printCard(card_t* card)
{        
    printf("%s %s\n", colors[card->color], cards[card->type]);    
}

void drawAllCards()
{
    for (int i = 0; i < 52; i++)
    {
        card_t card = drawCard(deckArray);
        printCard(&card);
    }
}

int main(void)
{    
    clearDeck(&deckArray[0]);
    card_t board[3];
    player_t player[NUMBER_OF_PLAYERS];
    strcpy(player[0].name, "ali kaan");
    strcpy(player[1].name, "kivanc");

    startMatch(player, board, NUMBER_OF_PLAYERS);  
    
    for(int i = 0; i < 3; i++) 
    {
        board[i] = drawCard(deckArray);
        for(int j = 0; j < NUMBER_OF_PLAYERS; j++)
        {
            player[j].cards[i + 2] = board[i];
        }
        printf("Board's %d. card is %s %s\n", i, colors[board[i].color], cards[board[i].type] );                                
    }
    return 0;
}
