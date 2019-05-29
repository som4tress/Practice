/******************************************************************************

                           Inplace Merge Sorted Linked List

*******************************************************************************/

#include <stdio.h>

struct _List {
    int x;
    struct _List *next;
};

typedef struct _List List;

void Insert(List **list, int x) {
    List *node;
    
    if(!*list) {
        *list = malloc(sizeof(List));
        (*list)->x = x;
        (*list)->next = NULL;
        return;
    } else {
        node = malloc(sizeof(List));
        node->x = x;
        node->next = *list;
        *list = node;
    }
}

void print(List *list) {
    List *ptr = list;
    while(ptr) {
        printf("%d->", ptr->x);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void merge(List **list_a, List **list_b) {
    List *ptr1 = *list_a;
    List *ptr2 = *list_b;
    List *tmp, *tmp1, *prev_ptr1 = NULL;
    
    while(ptr1 && ptr2) {
        if(ptr1->x > ptr2->x) {
            if(!prev_ptr1) { // New first element
                tmp = ptr2->next;
                ptr2->next = ptr1;
                *list_a = ptr2;
                ptr1 = *list_a;
                ptr2 = tmp;
            } else { // elem to be inserted between two elements
                tmp = ptr2->next;
                ptr2->next = ptr1;
                prev_ptr1->next = ptr2;
                ptr2 = tmp;
            }
        } else {
            prev_ptr1 = ptr1;
            ptr1 = ptr1->next;
        }
    }
}

int main()
{   
    List *list_a = NULL, *list_b = NULL;
    
    Insert(&list_a, 6);
    Insert(&list_a, 4);
    Insert(&list_a, 3);
    printf("Original list_a = ");
    print(list_b);
    
    Insert(&list_b, 5);
    Insert(&list_b, 4);
    Insert(&list_b, 3);
    Insert(&list_b, 2);
    Insert(&list_b, 1);
    printf("Original list_b = ");
    print(list_a);
    
    printf("Merged list_a = ");
    merge(&list_a, &list_b);
    print(list_a);
    
    return 0;
}


