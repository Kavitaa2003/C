//singly linear linked list in ds
// |11| -> |21| ->| 51| -> |101| -> NULL

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)//LL is empty
    {
        *first = newn;
    }
    else//LL contains atleast one elementn
    {
        newn->next = *first;
        *first = newn;
    }
}



int Count(PNODE first)
{
    int iCnt = 0;
    while(first != NULL)
    {
        iCnt++;
    }
    return iCnt; 
}

int main()
{
   PNODE head = NULL;

   InsertFirst(&head,121);
   InsertFirst(&head,111);
   InsertFirst(&head,101);

   InsertFirst(&head,51);
   InsertFirst(&head,21);
   InsertFirst(&head,11);
   int iRet =0;
   iRet = Count(head);
   printf("total nodes present are : %d",iRet);
   
   return 0;
}