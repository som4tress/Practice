#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct _Stack {
    char value;
    struct _Stack *next;
};

typedef struct _Stack Stack;

Stack *NumStack, *StrStack;

#define PUSH_STR(value) { Push(&StrStack, value); }
#define POP_STR(value) { Pop(&StrStack, &value); }

#define PUSH_NUM(value) { Push(&NumStack, value); }
#define POP_NUM(value) { Pop(&NumStack, &value); value = value - '0'; }

int isStackEmpty(Stack *head) {
    if (!head) return 1;
    return 0;
}

int StackSize(Stack *head) {
    Stack *ptr = head;
    int i;
    if (!head) return 0;
    for(i=0; ptr; i++) {
        ptr = ptr->next;
    }
    return i;
}

int Push(Stack **head, char value) {
    Stack *Node;
    
    Node = malloc(sizeof(Stack));
    if(!Node) return -1;
    Node->value = value;
    
    if (!head) {
        Node->next = NULL;
        *head = Node;
        return 0;
    }
    
    Node->next = *head;
    *head = Node;
    
    return 0;
}

int Pop(Stack **head, char *value) {
    Stack *node = *head;
    *value = node->value;
    *head = node->next;
    free(node);
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main()
{
    char str[] = "2[4[cb2[abc]]5[def]]";
    char result[100];
    
    for(int i=0; i<strlen(str); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            PUSH_NUM(str[i]);
        } else if(str[i] >= 'a' && str[i] <= 'z' || str[i] == '[') {
            PUSH_STR(str[i]);
        } else if(str[i] == ']') {
            char tmp[100];
            int count = 0;
            while(1) {
                POP_STR(tmp[count]);
                if(tmp[count] == '[') {
                    tmp[count] = 0;
                    break;
                }
                count++;
            }
            strcpy(tmp, strrev(tmp));
            
            POP_NUM(count);
            while(count--) {
                for(int i1=0; i1<strlen(tmp); i1++) {
                    PUSH_STR(tmp[i1]);
                }
            }
        }
    }
    
    int i = 0;
    while(!isStackEmpty(StrStack)) {
        POP_STR(result[i++]);
    }
    result[i] = 0;
    printf("%s", strrev(result));
    
    return 0;
}




