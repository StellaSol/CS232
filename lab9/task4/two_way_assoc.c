#include <stdio.h>

int tag[2][4];
int mru[4] = {1,1,1,1};

int main( )
{
    int addr;
    int hits, accesses;
    FILE *fp;

    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    while (fscanf(fp, "%x", &addr) > 0) {
        /********* YOUR CODE HERE ************/
        accesses+=1;
        printf("%3d: 0x%08x ", accesses, addr);

        int index = (addr >> 2) & 3;
        int x;
        int tag_ = addr | 0xf;

        //find tag value
        for(x = 0; x < 2; x++) {
          if(tag[index][x] == tag_) {
            printf("Hit%d ", x);
            mru[index] = x;
            hits++;
            break;
          }
        }

        if(x == 2) {
          printf("Miss ");
          int n = (mru[index] + 1) % 2;
          tag[index][n] = tag_;
          mru[index] = n;
        }

        //print the tag arrays for summary
        for(int i = 0; i < 4; i++) {
          printf(" 0x%08x \n", tag[i][0]);
          printf(" 0x%08x \n", tag[i][1]);
        }

        //print the mru array for summary
        for(int i = 0; i < 4; i++) {
          printf("%d ", mru[i]);
        }
        printf("\n");
    }
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    close(fp);
}
