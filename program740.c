//Bug Solving problems : Detect loop : Check loop is present or not 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *next;

}NODE, *PNODE, **PPNODE;

void InsertSortedIncUnique(PPNODE first , int no)
{
    PNODE newn = NULL,temp = NULL;

    newn =(PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if( *first == NULL || (no < (*first)->data ))
    {
        newn->next = *first;
        *first = newn;
    }

    else
    {
        temp = *first;

        while((temp -> next != NULL) && (temp->next->data < no))
        {
            temp = temp -> next;
        }

        if((temp->next == NULL) && (temp->data == no))
        {
            free(newn);
            return;
        }    

        if(temp -> next != NULL)
        {
            if( temp -> next -> data == no || temp -> data == no)
            {
                free(newn);
                return;
            }
        }
        newn->next = temp->next;
        temp->next  = newn;
           
    }

}
void Display(PNODE first)
{
    while(first)
    {
        printf(" | %d | -> ",first->data);
        first = first->next;
    }
    printf("Null \n");
}

bool CheckLoop(PNODE first)
{
    bool bflag = false;
    PNODE student = first;
    PNODE teacher = first;

    while((teacher != NULL) && (teacher -> next != NULL))
    {
        teacher = teacher -> next -> next;
        student = student -> next;

        if(teacher == student)
        {
            bflag = true;
        }
    }

    return bflag;
}

int main()
{
    PNODE head = NULL;

    PNODE last = NULL;
    PNODE temp = NULL;
    
    bool iRet = false;

    InsertSortedIncUnique(&head,11);
    InsertSortedIncUnique(&head,21);
    InsertSortedIncUnique(&head,51);
    InsertSortedIncUnique(&head,101);
    InsertSortedIncUnique(&head,111);
    InsertSortedIncUnique(&head,121);

    last = head->next->next->next->next->next;

    temp = head->next->next;

    last->next = temp;

    iRet = CheckLoop(head);

    if( iRet == true)
    {
        printf("Loop is present\n");
    }
    else
    {
        printf("Loop is not present\n");   
    }
    return 0;
}