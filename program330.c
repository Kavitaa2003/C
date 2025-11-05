#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    
    newn->next = *first;////////
    *first = newn;//////////////
    
}

void InsertLast(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp =NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    
    if(*first == NULL)
    {
        *first = newn;
    }

    else
    {
        temp = *first;
        while(temp->next!= NULL)
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
        printf("|%d| -> ",first->data);
        first= first->next;
    }
    printf("NULL\n");
}

int count(PNODE first)
{
    int iCnt = 0;
    while(first != NULL)
    {
       iCnt++;
       first= first->next;
    }
    return iCnt;
}


void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if((*first) ==NULL)//empty LL
    {
        return;
    }
    else if((*first)->next == NULL)//single ll
    {
         free(*first);
         *first =NULL;
    }
    else//more than 1 node
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)///delete last
{
    PNODE temp = NULL;
    if((*first) ==NULL)//empty LL
    {
        return;
    }
    else if((*first)->next == NULL)//single ll
    {
         free(*first);
         *first =NULL;
    }
    else//more than 1 node
    {
        temp = *first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE first,int no,int pos)
{
    PNODE temp = *first;
    PNODE newn = NULL;
    int icount=0,i=0;
    
    icount = count(*first);

    if((pos<1) || (pos>icount+1))
    {
        printf("invalid pos");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if( pos == icount+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;
        for(i = 1; i <= pos-2; i++)
        {
            temp=temp->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next =NULL;

        newn->next = temp->next;
        temp->next =newn;
    }
}

void DeleteAtPos(PPNODE first,int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    PNODE newn = NULL;
    int icount=0,i=0;
    
    icount = count(*first);

    if((pos<1) || (pos>icount))
    {
        printf("invalid pos");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if( pos == icount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        for(i = 1; i <= pos-2; i++)
        {
            temp=temp->next;
        }
        target = temp->next;
        temp->next = target->next;//temp->next = temp->next->next;
        free(target);
    }
}



int main()
{
    PNODE head = NULL;
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    int iRet = 0 ;
    iRet = count(head);
    printf("total nodes in linked list are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);

    Display(head);

    iRet = count(head);
    printf("Total nodes of linked list are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = count(head);
    printf("Total nodes of linked list are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);

    iRet = count(head);
    printf("Total nodes of linked list are : %d\n",iRet);

    InsertAtPos(&head,105,5);

    Display(head);

    iRet = count(head);
    printf("Total nodes of linked list are : %d\n",iRet);

    DeleteAtPos(&head,5);

    Display(head);

    iRet = count(head);
    printf("Total nodes of linked list are : %d\n",iRet);
    
    return 0;
}