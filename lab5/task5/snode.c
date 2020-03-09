#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(void *s)
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
    struct snode *node;
    node = malloc(sizeof(struct snode));
    node->data = s;
    node->next = NULL;
    return node;
}
void snode_destroy(struct snode * s)
{

    s=NULL;//delete the node
    free(s->data); //free the string
    free(s); //free the node
 
}
 
