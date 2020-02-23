/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int stringCompare(char str1[], char str2[]) {
    int i = 0;
    int check = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) { //Checks if the first string is equal to the second string.
            check = 1;            //If it passes through check, then it is not equal and will be further evaluated
            break;
        }
        i++;
        }
    if (check == 0 && str1[i] == '\0' && str2[i] == '\0') { //If they are equal then no need to compare
        return 0;
    }
    
    else {
        return (str1[i] - str2[i]);
    }
}

//Since the string library function can't be used, a stringCopy function was created instead :D
void stringCopy(char destination[], char source[]) {
    int i = 0;
    while (source[i] != '\0') {// This loop keeps running until the end of the source string
        destination[i] = source[i];//copies character by character until reaching the end
        i++;
    }
    destination[i] = '\0'; //has to have null char at end
}

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
          if (stringCompare(Strings[j], Strings[j + 1]) > 0)
          {
              // Swapping Strings[j] and Strings[j+1]
              stringCopy(Temp, Strings[j]);
              stringCopy(Strings[j], Strings[j + 1]);
              stringCopy(Strings[j + 1], Temp);
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
