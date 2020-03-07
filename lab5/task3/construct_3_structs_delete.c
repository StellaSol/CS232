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
    //TODO: copy add func from task2
    node_t * temp;
    temp = (struct snode*)malloc(sizeof(node_t));
    strcpy(temp->str, str);
    temp->length = length;
    temp->next=*head;
    *head = temp;
}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
      node_t * temp = *head;
      if (idx == 0){ //if it is the head, delete the head first
          *head = temp->next;
          free(temp);
          return;
      }
      for (int i = 0; temp != NULL && i < idx; i++){ //if it is not the head
           temp = temp->next;
      }
      node_t *suc = temp->next->next;
      free(temp);
      temp->next = suc;
}

void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete.
    node_t * temp = *head, *prev = NULL;
      if (temp != NULL && strcmp(temp->str,key)==0) { //check if the head has the key
          temp = temp->next;
          free(temp);
          return;
      }
      while (temp != NULL && strcmp(temp->str,key)!=0){  //Finds the key by iterating through each node
          prev = temp;
          temp = temp->next;
      }
      prev->next = temp->next;
      free(temp);
}
//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
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
