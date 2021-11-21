#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *Next;
}NODE,*PNODE;

class SinglyLL
{
private:
    PNODE First;
    int Size;
public:
    SinglyLL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

SinglyLL::SinglyLL()
{
    First = NULL;
    Size = 0;
}

void SinglyLL::Display()
{
    PNODE Temp = First;
    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->Next;
    }
    cout<<endl;
}

int SinglyLL::Count()
{
    return Size;
}

void SinglyLL::InsertFirst(int No)
{
    PNODE NewNode = new NODE;
    NewNode->Data = No;
    NewNode->Next = NULL;

    if(First == NULL)
    {
        First = NewNode;
    }
    else
    {
        NewNode->Next = First;
        First = NewNode;
    }
    Size++;
}

void SinglyLL::InsertLast(int No)
{
    PNODE NewNode = new NODE;
    NewNode->Data = No;
    NewNode->Next = NULL;

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
        Temp->Next = NewNode;
    }
    Size++;
}

void SinglyLL::InsertAtPos(int No,int iPos)
{
    if((iPos < 1) || (iPos > Size+1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Size+1)
    {
        InsertLast(No);
    }
    else
    {
        PNODE NewNode = new NODE,Temp = First;
        NewNode->Data = No;
        NewNode->Next = NULL;

        for(int i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }

        NewNode->Next = Temp->Next;
        Temp->Next = NewNode;
        Size++;
    }
}

void SinglyLL::DeleteFirst()
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
        First = First->Next;
        delete Temp;
    }
    Size--;
}

void SinglyLL::DeleteLast()
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

void SinglyLL::DeleteAtPos(int iPos)
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
        PNODE Temp = First,Targeted = NULL;
        for(int i = 1; i < iPos - 1; i++)
        {
            Temp = Temp->Next;
        }
        Targeted = Temp->Next;
        Temp->Next = Targeted->Next;
        delete Targeted;
        Size--;
    }
}