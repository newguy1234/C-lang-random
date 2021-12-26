#include "sort.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/* sort linked list *list using merge insertion sort. */
/* upon success, the elements in *list will be sorted. */
/* return silently if *list is uninitialised or empty. */
/* the compare argument is a pointer to a function which returns */
/* less than 0, 0, or greater than 0 if first argument is */
/* less than, equal to, or greater than second argument respectively. */
void ahhh(LinkedList *list,LinkedList *B){
     while(1) {
        prepend_linked_list(list, B->tail->data);
        remove_tail_linked_list(B);
        if(B->head == NULL){
         break;
        }
    }
}

void change(){
}

void insertion_sort(LinkedList *list, int (*compare)(void *, void *))
{

    LinkedList *tmp = initialise_linked_list();
    Node *ndtmp;
    Node *nN;
    append_linked_list(tmp, list->head->data);
    remove_head_linked_list(list);
    while(list->head != NULL) {
        ndtmp = tmp->head;
        while(ndtmp != NULL) {
            if(compare(list->head->data, ndtmp->data) < 0) {
                if(ndtmp->prev != NULL) {
                    nN = initialise_node();
                    nN->data = list->head->data;
                    nN->next = ndtmp;
                    nN->prev = ndtmp->prev;
                    ndtmp->prev->next = nN;
                    ndtmp->prev = nN;
                }else {
                    prepend_linked_list(tmp, list->head->data);
                }
                remove_head_linked_list(list);
                break;
            }
            ndtmp = ndtmp->next;
        }
        if(ndtmp==NULL) {
            append_linked_list(tmp, list->head->data);
            remove_head_linked_list(list);
        }
    }
    ahhh(list,tmp);
    free_linked_list(tmp);
}
