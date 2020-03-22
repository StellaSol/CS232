#ifndef _snode_H_
#define _snode_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct snode;
//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(char *s) ;
void snode_destroy(struct snode * n) ;

//Internal structure functions 
void snode_set_str(struct snode *,char *s);
char* snode_get_str(struct snode *);
void snode_set_next(struct snode *, struct snode *s);
struct snode* snode_get_next(struct snode *);

#endif
