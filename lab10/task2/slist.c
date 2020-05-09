
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "slist.h"
#include "snode.h"

typedef struct slist {
    struct snode *front; // front node
    struct snode *back;  // back node
    int size;
    int index;
}slist_s;

// typedef struct snode {
//   char* str;
//   struct snode* next;
// }snode_s;


/**
 * Allocates new slist dynamically.
 *
 * @return pointer to the list
 */
slist_s* slist_create(){                                                    //FINISHED
    struct slist *new = (slist_s *)calloc(1,sizeof(slist_s));
    return new;

    // slist_s * new = (slist_s*) calloc (1, sizeof(slist_s));
    //
    // return new;
}

/**
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
snode_s* slist_add_back(slist_s *l, char *str){
    snode_s *newNode = snode_create (str);                           //FINISHED
    if(l->front == NULL){

      l->front = newNode;
      l->back = newNode;
    }else{

    snode_set_next(l->back, newNode); //ptr of last node points to new node

    l->back=newNode; //pointer 'back' points to the newNode(now last)
    //snode_get_next(newNode); // last pointer(newNode) points to NULL

  }l->size++;
  return newNode;
}

/**
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
snode_s* slist_add_front(struct slist *l, char *str){

  snode_s *newNode = snode_create (str);                      //FINISHED

    if(l->front != NULL){



        snode_set_next(newNode, l->front);//ptr of newNode to point to the first node
        l->front = newNode; // ptr of front to point to newNode(now first)

    }else{
      if(l->front == NULL){


        l->front = newNode;
        l->back = newNode;
      }
    }
    l->size++;
    return newNode;
}
//}
/**
 * Returns the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
snode_s* slist_find(struct slist *l, char *str){                        //FINISHED
    // snode_s *temp= (snode_s *) l->front;
    //
    // while(temp->next != NULL){ //may be no next here
    //     if(strcmp(temp->next->str, str)==0){
    //         temp = temp->next;
    //     } else if(strcmp(temp->next->str, str)==1){
    //         break;
    //     }else{
    //         return NULL;
    //     }
    //
    // }
    // return (snode_s *) temp->str;

    snode_s * find = l->front;

    while (find != NULL){
      if (strcmp(snode_get_str(find), str) == 0)
      {
        return find;
      }
      else if (strcmp(snode_get_str(find), str) != 0)
      {
        find = snode_get_next(find);
      }
    }
    find = NULL;

    return find;
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){

  snode_s * pred; //

  snode_s *temp = l -> front;
  while(temp != NULL){
  pred = snode_get_next(temp);

  //node1 -> next = node2;

  free(snode_get_str(temp));
  free (temp);
  temp = pred;
}free (l);

}


/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){                           //FINISHED (POSSIBLE EMPTY NODE ISSUE)
    snode_s *temp= l->front;

    while(temp != NULL){
        printf("%s\n", snode_get_str(temp));
        temp = snode_get_next(temp);
    }

}

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){           //changed void to int   FINISHED
    snode_s *temp=  l->front;
    int counter = 0;
    while(temp != NULL){
        counter++;
        temp = snode_get_next(temp);
    }
    return(counter);
}

/**
 * Deletes the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
void slist_delete(struct slist *l, char *str){

    snode_s *pred =  l->front;
    snode_s *temp = NULL;
    snode_s *t1 =  l->front;
    snode_s *t2 =  l->front;

      if (strcmp(snode_get_str(t1), str) == 0)
    {
      t2 = snode_get_next(t1);
      free(snode_get_str(t1));
      free(t1);
      if (t2 == NULL)
      {
        l->front = NULL;
        l->back = NULL;
      }
      l->front = t2;
    }
  else
  {
  while(snode_get_next(pred) != NULL){

    if(strcmp(snode_get_str(snode_get_next(pred)), str)== 0){
            temp = snode_get_next(pred);
            snode_set_next(pred, snode_get_next(temp));
      free(snode_get_str(temp));
      free(temp);
      break;
}
      else{
          pred = snode_get_next(pred);
        }
        l->back = pred;
}
  }



l->size--;

}



snode_s * slist_get_front(struct slist *l) {

  return l->front;
}


snode_s * slist_get_back(struct slist *l) {

  return l->back;

}

struct snode *slist_find_at(struct slist *l, int index) {

  snode_s * find = l->front;


  while (find != NULL){
    if (index == 0)
    {
      return find;
    }

    else if (0 < index)
    {
      for (int i = 0; index > i; i++){

        find = snode_get_next(find);
      }return find;
    }

    else if (0 > index)
    {
      if (index < -3){
        return NULL;
      }
      // else {
      //   if (index > -3) {
      //     find = snode_get_next(find);
      //   }
      //}
    //   else {
    //   find = snode_get_next(find);
    // }
      for (int i = 0; slist_length(l) + index > i; i++){

        find = snode_get_next(find);

        // else {
        //    find = snode_get_next(find);
        //  }

      }return find;
      }
  }return find;
}

void slist_delete_at(struct slist *l, int index) {

  snode_s * node = slist_find_at(l, index);

  slist_delete(l, snode_get_str(node));

}
