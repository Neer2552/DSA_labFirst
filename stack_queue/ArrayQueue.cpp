#include "queue.h"
#include <iostream>

ArrayQueue::ArrayQueue(int x) : size(x), topindex(-1), data(new int[size]) {}

ArrayQueue::~ArrayQueue() {}
bool ArrayQueue::isEmpty()
{
    if (topindex < 0)
    {
        return true;
    }
    else
        return false;
}

bool ArrayQueue::isFull()
{
    if(topindex >= size -1)
    {
        return true;
    }
    else
        return false;
}

void ArrayQueue::enQueue(int element)
{
    if (!isFull())
    {
        topindex++;
        data[topindex] = element;
    }
    else
    {
        throw("The Queue is Full");
    }
 } 

void ArrayQueue::deQueue(int &element)
{
    if (!isEmpty())
    {
        int i;
        element = data[0];
        for (i = 0; i < topindex; i++)
        {
            data[i] = data[i + 1];
        }
        topindex--;
    }
    else
    {
        throw("The Queue is Empty");
    }
}

void ArrayQueue::front(int &element)
{
    if (!isEmpty())
    {
        element = data[0];
       
    }
    else
        std::cout<<"The stack is empty \n";
};

void ArrayQueue::rear(int &element)
{
    if (!isEmpty())
    {
        element = data[topindex];
       
    }
    else
        std::cout<<"The stack is empty \n";
};

void ArrayQueue::traverse()
{
    int i;
    if(!isEmpty())
    {
        std::cout<<"The elements in the Queue  : ";
        for(i=0;i<=topindex;i++)
        {
            std::cout<<"  "<<data[i];
        }
    }
    else
    {
        std::cout<<"\nThe Queue is empty\n";
    }
}
int main()
{
    ArrayQueue Queue(10);
     int data;
    Queue.enQueue(5);
    Queue.enQueue(6);
    Queue.enQueue(7);
    Queue.traverse();
    Queue.deQueue(data);
    std::cout<<"\nThe deQueued data is : "<<data<<std::endl;
    Queue.traverse();
}
