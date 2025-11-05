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
            //printf("nodes are: %d\n",iCount);
            
        }
    }


int Count(PNODE first, PNODE last)
{
      int iCount = 0;
    if((first) == NULL && (last) == NULL)
        {
            return 0;
        }
        else
        {
            do
            {
                first =first->next;
                iCount++;
            } while (first != last->next);
            printf("\n");
           // printf("nodes are: %d\n",iCount);
            
        }
        return iCount;
}

void InsertAtPos(PPNODE  first, PPNODE last, int no,int pos)
{
    int iCount = 0;
    iCount = Count(*first,*last);
    PNODE newn = NULL;
    PNODE temp = NULL;

    if(pos<1 || pos > iCount+1)
        {
            printf("invalid input");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(first,last,no);
        }
        else if(pos == iCount+1)
        {
            InsertLast(first,last,no);

        }
        else
        {
            PNODE newn = (PNODE)malloc(sizeof(NODE));
            newn->data = no;
            newn->next = NULL;
           PNODE temp = *first;

            for(int i=1;i<pos-1;i++)
            {
                temp = temp->next;

            }
            newn -> next = temp->next;
            temp->next = newn;
            iCount++;

        }
    }


    void DeleteAtPos(PPNODE  first, PPNODE last,int pos)
    {
        int iCount = 0;
        iCount=Count(*first,*last);
        if(pos<1 || pos > iCount)
        {
          return;
        }

        if(pos == 1)
        {
            DeleteFirst(first,last);
        }
        else if(pos == iCount)
        {
            DeleteLast(first,last);
        }
        else
        {
            PNODE temp = NULL;
            PNODE target = NULL;
            int i =0;
            temp = *first;

             for(int i=1; i<pos-1; i++)
            {
                temp = temp->next;

            }
            target = temp->next;
            temp->next = target->next;
            free(target);

            iCount--;

        }
    }


int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("nodes are: %d",iRet);

    InsertAtPos(&head,&tail,105,5);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("nodes are: %d",iRet);

    DeleteAtPos(&head,&tail,5);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("nodes are: %d",iRet);
    
    return 0;
}
/*
singly linear
singly circular
doubly linear
doubly circular
*/