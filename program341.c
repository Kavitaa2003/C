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

void InsertAtPos(PPNODE first,int no,int pos)
{
    PNODE temp = *first;
    PNODE newn = NULL;
    int icount=0,i=0;
    
    icount = count(*first);
    printf("%d\n",icount);

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
        newn  = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL; 
        temp = *first;

        for(i=0; i<= pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp ->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev=temp;
    }

}

void DeleteAtPos(PPNODE first,int pos)
{
    int icount = 0,i=0;
    count(*first);
    printf("%d",icount);
    PNODE temp = NULL;
    PNODE target = NULL;

    if(pos<1 || pos>icount+1)
    {
        printf("invalid position\n");
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }

    else if(pos == icount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;
        for(i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev=temp;
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

    int iRet =0;
    iRet = count(head);
    printf("nodes are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = count(head);
    printf("node are : %d\n",iRet);
    

    InsertAtPos(&head,105,1);

    Display(head);

    iRet = count(head);
    printf("nodes are : %d\n",iRet);

    DeleteAtPos(&head,1);

    Display(head);

    iRet = count(head);
    printf("nodes are : %d\n",iRet);


    
    return 0;
}
