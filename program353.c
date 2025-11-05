//Singly Circular LL

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

void InsertFirst(PPNODE  first, PPNODE last, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if( *first == NULL && *last == NULL )//if (iCount == 0)
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
    }
    else
    {
        newn->next = *first;
        *first = newn;
        (*last)->next = *first;
    }
    
}
    
void InsertLast(PPNODE  first, PPNODE last, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if( *first == NULL && *last == NULL )//if (iCount == 0)
    {
        *first = newn;
        *last = newn;
        (*last)->next = *first;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
        (*last)->next = *first;
    }
    
}
void InsertAtPos(PPNODE  first, PPNODE last, int no,int pos)
{}

void DeleteFirst(PPNODE  first, PPNODE last)
    {
        if(*first == NULL && *last == NULL)
        {
            return;
        }
        else if( *first == *last)
        {
            free(*first);
            *first = NULL;
            *last = NULL;
            //first = last = NULL;
        }
        else
        {
            *first = (*first)->next;
            free((*last)->next);
            (*last)->next = *first;
        }
    }

void DeleteLast(PPNODE  first, PPNODE last)
{
    {
        if(*first == NULL && *last == NULL)
        {
            return;
        }
        else if( *first == *last)
        {
            free(*first);
            *first = NULL;
            *last = NULL;
        }
        else
        {
            /*delete(last);
            last deleted but circulat LL is not maintain here so use loop 
            last->next = first;*/
            PNODE temp = NULL;
            temp = *first;
            while(temp ->next != (*last))
            {
                temp = temp->next;
            }
            free(*last);
            *last = temp;
            (*last)->next = *first;
        }
    }
}

void DeleteAtPos(PPNODE  first, PPNODE last,int pos)
{}

void Display(PNODE first,PNODE last)
{

        if((first) == NULL && (last) == NULL)
        {
            return;
        }
        else
        {
            int iCount = 0;
            do
            {
                printf("|%d|->",first->data);
                first =first->next;
                iCount++;
            } while (first != last->next);
            printf("\n");
            printf("nodes are: %d\n",iCount);
            
        }
    }


int Count(PNODE first, PNODE last)
{
    return 0;
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);

    InsertLast(&head,&tail,121);

    Display(head,tail);

    DeleteLast(&head,&tail);

    Display(head,tail);
    
    return 0;
}