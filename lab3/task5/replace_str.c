/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdio.h>
#include <string.h> 

void CS232(char* src) {
     char *srcptr, *replaceptr;
     int i=0;
     // char *srcptr, *replaceptr;
     int srcLength = strlen(src);
     char replacement[16] = "232 is awesome!";
     srcptr = src;
     replaceptr = replacement;
     if (srcLength <=15) {
         for (i = 0; i < 15; i++)
          *srcptr++ = *replaceptr++;
     }
}

char * replace_string(char *str) {
    CS232(str);
    return str;
}

int main(int argc, char ** argv) {
    char str[16];
    char * ret = replace_string(str);
    printf("replaced string = %s\n", ret);
    return 0;
}
