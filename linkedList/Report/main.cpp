/*#include<iostream>
#include"LinkedList.cpp"

int main()
{
    LinkedList list;
    list.addToHead(10);
    list.addToHead(12);
    list.Traverse();
}*/

#include<iostream>
#include"LinkedList.cpp"

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

    // Adding data after a specified predecessor node
    list.Add(12, 14);

    // Removing data from the head of the list
    int removedFromHead;
    list.removeFromHead(&removedFromHead);
    std::cout << "Data removed from the head: " << removedFromHead << std::endl;

    // Removing data from the tail of the list
    int removedFromTail;
    list.removeFromTail(&removedFromTail);
    std::cout << "Data removed from the tail: " << removedFromTail << std::endl;

    // Searching for and removing specific data from the list
    list.Remove(14);

    // Printing the data in the list from head to tail
    std::cout << "Data in the list: ";
    list.Traverse();
    
    // Searching for data within the list
    int searchData = 10;
    bool searchResult = list.search(searchData);
    std::cout << searchData << " exists in the list: " << (searchResult ? "Yes" : "No") << std::endl;

    return 0;
}

