//
// Created by Josephine  Klefeker  on 4/29/18.
//


#ifndef FINALPROJECT_PQ_HEAP_H
#define FINALPROJECT_PQ_HEAP_H

#include<iostream>
#include<time.h>
#include <fstream>
#include <sstream>
using namespace std;

// A class for Min Heap
struct preg{
    string name;
    int labor;
    int treatment;
};

class MinHeap
{
public:
    MinHeap(int capacity);
    ~MinHeap();
    void push(preg woman);
    preg pop();
    preg peek() { return heap[1]; }
    void printHeap();
private:
    preg *heap; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int currentSize; // Current number of elements in min heap
    void MinHeapify(int index);
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i+1); }
    int right(int i) { return (2*i + 2); }
    void swap(preg *x, preg *y);
};

#endif //FINALPROJECT_PQ_HEAP_H
