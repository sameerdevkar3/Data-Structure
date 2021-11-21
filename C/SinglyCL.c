#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->data = no;
    NewNode->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = NewNode;
        *Tail = NewNode;
    }
    else
    {
        NewNode->next = *Head;
        *Head = NewNode;
    }
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->data = no;
    NewNode->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = NewNode;
        *Tail = NewNode;
    }
    else
    {
        (*Tail)->next = NewNode;
        *Tail = NewNode;
    }
    (*Tail)->next = *Head;
}

void Display(PNODE Head,PNODE Tail)
{
    do
    {
        printf("| %d |->",Head->data);
        Head = Head->next;
    }while(Head != Tail->next);
    printf("\n");
}

int Count(PNODE Head,PNODE Tail)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        Head = Head->next;
    }while(Head != Tail->next);
    return iCnt;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    PNODE Temp = *Head;
    if((*Head == NULL) && (Tail == NULL))
        return;
    
    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(Temp);
    }
    (*Tail)->next = *Head;
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE Temp = *Head,Targeted = NULL;
    if((*Head == NULL) && (Tail == NULL))
        return;
    
    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        while(Temp->next != *Tail)
        {
            Temp = Temp->next;
        }
        Targeted = Temp->next;
        *Tail = Temp;
        free(Targeted);
        (*Tail)->next = *Head;
    }
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
    int size = Count(*Head,*Tail);
    PNODE Temp = *Head,Targeted = NULL;
    if((*Head == NULL) && (*Tail == NULL))
        return;
    if((iPos < 1) || (iPos > size+1))
        return;
    
    if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos == size)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        for(int i = 1; i < iPos-1; i++)
        {
            Temp = Temp->next;
        }
        Targeted = Temp->next;
        Temp->next = Targeted->next;
        free(Targeted);
    }
}