//singly linear linked list in ds
// |11| -> |21| ->| 51| -> |101| -> NULL

#include<stdio.h>

struct node
{
    int data;
    struct node *next;//self referencial structure 12 byte
};

typedef struct node NODE;
typedef struct node * PNODE;//pointer node
typedef struct node ** PPNODE;//poiner to pointer node 

int main()
{
    struct node *head = NULL;//stores the address of first node 

    return 0;
}