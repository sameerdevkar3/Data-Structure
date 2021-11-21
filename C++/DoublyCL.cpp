#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *Next;
    struct node *Prev;
}NODE,*PNODE;

class DoublyCL
{
private:
    PNODE first,last;
    int size;
public:
    DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    void Display();
    int Count();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int no,int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
};

void DoublyCL::Display()
{
    PNODE Temp = first;
    do
    {
        cout<<"| "<<Temp->Data<<" |->";
        Temp = Temp->Next;
    }while(Temp != last->Next);
    cout<<"\n";
}

int DoublyCL::Count()
{
    return size;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE NewNode = new NODE;

    NewNode->Data = no;
    NewNode->Next = NULL;
    NewNode->Prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = NewNode;
        last = NewNode;
    }
    else
    {
        NewNode->Next = first;
        first->Prev = NewNode;
        first = NewNode;
    }
    last->Next = first;
    first->Prev = last;
    size++;
}

void DoublyCL::InsertLast(int no)
{
    PNODE NewNode = new NODE;

    NewNode->Data = no;
    NewNode->Next = NULL;
    NewNode->Prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = NewNode;
        last = NewNode;
    }
    else
    {
        last->Next = NewNode;
        NewNode->Prev = last;
        last = NewNode;
    }
    last->Next = first;
    first->Prev = last;
    size++;    
}

void DoublyCL::InsertAtPos(int no,int ipos)
{
    if((ipos < 1) || (ipos > (size+1)))
    {
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE NewNode = new NODE;
        PNODE Temp = first;

        NewNode->Data = no;
        NewNode->Next = NULL;
        NewNode->Prev = NULL;

        for(int i = 1;i < ipos -1; i++)
        {
            Temp = Temp->Next;
        }
        
        NewNode->Next = Temp->Next;
        NewNode->Next->Prev = NewNode;
        Temp->Next = NewNode;
        NewNode->Prev = Temp;
        size++;
    }
}

void DoublyCL::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->Next;
        delete first->Prev;
        first->Prev = last;
        last->Next = first;
    }
    size--;
}

void DoublyCL::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        // last->Prev->Next = first;
        last = last->Prev;
        delete first->Prev;
        first->Prev = last;
        last->Next = first;
    }
    size--;    
}

void DoublyCL::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        PNODE Temp = first;

        for(int i = 1; i < ipos-1; i++)
        {
            Temp = Temp->Next;
        }

        Temp->Next = Temp->Next->Next;
        delete Temp->Next->Prev;
        Temp->Next->Prev = Temp;

        size--;
    }
}