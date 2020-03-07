#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    node_t * node1=(struct snode*)malloc(sizeof(node_t));
    node_t * node2=(struct snode*)malloc(sizeof(node_t));
    node_t * node3=(struct snode*)malloc(sizeof(node_t));
    head = node1; // FIX1: point head to node1 so that from head all the nodes can be visited
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    strcpy(node1->str, "hello");
    node1->length=5;
    strcpy(node2->str, "there");
    node2->length=5;
    strcpy(node3->str, "prof");
    node3->length=4;

    
    //Dereference each pointer to access the .next field in its pointee,
    //and use pointer assignment to set the .next field to point to the appropriate Node.
    node1->next=node2;
    node2->next=node3;
    node3->next=NULL;
        
    return head;
}

void teardown(node_t **head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
    node_t *cur = *head;
    while (cur) {
        node_t *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = NULL;
}


void add(node_t ** head, char * str, int length){
    node_t * temp;
    temp = (struct snode*)malloc(sizeof(node_t));
    strcpy(temp->str, str);
    temp->length = length;
    temp->next=*head;
    *head = temp;
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    dump_all(head);
    teardown(&head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
