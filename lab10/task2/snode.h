#ifndef _snode_H_
#define _snode_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct snode snode_s;

//TODO: change prototypes of functions to remove
//length
snode_s *snode_create(frame *s);

void snode_destroy(snode_s * s);



void snode_set_next(snode_s *Node, snode_s * a);
snode_s *snode_get_next(snode_s *Node);


void snode_set_str(snode_s *Node, frame * str);
frame *snode_get_str(snode_s *Node);



#endif
