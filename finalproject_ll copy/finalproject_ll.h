//
// Created by Josephine  Klefeker  on 5/4/18.
//

#ifndef FINALPROJECT_LL_FINALPROJECT_LL_H
#define FINALPROJECT_LL_FINALPROJECT_LL_H

#include <iostream>
#include <time.h>
#include <chrono>
#include <fstream>
#include <sstream>
using namespace std;


struct preg{
    string name;
    int labor;
    int treatment;


};

struct Node
{
    preg item;
    Node* next;
};

class LinkedList
{

public:
    LinkedList();
    ~LinkedList();
    void push(preg woman);
    preg pop();
private:
    Node* head;
    Node * insertHead( Node *head, preg newItem );
    void insertAfter( Node *prevNode, preg newItem );


};


#endif //FINALPROJECT_LL_FINALPROJECT_LL_H
