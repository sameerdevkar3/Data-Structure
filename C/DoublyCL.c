#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE,**PPNODE;

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

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->data = no;
    NewNode->next = NULL;
    NewNode->prev = NULL;

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

    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    NewNode->data = no;
    NewNode->next = NULL;
    NewNode->prev = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
       *Head = NewNode;
       *Tail = NewNode;
    }
    else
    {
        (*Tail)->next = NewNode;
        NewNode->prev = *Tail;
        *Tail = NewNode;
    }

    (*Head)->prev = *Tail;
    (*Tail)->next = *Head;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos)
{
    int size = Count(*Head,*Tail);
    PNODE NewNode = NULL,Temp = *Head;

    if((iPos < 1) || (iPos > size+1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,Tail,no);
    }
    else if(iPos == size+1)
    {
        InsertLast(Head,Tail,no);
    }
    else
    {
        NewNode = (PNODE)malloc(sizeof(NODE));
        NewNode->data = no;
        NewNode->next = NULL;
        NewNode->prev = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            Temp = Temp->next;
        }

        NewNode->next = Temp->next;
        NewNode->prev = Temp;
        Temp->next->prev = NewNode;
        Temp->next = NewNode;
    }
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
   if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }

    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Tail = (*Tail)->prev;
        free((*Head)->prev);
        (*Head)->prev = *Tail;
        (*Tail)->next = *Head;
    } 
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
    int size = Count(*Head,*Tail);
    PNODE Temp = *Head;

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
        for(int i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->next;
        }

        Temp->next = Temp->next->next;
        free(Temp->next->prev);
        Temp->next->prev = Temp;
    }
}