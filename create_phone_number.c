#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char *buffer;

char* likes(size_t n, const char *const names[n]) {
  buffer = (char*)malloc(100);
  switch(n) {
    case 0:  strcpy(buffer,"no one likes this"); break;
    case 1:  sprintf(buffer, "%s likes this",names[0] ); break;
    case 2:  sprintf(buffer, "%s and %s like this",names[0], names[1] ); break;
    case 3:  sprintf(buffer, "%s, %s and %s like this", names[0], names[1], names[2] ); break;
    default:  sprintf(buffer, "%s, %s and %d others like this", names[0], names[1], (int)(n-2) ); break;
    }
    return buffer;
}