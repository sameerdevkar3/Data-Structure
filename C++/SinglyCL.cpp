#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *Next;
}NODE,*PNODE;

class SinglyCL
{
private:
    PNODE First,Last;
    int Size;
public:
    SinglyCL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

SinglyCL::SinglyCL()
{
    First = NULL;
    Last = NULL;
    Size = 0;
}

void SinglyCL::Display()
{
    PNODE Temp = First;
    do
    {
        cout<<"| "<<Temp->Data<<" | -> ";
        Temp = Temp->Next;
    }while(Temp != Last->Next);
    cout<<endl;
}

int SinglyCL::Count()
{
    return Size;
}

void SinglyCL::InsertFirst(int No)
{
    PNODE NewNode = new NODE;
    NewNode->Data = No;
    NewNode->Next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = NewNode;
        Last = NewNode;
    }
    else
    {
        NewNode->Next = First;
        First = NewNode;
    }
    Last->Next = First;
    Size++;
}

void SinglyCL::InsertLast(int No)
{
    PNODE NewNode = new NODE;
    NewNode->Data = No;
    NewNode->Next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = NewNode;
        Last = NewNode;
    }
    else
    {
        Last->Next = NewNode;
        Last = NewNode;
    }
    Last->Next = First;
    Size++;
}

void SinglyCL::InsertAtPos(int No,int iPos)
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

void SinglyCL::DeleteFirst()
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
    Last->Next = First;
    Size--;
}

void SinglyCL::DeleteLast()
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
        while(Temp->Next != Last)
        {
            Temp = Temp->Next;
        }
        delete Temp->Next;
        Last = Temp;
        Last->Next = First;
    }
    Size--;
}

void SinglyCL::DeleteAtPos(int iPos)
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
    }
}