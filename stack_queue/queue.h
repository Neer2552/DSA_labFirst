
#include <iostream>
#include "LinkedList.h"
#pragma once
class IQueue
{
public:
    IQueue() {}
    ~IQueue() {}
    virtual void enQueue(int element) = 0;
    virtual void deQueue(int &element) = 0;
    virtual bool isEmpty() = 0;
    virtual void front(int &element) = 0;
    virtual void rear(int &element) = 0;
    virtual void traverse() = 0;
};

class LinkedListQueue : public IQueue
{
private:
    LinkedList list;

public:
    LinkedListQueue() {}
    ~LinkedListQueue() {}
    void enQueue(int element);
    void deQueue(int &element);
    void front(int &element);
    void rear(int &element);
    bool isEmpty();
    void traverse();
};

class ArrayQueue : public IQueue
{
private:
    int size;
    int topindex;
    int *data;

public:
    ArrayQueue (int x);
    ~ArrayQueue(); 
    void enQueue(int element);
    void deQueue(int &element);
    bool isEmpty();
    bool isFull();
    void front(int &element);
    void rear(int &element);
    void traverse();
    
};
