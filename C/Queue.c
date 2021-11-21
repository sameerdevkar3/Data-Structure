#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("| %d | <- ",Head->data);
        Head = Head->next;
    }
    printf("\n");
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

void Enqueue(PPNODE Head,int no)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE));
    PNODE Temp = *Head;
    NewNode->data = no;
    NewNode->next = NULL;

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
    }
}

int Dequeue(PPNODE Head)
{
    int no = (*Head)->data;
    PNODE Temp = NULL;
    
    if(*Head == NULL)
    {
        return -1;
    }

    if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        Temp = *Head;
        *Head = (*Head)->next;
        free(Temp);
    }
    return no;
}