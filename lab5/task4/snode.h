#ifndef _snode_H_
#define _snode_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct snode {
  //TODO: change str to dynamic allcoation
  char * str;
  int length;
  struct snode *next;
};

//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(char *s) ;
void snode_destroy(struct snode * n) ;
/*void snode_set_str(char *s) ;
struct snode_get_str(struct snode *s);
void snode_set_next(struct snode *s);
struct snode_get_next(struct snode *s);*/
 
#endif
