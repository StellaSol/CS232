#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "slist.h"
#include "snode.h"



struct slist *slist_create()
{
    struct slist *l=  malloc(sizeof(struct slist));
    l->size = 0;
    return l;
    free(l);
}


struct snode* slist_add_back(struct slist *l, char *str){
    struct snode *node;
    node = snode_create(str);
    if (l->size == 0) {
        l->back = node;
        l->front = node;
        l->size = 1;
    }
    else {
        snode_set_next(l->back,node); //l->back->next = node;
        l->back = node;
        l->size++;
    }
    return node;
}


struct snode* slist_add_front(struct slist *l, char *str){
    struct snode *node;
    node = snode_create(str);
    if (l->size == 0) {
        l->back = node;
        l->front = node;
        l->size = 1;
    }
    else {
        snode_set_next(node,l->front); //node->next = l->front
        l->front = node;
        l->size++;
    }
    return node;
    
}


struct snode* slist_find(struct slist *l, char *str){
    struct snode *temp = l->front;
    while (temp != NULL) {
        if (strcmp(snode_get_str(temp),str) == 0){
            //temp->str
            return temp;
        }
        temp = snode_get_next(temp);
      }
    return temp;
}

void slist_destroy(struct slist *l){
    struct snode *p_list;
    p_list = l->front;
    while (l->front != NULL){
        l->front = snode_get_next(l->front);
        free(snode_get_str(p_list));
        free(p_list);
        p_list = l->front;
    }
    l->front = NULL;
    l->back  = NULL;
    l->size = 0;
    free(p_list);
}

void slist_traverse(struct slist *l){
    struct snode *temp = l->front;
    while (temp != NULL) {
      printf("Node:%s \t length:%lu\n", snode_get_str(temp),strlen(snode_get_str(temp)));
        temp = snode_get_next(temp);
    }
    free(temp);
}

struct snode* slist_delete(struct slist *l, char *str){
    struct snode *temp = l->front,*prev=NULL;
    if (temp != NULL && strcmp(snode_get_str(temp),str)==0) {
        l->front = snode_get_next(temp);
        temp = snode_get_next(temp);
        free(temp);
        if (l->front == NULL) {
            l->back = NULL;
        }
        l->size--;
        return temp;
    }
    while (temp != NULL && strcmp(snode_get_str(temp),str)!=0) {
        prev = temp;
        temp = snode_get_next(temp);
    }
    snode_set_next(prev, snode_get_next(temp)); //prev->next = temp->next
    free(temp);
    if (temp == l->back) {
        l->back = prev;
    }
    l->size--;
    return temp;
}

int slist_length(struct slist *l){
    return l->size;
}

struct snode * slist_get_front(struct slist * slist_p){
    return slist_p->front;
}

struct snode * slist_get_back(struct slist * slist_p){
    return slist_p->back;
}


