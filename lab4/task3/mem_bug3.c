#include <stdio.h>
#include <stdlib.h>
void makearray(int **ptr, int size,int base){

  int j;
  *ptr=(int *)malloc(size * sizeof(int));
    
  for(j=0;j<size;j++)
      (*ptr)[j] = base*=2; //doubling base
}

int main(){
  int * a1;
  makearray(&a1,5,2); 
  int * a2;
  makearray(&a2,10,3);
  int j, sum=0;

  for(j=0;j<5;j++){
    printf("%d ",a1[j]);
    sum+=a1[j];
  }
  printf("\n");

  for(j=0;j<10;j++){
    printf("%d ",a2[j]);
    sum+=a2[j];
  }
  printf("\n");

  printf("SUM: %d\n", sum);
  free(a1);
  free(a2);
}
