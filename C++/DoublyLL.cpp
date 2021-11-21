#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *Next,*Prev;
}NODE,*PNODE;

class DoublyLL
{
private:
    PNODE First;
    int Size;
public:
    DoublyLL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

DoublyLL::DoublyLL()
{
    First = NULL;
    Size = 0;
}

void DoublyLL::Display()
{
    PNODE Temp = First;
    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->Next;
    }
    cout<<endl;
}

int DoublyLL::Count(){return Size;}

void DoublyLL::InsertFirst(int No)
{
    PNODE NewNode = new NODE;
    NewNode->Data = No;
    NewNode->Next = NULL;
    NewNode->Prev = NULL;

    if(First == NULL)
    {
        First = NewNode;
    }
    else
    {
        NewNode->Next = First;
        First->Prev = NewNode;
        First = NewNode;
    }
    Size++;
}

void DoublyLL::InsertLast(int No)
{
    PNODE NewNode = new NODE;
    NewNode->Data = No;
    NewNode->Next = NULL;
    NewNode->Prev = NULL;

    if(First == NULL)
    {
        First = NewNode;
    }
    else
    {
        PNODE Temp = First;
        while(Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        NewNode->Prev = Temp;
        Temp->Next = NewNode;
    }
    Size++; 
}

void DoublyLL::InsertAtPos(int No,int iPos)
{
    if((iPos < 1) || (iPos > Size+1))
    {
        return;
    }

    if(iPos == 1)
        InsertFirst(No);
    else if(iPos == Size+1)
        InsertLast(No);
    else
    {
        PNODE NewNode = new NODE,Temp = First;
        NewNode->Data = No;
        NewNode->Next = NULL;
        NewNode->Prev = NULL;

        for(int i = 1;i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }
        NewNode->Next = Temp->Next;
        NewNode->Prev = Temp;
        Temp->Next = NewNode;
        Size++;
    }
}

void DoublyLL::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }

    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->Next;
        delete First->Prev;
        First->Prev = NULL;
    }
    Size--;
}

void DoublyLL::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }

    if(First->Next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE Temp = First;
        while(Temp->Next->Next != NULL)
        {
            Temp = Temp->Next;
        }
        delete Temp->Next;
        Temp->Next = NULL;
    }
    Size--;
}

void DoublyLL::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Size+1))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp = First;
        for(int i = 1;i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }
        Temp->Next = Temp->Next->Next;
        delete Temp->Prev;
        Temp->Prev = Temp;
        Size--;
    }
}