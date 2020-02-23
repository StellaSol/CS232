/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */


int main()
{
  char Strings[NUM][LEN];
  char Temp[LEN] = { 0 }; //Created a temporary array to store all the characters for the swaps so all swaps will be complete
  int i, j, n;
    
  printf("Please enter %d strings, one per line:\n", NUM);
    for (i = 0; i < 30; i++) {
         fgets(Strings[i], LEN, stdin);
         Strings[i][strlen(Strings[i]) - 1] = '\0'; //Removing that extra new line character from each input string
    }

  puts("\nHere are the strings in the order you entered:");
  for (i = 0; i < 30; i++) {
      printf("%s\n", Strings[i]);
  }

  /* Bubble sort */
  n = 30;// Length of the rows
  for (i = 1; i < n; i++) { //Loop for the rows
      for (j = 0; j < n - i; j++) { //loop through the columns
          if (strcmp(Strings[j], Strings[j + 1]) > 0)
          {
              // Swapping Strings[j] and Strings[j+1]
              strcpy(Temp, Strings[j]);
              strcpy(Strings[j], Strings[j + 1]);
              strcpy(Strings[j + 1], Temp);
          }
      }
  }

  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");
  for (i = 0; i < 30; i++) {
      printf("%s\n", Strings[i]);
  }
    
    return 0;

}
