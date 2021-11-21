#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *Next;
}NODE,*PNODE;

class Queue
{
private:
    PNODE First;
    int Size;
public:
    Queue();
    void Display();
    int Count();
    void Enqueue(int);
    int Dequeue();
};

Queue::Queue()
{
    First = NULL;
    Size = 0;
}

void Queue::Display()
{
    PNODE Temp = First;
    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" |"<<endl;
        Temp = Temp->Next;
    }
    cout<<endl;
}

int Queue::Count(){return Size;}

void Queue::Enqueue(int No)
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

int Queue::Dequeue()
{
    if(First == NULL)
        return -1;

    int No = First->Data;
    
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
    return No;
}