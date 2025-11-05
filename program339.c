////Doubly linear linked list   $ = change
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;  //$
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
    printf("NULL <=> ");
    while( first != NULL)
    {
        printf("|%d| <=> ",first->data);
        first = first ->next;
    }
    printf("NULL\n");
    
}

int count(PNODE first)
{
    int count = 0;
     while( first != NULL)
    {
        count++;
        first = first->next;
    }
    return count;
}

void InsertFirst(PPNODE first,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;//&

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;//$
        (*first) = newn;
    }
}

void InsertLast(PPNODE first,int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;//&

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;
        while(temp->next != NULL)
        {
            temp = temp->next;

        }
        newn->prev = temp;//$
        temp->next = newn;
    }
}

void InsertAtPos(PPNODE first,int pos)
{}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);//&
        (*first)->prev = NULL;//&
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp =NULL;
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next != NULL) //$
        {
            temp = temp->next;
        }
        temp->prev->next = NULL; //$
        free(temp);
    }
}

void DeleteAtPos(PPNODE first,int pos)
{}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    int iRet =0;
    iRet = count(head);
    printf("nodes are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = count(head);
    printf("node are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = count(head);
    printf("node are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);

    iRet = count(head);
    printf("nodes are : %d\n",iRet);
    
    return 0;
}
