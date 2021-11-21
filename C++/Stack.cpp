#include<iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *Next;
}NODE,*PNODE;

class Stack
{
private:
    PNODE First;
    int Size;
public:
    Stack();
    void Display();
    int Count();
    void Push(int);
    int Pop();
};

Stack::Stack()
{
    First = NULL;
    Size = 0;
}

void Stack::Display()
{
    PNODE Temp = First;
    while(Temp != NULL)
    {
        cout<<"| "<<Temp->Data<<" |"<<endl;
        Temp = Temp->Next;
    }
    cout<<endl;
}

int Stack::Count(){return Size;}

void Stack::Push(int No)
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

int Stack::Pop()
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