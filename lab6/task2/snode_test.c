#include <stdio.h>
#include "snode.h"
// CORRECTION HERE
#include "snode.c"
#include <string.h>


// global variables (data segment)

struct snode *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create snodes
  // TODO: modify func calls to snode_create
  // to match with new prototypes.
  n1 = snode_create("hello");
  n2 = snode_create("there");
  n3 = snode_create("prof");

  printf("snode_test running...\n");

  // manually "link" the nodes together.
    snode_set_next(n1,n2); //n1->next = n2
    snode_set_next(n2,n3); //n2->next = n3
    snode_set_next(n3,NULL); //n3->next = NULL

  // p points to node n1 initially
  p = n1;

  while (p != NULL) {
    // Complete this line to print the current node's string and
    // length (you can use strlen!)
      printf("str: %s - length:  %lu\n", snode_get_str(p) /*p->str*/, strlen(snode_get_str(p)/*p->str*/)); // TODO
    // TODO: add code to move p to point to next nod
      p=snode_get_next(p); //p = p->next
    // until you add this line, this program will have an infinite loop.
  }

  return 0;
}
