#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>


/*void snode_set_str(char *s){ //set string to a node
    struct snode *node;
    node.str=s;
}

struct snode_get_str(struct snode *s){ //receives the node to get the string
    return s.str;
}

void snode_set_next(struct snode *s){ //set the next node
    struct snode *node;
    node.next = s;
}

struct snode_get_next(struct snode *s){ //returns the next node of the node
    return s.next;
}*/

struct snode *snode_create(char *s)
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
    struct snode *node;
    node = malloc(sizeof(struct snode));
    node->length = strlen(s);
    node->str = malloc(node->length + 1);
    strcpy(node->str, s);
    node->next = NULL;
    return node;

}
void snode_destroy(struct snode * s)
{

    s=NULL;
    free(s->str);
    free(s);
 
}
 
