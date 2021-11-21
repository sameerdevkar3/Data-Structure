#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d | ->",Head->data);
        Head = Head->next; 
    }
    printf(" NULL");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}

void InsertFirst(PPNODE Head,int no)
{
    PNODE NewNode = NULL;
    NewNode = (PNODE)malloc(sizeof(NODE));

    NewNode->data = no;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        NewNode->next = *Head;
        *Head = NewNode;
    }
}

void InsertLast(PPNODE Head,int no)
{
    PNODE NewNode = NULL;
    PNODE Temp = *Head;
    NewNode = (PNODE)malloc(sizeof(NODE));

    NewNode->data = no;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if(*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = NewNode;
        NewNode->prev = Temp;
    }
}

void InsertAtPos(PPNODE Head,int no,int iPos)
{
    int size = 0, i = 0;
    size = Count(*Head);
    PNODE NewNode = NULL;
    PNODE Temp = *Head;

    if((iPos < 1) || (iPos > size+1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,no);
    }
    else if(iPos == size)
    {
        InsertLast(Head,no);
    }
    else
    {
        NewNode = (PNODE)malloc(sizeof(NODE));

        NewNode->data = no;
        NewNode->next = NULL;
        NewNode->prev = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            Temp = Temp->next;
        }

        NewNode->next = Temp->next;
        NewNode->prev = Temp;
        Temp->next = NewNode;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE Targeted = *Head;
    if(*Head == NULL)
    {
        return;
    }
    
    if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        Targeted = *Head;     
        *Head = (*Head)->next;
        free(Targeted);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)
        return;

    if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE Head,int iPos)
{
    int size = Count(*Head),i=0;
    PNODE Temp = *Head;
    PNODE Targeted = NULL;
    if(*Head == NULL)
        return;
    
    if((iPos < 1) || (iPos > size+1))
        return;

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        for(i = 1;i < iPos-1;i++)
        {
            Temp = Temp->next;
        }
        Targeted = Temp->next;
        Temp->next = Temp->next->next;
        free(Targeted);
    }
}