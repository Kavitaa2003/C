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

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)//LL is empty
    {
        *first = newn;
    }
    else//LL contains atleast one elementn
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
       printf("%d\n",first->data);
       first = first->next;
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

   InsertFirst(&head,101);
   InsertFirst(&head,51);
   InsertFirst(&head,21);
   InsertFirst(&head,11);

   int iRet =0;
   iRet = Count(head);
   printf("total nodes present are : %d",iRet);

  
   InsertLast(&head,111);
   InsertLast(&head,121);
   InsertLast(&head,151);

  int iBet = Count(head);
   printf("total nodes present are : %d",iRet);

   Display(head);
   
   return 0;
}