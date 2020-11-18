#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool validSolution(unsigned int board[9][9]){
    bool numbers[10];

    memset(&numbers, false, sizeof(numbers));
    for(int i = 0; i < 3; i++)
    {
       for(int j = 0; j < 3; j++)
       {
           numbers[board[i][j]] = true;
       }
    }
    for(int k = 1; k < 10; k++)  if(numbers[k] == false) return false;

    memset(&numbers, false, sizeof(numbers));
    for(int i = 3; i < 6; i++)
    {
       for(int j = 3; j < 6; j++)
       {
           numbers[board[i][j]] = true;
       }
    }
    for(int k = 1; k < 10; k++)  if(numbers[k] == false) return false;

    memset(&numbers, false, sizeof(numbers));
    for(int i = 6; i < 9; i++)
    {
       for(int j = 6; j < 9; j++)
       {
           numbers[board[i][j]] = true;
       }
    }
    for(int k = 1; k < 10; k++)  if(numbers[k] == false) return false;

   return true;
}

int main()
{
    unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}}; 
                             
unsigned int example2[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                              {6, 7, 2, 1, 9, 0, 3, 4, 8},
                              {1, 0, 0, 3, 4, 2, 5, 6, 0},
                              {8, 5, 9, 7, 6, 1, 0, 2, 0},
                              {4, 2, 6, 8, 5, 3, 7, 9, 1},
                              {7, 1, 3, 9, 2, 4, 8, 5, 6},
                              {9, 0, 1, 5, 3, 7, 2, 1, 4},
                              {2, 8, 7, 4, 1, 9, 6, 3, 5},
                              {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    printf("Result: %d\n",validSolution(example1));
    printf("Result: %d\n",validSolution(example2));
    return 0;
}