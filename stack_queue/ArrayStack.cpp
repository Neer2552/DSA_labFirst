#include "stack.h"
#include <iostream>
ArrayStack::ArrayStack(int size)
    : size(size), topindex(-1), data(new int[size]) {}



bool ArrayStack::isEmpty()
{
    if (topindex < 0)
    {
        return true;
    }
    else
        return false;
}

bool ArrayStack::isFull()
{
    if (topindex >= size - 1)
        return true;
    else
        return false;
}

bool ArrayStack::push(const int element)
{
    if (topindex < size - 1)
    {
        topindex++;
        data[topindex] = element;
        return true;
    }
    else
        return false;
}

void ArrayStack::top(int &element) 
{
    if (topindex < 0)
    {
    std::cout<<"The stack is empty ";
    }
    else
    {
        element = data[topindex];
    
    }
}

void ArrayStack::pop(int &element)
{
    if (!isEmpty())
    {
        element = data[topindex];
        topindex--;
        
    }
    else
    {

        
    }
}

void ArrayStack::traverse()
{

    if(!isEmpty())
    {
        std::cout<<"The elements in the stack : ";
        int i;
    for(i=topindex;i>=0;i--)
    {
        std::cout<<" "<<data[i];
    }
    }
    else
    std::cout<<"The Stack is empty \n";
}

int main()
{  
    int data;
    ArrayStack Stack(20);
    Stack.push(7);
    Stack.push(6);
    Stack.push(5);
    Stack.push(4);
    Stack.pop(data);
    std::cout<<"The removed data is "<<data<<std::endl;
    Stack.traverse();
}
