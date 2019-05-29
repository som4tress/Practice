//bac bca acb cba abc cab

/******************************************************************************
                           Queue Implementation
*******************************************************************************/

#include <stdio.h>

struct _Queue {
    char str[100];
    struct _Queue *next;
};

typedef struct _Queue Queue;

Queue *Head = NULL, *Tail = NULL;

int Enqueue(char *str) {
    if (!Head) {
        Head = malloc(sizeof(Queue));
        if(!Head) return -1;
        strcpy(Head->str, str);
        Head->next = NULL;
        Tail = Head;
        return 0;
    }
    
    Queue *elem = malloc(sizeof(Queue));
    if(!elem) return -1;
    strcpy(elem->str, str);
    elem->next = NULL;
    Tail->next = elem;
    Tail = elem;
    return 0;
}

int Deque(char *str) {
    if(!Head) return -1;
    
    strcpy(str, Head->str);
    Queue *elem = Head->next;
    free(Head);
    Head = elem;
    return 0;
}

int isQueueEmpty() {
    if(!Head) return 1;
    return 0;
}

int Exists(char *str) {
    Queue *cur = Head;
    
    while(cur) {
        if(strcmp(cur->str, str) == 0)
            return 1;
        cur = cur->next;
    }
    
    return 0;
}

int main()
{
    char str[100];
    int i, len=3;
    
    Enqueue("abc");
    
    while(!isQueueEmpty()) {
        Deque(str);
        for(i=0; i<len-2; i++) {
            
        }
    }
    
}







