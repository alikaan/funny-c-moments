#include <stdlib.h>
#include <stdio.h>

// Four command functions. They must have identical arguments.

void go_left(void) 
{
    printf("Going Left"); 
}
void go_right(void) 
{ 
    printf("Going Right");
}
void stop(void) 
{ 
    printf("Stopped"); 
}
void quit(void) 
{ 
    printf("Bye"); 
    exit(0);     
}

// An array of a two value structures.

struct {
    char cmd;			// The character
    void (*function)(void);	// a pointer to a function.
} 
commands [] = {
    {'l', &go_left},	// put the address of the function
    {'r', &go_right},	// into the function pointer
    {'s', &stop},
    {'q', &quit},
    {0, 0}		// marks the end of the array.
};

int main(void) {
    char c; 
    int i;

    while (1) 
    {
        c = getchar();	// not available on FRC
        i = 0;

        while (commands[i++].cmd) 
        {
	        if (commands[i].cmd == c) 
	        {		        
        		(*(commands[i].function))();
            }	        
        }
    }
}