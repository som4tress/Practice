/******************************************************************************

                            Binary Search Tree Code

*******************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct _Node {
    int value;
    struct _Node *left;
    struct _Node *right;
};

typedef struct _Node Node;

struct _Stack {
    Node *node;
    struct _Stack *next;
};

typedef struct _Stack Stack;

Node *root = NULL;
Stack *head = NULL;

int push(Node *node) {
    Stack *element = malloc(sizeof(Stack));
    if (!element) return -1;
    element->node = node;
    element->next = head;
    head = element;
    return 0;
}

Node* pop() {
    if(!head) return NULL;
    Node *ret = head->node;
    Stack *old_head = head;
    head = head->next;
    free(old_head);
    return ret;
}

int isEmpty() {
    if (!head) return 1;
    return 0;
}

int insert(int val) {
    Node *cur_ptr, *new_node;
    
    new_node = malloc(sizeof(Node));
    if(!new_node) return -1;
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    
    if (!root) {
        root = new_node;
        return 0;
    }
    
    cur_ptr = root;
    
    do {
        if (val < cur_ptr->value) {
            if (!cur_ptr->left) {
                cur_ptr->left = new_node;
                break;
            }
            else
                cur_ptr = cur_ptr->left;
        }
        else {
            if (!cur_ptr->right) {
                cur_ptr->right = new_node;
                break;
            }
            else
                cur_ptr = cur_ptr->right;
        }
    } while(1);
  
    return 0;
}

void printall_inorder_recursive(Node *node) {
    if(node) {
        printall_inorder_recursive(node->left);
        printf("%d|", node->value);
        printall_inorder_recursive(node->right);
    }
}

void printall_inorder_iterative(Node *node) {
    while(node || !isEmpty()) {
        if(node) {
            push(node);
            node = node->left;
        } else {
            node = pop();
            if (node) {
                printf("%d|", node->value);
                node = node->right;
            }
        }
    }
}

void printall_preorder_recursive(Node *node) {
    if (node) {
        printf("%d|", node->value);
        printall_preorder_recursive(node->left);
        printall_preorder_recursive(node->right);
    }
}

void printall_preorder_iterative(Node *node) {
    while(node || !isEmpty()) {
        if (node) {
            printf("%d|", node->value);
            push(node);
            node = node->left;
        } else {
            node = pop();
            node = node->right;
        }
    }
}

void printall_postorder_recursive(Node *node) {
    if (node) {
        printall_postorder_recursive(node->left);
        printall_postorder_recursive(node->right);
        printf("%d|", node->value);
    }
}

void printall_postorder_iterative(Node *node) {
    
}

/*
1000 0 
*/

int main()
{
    int arr[] = { 1000, 0, 3, 1, 5, 10, 6, 102, 56, 234 };
    
    printf("Inserting .. ");
    for (int i=0; i<sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d->", arr[i]);
        insert(arr[i]);
    }
    
    printf("\nInorder Recursive : ");
    printall_inorder_recursive(root);
    printf("\nInorder Iterative : ");
    printall_inorder_iterative(root);
    printf("\nPreorder Recursive : ");
    printall_preorder_recursive(root);
    printf("\nPreorder Iterative : ");
    printall_preorder_iterative(root);
    printf("\nPostorder Recursive : ");
    printall_postorder_recursive(root);

    return 0;
}

