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
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;
    printf("----------------------------------------------------------\n");
    printf("-------------------Doubly Linear Linked List---------------------\n");
    printf("----------------------------------------------------------\n");
    
    while(1)
    {
        printf("----------------------------------------------------------\n");
        printf("----------------------Please select optin-----\n");
        printf("1. Insert new node at first position\n");
        printf("2. Insert new node at last position\n");
        printf("3. Insert new node at any position\n");
        printf("4. Delete new node at first position\n");
        printf("5. Delete new node at last position\n");
        printf("6. Delete new node at any position\n");
        printf("7. Display number of nodes of linked list\n");
        printf("8. Count number of nodes of linked list\n");
        printf("0. Terminate the application\n");

        
        printf("Enter your choice: ");
        scanf("%d",iChoice);
        
        if(iChoice == 1)
        {
            printf("enter the data that you want to insert: \n");
            scanf("%d",&iValue);

            InsertFirst(&head,iValue);
        }

        else if(iChoice == 2)
        {
            printf("enter the data that you want to insert: \n");
            scanf("%d",&iValue);

            InsertLast(&head,iValue);
        }

        else if(iChoice == 3)
        {
            printf("enter the data that you want to insert: \n");
            scanf("%d",&iValue);
             printf("enter the position  \n");
            scanf("%d",&iPos);
            
            InsertAtPos(&head,iValue,iPos);
        }

        else if(iChoice == 4)
        {
            printf("Deleting first \n");

            DeleteFirst(&head);
        }

        else if(iChoice == 5)
        {
            printf("Deleting last \n");

            DeleteFirst(&head);
        }

        else if(iChoice == 6)
        {
            printf("deleting element from any position \n");
            printf("enter the position  \n");
            scanf("%d",&iPos);
            
            DeleteAtPos(&head,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Display all the nodes of linked list: \n");
            Display(head);
        }

        else if(iChoice == 8)
        {
            iRet = count(head);
            printf("Count all the nodes of linked list: %d \n",iRet);
        }

        else if(iChoice == 0)
        {
            printf("Exit\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }

        printf("------------------------------------------------------------------\n");
    }
    return 0;
}
