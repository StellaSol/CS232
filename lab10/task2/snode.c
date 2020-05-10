#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

typedef struct snode {
  frame * str;
  struct snode *next;
}snode_s;

struct snode *snode_create(frame *s)
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
 snode_s * Node = (struct snode*) calloc(1,sizeof(struct snode));

 Node->str = (frame *) malloc ((strlen(s) + 1) * sizeof (char));

 strcpy(Node->str, s);
 Node->next = NULL;

 return Node;
}

void snode_destroy(struct snode * s)
{
 //TODO: implement snode_destroy
free(s->str);
free(s);
};

//static struct snode * Node;

void snode_set_next(struct snode *Node, struct snode * a){
  Node->next = a;
}

snode_s *snode_get_next(snode_s *Node){
  return Node->next;
}

frame *snode_get_str(struct snode *Node){
  return Node->str;
}

void snode_set_str(struct snode *Node, frame * str){
  Node->str = str;
}
