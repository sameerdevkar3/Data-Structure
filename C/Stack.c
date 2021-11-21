#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void Display(PNODE last)
{
    while(last != NULL)
    {
        printf("| %d |\n",last->data);
        last = last->next;
    }
}

void Push(PPNODE last,int no)
{
    PNODE NewNode = (PNODE)malloc(sizeof(NODE)),Temp = *last;
    NewNode->data = no;
    NewNode->next = NULL;

    if(*last == NULL)
    {
        *last = NewNode;
    }
    else
    {
        NewNode->next = *last;
        *last = NewNode;
    }
}

int Pop(PPNODE last)
{
    int no = 0;
    PNODE Temp = *last;

    if(*last == NULL)
        return -1;
    
    if((*last)->next == NULL)
    {
        no = (*last)->data;
        free(*last);
        *last = NULL;
    }
    else
    {
        no = Temp->data;
        *last = (*last)->next;
        free(Temp);
    }
    return no;
}