#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

    int len=0,n = 0,j=0,ch;
  char buf[MAX_BUF];//char array

  printf("Enter a string");
  while ((ch = getchar()) != EOF && n < 1000) {
     buf[n] = ch;
     ++n;
  }
  len=strlen(buf)-1; //length of the string
    
    int uppercase=0, lowercase=0, chars=0, words=0, lines=0, whitespaces=0,digits=0;
    if(len>=MAX_BUF){//TO CHECK IF INPUT IS NOT GREATER THAN THE MAX_BUF
            printf("Only 1024 characters are allowed\n");
            return 0;
    }
       for(n=0;buf[n];n++){
           if(buf[j]>='A' && buf[j]<='Z'){
               uppercase++;
           }
           else if(buf[j]>='a' && buf[j]<='z'){
               lowercase++;
           }
           else if (buf[j]>='0' && buf[j]<='9'){
               digits++;
           }
           else if (buf[j] == 32){
               whitespaces++;
               words++;
           }

           else if(buf[j]==10){
               lines++;
               words++;
           }
           chars++;
           j++;
       }

    printf("%d %d %d %d %d %d %d \n ",chars,words+1,lines, whitespaces,uppercase,lowercase,digits);

}

