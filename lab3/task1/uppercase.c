#include <stdio.h>

int main(int argc, char *argv[]) {
  char str[10090];
   int ch, n=0,i=0;

   while ((ch = getchar()) != EOF && n < 1000) {
      str[n] = ch;
      ++n;
   }

    for(n=0;str[n];n++)
      {
          if(str[n]>=97 && str[n]<=122 ){
              str[n] = str[n] - 32;
          }
      }
    
    
   while(str[i]!='\0'){
       putchar(str[i]);
       i++;
   }

    
    return 0;
}

