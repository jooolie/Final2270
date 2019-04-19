//
// Created by Josephine  Klefeker  on 5/4/18.
//

#include "finalproject_ll.h"




// Insert a blank node at beginning of list
LinkedList::LinkedList() {}
LinkedList::~LinkedList(){}

Node* LinkedList::insertHead( Node *head, preg newItem )
{
    // Create a new node and tmp poitner
    Node *tmp = new Node;

    tmp->item = newItem;

    // Link new node with old head
    tmp->next = head;

    // Return head pointer (pointing to new head)
    return tmp;


}

void LinkedList::insertAfter( Node *prevNode, preg newItem )
{
    // Create new node
    Node *tmp = new Node;
    tmp->item = newItem;

    // Link new node with next node
    tmp->next = prevNode->next;

    // Link prevNode with new node
    prevNode->next = tmp;

    tmp = nullptr;

}

void LinkedList::push(preg woman)
{
    Node* current = head;
    Node* prev;
    if(head == NULL || woman.labor <= current->item.labor)
    {
        if(head != NULL)
        {
            if(woman.labor == current->item.labor)
            {
                if(woman.treatment > current->item.treatment)
                {
                    insertAfter(current, woman);
                } else
                {
                    head = insertHead(head, woman);
                }
            }
            else
            {
                head = insertHead(head, woman);
            }
        }
        else //if it is null
        {
            head = insertHead(head, woman);
        }
    }
    else
    {
        while(current != NULL && woman.labor >= current->item.labor)
        {
            if(woman.labor == current->item.labor)
            {
                if(woman.treatment < current->item.treatment)
                {
                    break;
                }
            }
             prev = current;
             current = current->next;
        }
        insertAfter(prev, woman);
    }
}

preg LinkedList::pop()
{
    Node* tmp = head;
    preg top = tmp->item;
    // If the node to be deleted is head
    // make new head point to next node
    head = head->next;
    // deallocate memory for deleted node
    delete tmp;
    return top;



}




