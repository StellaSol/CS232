#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "slist.h"
#include "snode.h"


struct slist *slist_create() //allocates a new slist dynamically
{
    struct slist *l=  malloc(sizeof(struct slist));
    return l;
    free(l);
}

struct snode* slist_add_back(struct slist *l, char *str){
    struct snode *node = malloc(sizeof(struct snode));
    node = snode_create(str); //creates a node to insert the string
    if (l->counter == 0) { //set to both front and back of the node
        l->back = node;
        l->front = node;
        l->counter = 1;
    }
    else {
        l->back->next = node;
        l->back = node;
        l->counter++;
    }
    return node;
    free(node);
}

struct snode* slist_add_front(struct slist *l, char *str){
    struct snode *node = malloc(sizeof(struct snode));
    node = snode_create(str); //creating a node
    if (l->counter == 0) {
        l->back = node;
        l->front = node;
        l->counter = 1;
    }
    else {
        node->next = l->front;//adding it to the front
        l->front = node;
        l->counter++;
    }
    return node;
    free(node);
}


struct snode* slist_find(struct slist *l, char *str){
    struct snode *temp = l->front; //points to the front of the list
      while (temp != NULL) {
        if (strcmp(temp->str,str) == 0){
          return temp;
        }
        temp= temp->next;
      }
    return temp;
    free(temp);
}

void slist_destroy(struct slist *l){ //deallocate a list and all of its nodes
    struct snode *p_list;
    p_list = l->front;
    while (l->front != NULL){
        l->front = l->front->next;
        free(p_list->str);
        free(p_list);
        p_list = l->front;
    }
    //setting front and back both to null
    l->front = NULL;
    l->back  = NULL;
    l->counter = 0;
}

void slist_traverse(struct slist *l){ //
    struct snode *temp = l->front;
    while (temp != NULL) {
      printf("Node:%s \t length:%i\n", temp->str,temp->length);
        temp = temp->next;
    }
    free(temp);
}

struct snode* slist_delete(struct slist *l, char *str){
    struct snode *temp = l->front ,*prev=NULL;
    if (temp != NULL && strcmp(temp->str,str)==0) { //check if the head has the key
        temp = temp->next;
        free(temp);
        return temp;
    }
    while (temp != NULL && strcmp(temp->str,str)!=0){  //Finds the key by iterating through each node
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    l->counter--;
    return temp;
}

uint32_t slist_length(struct slist *l){
    return l->counter;
}




