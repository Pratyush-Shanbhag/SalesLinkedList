#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Sales.h"

class LinkedList
{
private:
    struct Node
    {
        Sales data;
        Node *next;
    };

    Node *head;
    int length;

public:
    LinkedList();
    ~LinkedList();

    int getLength() const {return length;}
    void insertNode(Sales);
    bool deleteNode(string);
    double average() const;

    bool searchList(string, Sales&) const;
    void displayList() const;
    void displayList(int) const;   // display based on year hired
};

#endif