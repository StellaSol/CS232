/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>



#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

int main()
{
  char* Strings = NULL;
  int i,j;

  Strings = realloc(Strings, NUM* sizeof(char)); //reallocate memory for Strings array
  if (Strings == NULL) //Checked if it allocated memory
  {
      printf("failed to allocate memory\n");
      return 0;
  }
    
  printf("Please enter %d strings, one per line:\n", NUM);
  fgets(Strings, NUM, stdin); //since it is a 1D array, no loop
    
  int n = strlen(Strings); //length of the string which includes the newline char *REMINDER*

  puts("\nHere is the string in the order you entered:");
  int c;
  for(c=0;c<n;c++){
    printf("%c", Strings[c]);
  }
    
  /* Bubble sort */
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (Strings[j] > Strings[j+1])
            {
                //pointers that point to the addresses of the element of the String array
                char *ptr1 = &Strings[j];
                char *ptr2 = &Strings[j+1];
                //swap using pointers
                char temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
            }
        }
    }
    
    /* Output sorted list */
    
  puts("\nIn alphabetical order, the strings are:");
  for(c=0;c<n;c++){
      printf("%c", Strings[c]);
  }
    free(Strings);
    return 0;
}
