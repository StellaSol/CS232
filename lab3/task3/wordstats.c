#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0}; //Array for letter frequencies
  int len=0, i=0,j=0,k;
  char buf[MAX_BUF];//char array

  printf("Enter a string");
  fgets(buf,MAX_BUF,stdin);//taking input for the array
    
  len=strlen(buf)-1; //length of the string
    
   do {
      if(len<=MAX_BUF){//TO CHECK IF INPUT IS NOT GREATER THAN THE MAX_BUF
          if(buf[i]>=97 && buf[i]<=122 ){//This will check frequencies of lowercase
              k = buf[i] - 97; 
              letter_frequency[k]++;
              i++;
          }
          else if(buf[i]>=65 && buf[i]<=90 ) { //This will check freq of uppercase
              k = buf[i] - 65;
              letter_frequency[k]++;
              i++;
          }
          else{ //For
              i++;
          }
          j++;
      }
      
      else{
          printf("Only 1024 characters are allowed\n");
          break;
      }
      
  } while (j<len);

  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}
