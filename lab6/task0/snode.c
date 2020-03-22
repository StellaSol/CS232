#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode {
  //TODO: change str to dynamic allcoation
  char * str;
  struct snode *next;
};


void snode_set_str(struct snode *snode_p ,char *s){
    strcpy(snode_p->str, s);
}

char* snode_get_str(struct snode *snode_p ){
    return snode_p->str;
}

void snode_set_next(struct snode *snode_p, struct snode *s){
    snode_p->next = s;
}

struct snode* snode_get_next(struct snode *snode_p){
    return snode_p->next;
}

struct snode *snode_create(char *s)
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
    struct snode *node;
    node = malloc(sizeof(struct snode));
    int length = strlen(s);
    node->str=(char*)malloc(length + 1); /*node->str*/
    snode_set_str(node,s);
    snode_set_next(node,NULL); //node->next = NULL
    return node;
}

void snode_destroy(struct snode * s)
{
    free(snode_get_str(s)); //free s->str
    free(s);
}
 
