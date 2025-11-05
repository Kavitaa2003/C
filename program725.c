//Accept the elemenst from user and insert into linklist in sorted order
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void Display(PNODE first)
{
    while(first)
    {
        printf("| %d | ->",first->data);
        first = first->next;
    }

    printf("Null \n");
}

int main()
{
    PNODE head = NULL;

    Display(head);

    return 0;
}