//singly linear linked list in ds
// |11| -> |21| ->| 51| -> |101| -> NULL

#include<stdio.h>
#include<stdlib.h>

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
   PNODE head = NULL;//typedef 
   
   PNODE newn1 = NULL;
   PNODE newn2 = NULL;
   PNODE newn3= NULL;
   
   newn1=(struct node *)malloc(sizeof(struct node));
   newn2=(struct node *)malloc(sizeof(struct node));
   newn3=(struct node *)malloc(sizeof(struct node));
   
   return 0;
}