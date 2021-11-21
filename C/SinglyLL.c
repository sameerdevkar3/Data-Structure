#include<stdio.h>
#include<stdlib.h>

// Self Referantial Structure
struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int iValue)
{
    PNODE NewNode = NULL;
    NewNode = (PNODE)malloc(sizeof(NODE));

    NewNode->Data = iValue;
    NewNode->Next = NULL;

    if(*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        NewNode->Next = *Head;
        *Head = NewNode; 
    }
}
void InsertLast(PPNODE Head,int iValue)
{
    PNODE NewNode = NULL;
    PNODE Temp = *Head;
    NewNode = (PNODE)malloc(sizeof(NODE));

    NewNode->Data = iValue;
    NewNode->Next = NULL;

    if(*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = NewNode;
        NewNode->Next = NULL;
    }
}

void InsertAtPos(PPNODE Head,int iValue,int Pos)
{
    int iCnt = 0;
    PNODE NewNode = NULL;
    PNODE Temp = *Head;
    NewNode = (PNODE)malloc(sizeof(NODE));

    NewNode->Data = iValue;
    NewNode->Next = NULL;

    if(*Head == NULL)
    {
        *Head = NewNode;
    }
    else if(Pos == 0)
    {
        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = NewNode;
        NewNode->Next = NULL;
    }
    else
    {
        while(iCnt != Pos)
        {
            Temp = Temp->Next;
            iCnt++;
        }
        NewNode->Next = Temp->Next;
        Temp->Next = NewNode;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->Next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->Next;
        free(Temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->Next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(Temp->Next->Next != NULL)
        {
            Temp = Temp->Next;
        }
        free(Temp->Next);
        Temp->Next = NULL;
    }
}

void DeleteAtPos(PPNODE Head,int Pos)
{
    int iCnt = 1;
    Pos = Pos - 1;
    PNODE Temp = *Head;
    PNODE Extra = NULL;

    while(iCnt != Pos)
    {
        Temp = Temp->Next;
        iCnt++;
    }
    Extra = Temp->Next;
    Temp->Next = Temp->Next->Next;
    free(Extra);
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("%d\t",Head->Data);
        Head = Head->Next;
    }
}

int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->Next;
    }
    return iCnt;
}