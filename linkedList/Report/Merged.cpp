#include <iostream>
class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, Node *next) : data(d), next(next) {}
};

class LinkedList
{
private:
    Node *HEAD;
    Node *TAIL;

public:
    LinkedList();

    void add(Node *pred, int data);
    void addToHead(int data);
    void addToTail(int data);
    void Traverse();
    bool remove(int &data);
    bool removeFromHead(int &data);
    bool removeFromTail(int &data);
    bool isEmpty();
    bool search(int data);
};

LinkedList::LinkedList() : HEAD(nullptr), TAIL(nullptr) {}

bool LinkedList::isEmpty() {
    return HEAD == nullptr;
}

void LinkedList::add(Node *pred, int data)
{
    Node *newNode = new Node; // Initialize newNode pointer
    newNode->data = data;
    newNode->next = pred->next;
    pred->next = newNode;
}

void LinkedList::addToHead(int data)
{
    Node *newNode = new Node; // Initialize newNode pointer
    if (!isEmpty())
    {

        newNode->data = data;
        newNode->next = HEAD;
        HEAD = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = nullptr;
        HEAD = newNode;
        TAIL = HEAD;
    }
}

void LinkedList::addToTail(int data)
{
    Node *newNode = new Node; // Initialize newNode pointer
    if (!isEmpty())
    {

        newNode->data = data;
        newNode->next = nullptr;
        TAIL->next = newNode;
        TAIL = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = nullptr;
        TAIL = newNode;
        HEAD = TAIL;
    }
}

bool LinkedList::removeFromHead(int &data) {
    if (!isEmpty()) {
        Node *nodeToDelete = HEAD;
        data = HEAD->data;
        HEAD = HEAD->next;
        delete nodeToDelete;
        if (isEmpty()) {
            TAIL = nullptr;
        }
        return true;
    } else {
        return false;
    }
}

bool LinkedList::search(int data)
{
    Node *newNode = HEAD;
    while (newNode != nullptr)
    {
        if (newNode->data == data)
        {
            return true;
        }
        newNode = newNode->next;
    }
    return false; 
}


bool LinkedList::removeFromTail(int &data)
{
    if (isEmpty())
    {
        return false;
    }

    if (HEAD == TAIL)
    { // Only one node in the list
        data = HEAD->data;
        delete HEAD;
        HEAD = TAIL = nullptr;
        return true;
    }

    Node *p = HEAD;
    Node *t = nullptr;
    while (p != TAIL)
    {
        t = p;
        p = p->next;
    }

    data = TAIL->data;
    delete TAIL;
    TAIL = t;
    TAIL->next = nullptr;
    return true;
}

void LinkedList::Traverse()
{
    Node *p = HEAD;
    if (!isEmpty())
    {
        std::cout << "The contents of the list are :  ";
        while (p != NULL)
        {
            std::cout << p->data ;
            std::cout<<"  ";
            p = p->next;
        }
    }
}

bool LinkedList::remove(int &data) {
    if (isEmpty()) {
        return false;
    }
    
    if (HEAD->data == data) {
        return removeFromHead(data);
    }
    
    Node *p = HEAD;
    Node *temp = nullptr;
    while (p->next != nullptr && p->data != data) {
        temp = p;
        p = p->next;
    }
    
    if (p->data == data) {
        if (p == TAIL) {
            return removeFromTail(data);
        } else {
            Node *nodeToDelete = p;
            temp->next = p->next;
            delete nodeToDelete;
            return true;
        }
    }
    
    return false;
}

int main()
{
    // Creating an instance of the LinkedList class
    LinkedList list;
    
    // Checking if the list is empty
    std::cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    // Adding data to the head of the list
    list.addToHead(10);
    list.addToHead(12);

    // Adding data to the tail of the list
    list.addToTail(15);

    // Removing data from the head of the list
    int removedFromHead;
    list.removeFromHead(removedFromHead);
    std::cout << "Data removed from the head: " << removedFromHead << std::endl;

    // Removing data from the tail of the list
    int removedFromTail;
    list.removeFromTail(removedFromTail);
    std::cout << "Data removed from the tail: " << removedFromTail << std::endl;

    // Searching for and removing specific data from the list
    int dataToRemove = 14;
    list.remove(dataToRemove);

    // Printing the data in the list from head to tail
    std::cout << "Data in the list: ";
    list.Traverse();
    
    // Searching for data within the list
    int searchData = 10;
    bool searchResult = list.search(searchData);
    std::cout << searchData << " exists in the list: " << (searchResult ? "Yes" : "No") << std::endl;

    return 0;
}

