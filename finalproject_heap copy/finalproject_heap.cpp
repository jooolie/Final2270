#include "finalproject_heap.h"

MinHeap::MinHeap(int cap)
{
    currentSize = 0;
    capacity = cap;
    heap = new preg[capacity];
}

MinHeap::~MinHeap()
{
    delete [] heap;
}

void MinHeap::push(preg woman)
{
    if (currentSize == capacity)
    {
        cout << "At capacity, cannot insert key." << endl;
    }

    else {
        currentSize++;
        int i = currentSize - 1;
        heap[i].name = woman.name;
        heap[i].labor = woman.labor;
        heap[i].treatment = woman.treatment;

        while (i != 0 && heap[parent(i)].labor >= heap[i].labor)
        {
            if(heap[parent(i)].labor == heap[i].labor)
            {
                if(heap[parent(i)].treatment > heap[i].treatment)
                {
                    swap(&heap[i], &heap[parent(i)]);
                    i = parent(i);
                }
                else
                {
                    break;
                }
            }
            else
            {
                swap(&heap[i], &heap[parent(i)]);
                i = parent(i);
            }

        }
    }
}

preg MinHeap::pop()
{

    preg bs;
    bs.name = "noname";
    bs.labor = 0;
    bs.treatment = 0;

    if (currentSize <= 0)
        return bs;
    if (currentSize == 1)
    {
        currentSize--;
        return heap[0];
    }

    preg poppedVal = heap[0];
    heap[0] = heap[currentSize-1];
    currentSize--;
    MinHeapify(0);

    return poppedVal;
}

void MinHeap::MinHeapify(int i)
{
    int leftChild = left(i);
    int rightChild = right(i);
    int smallest = i;
    if (leftChild < currentSize && heap[leftChild].labor <= heap[i].labor)
    {

        if(heap[leftChild].labor == heap[i].labor){
            if(heap[leftChild].treatment < heap[i].treatment)
            {
                smallest = leftChild;
            }
        }
        else{
            smallest = leftChild;
        }


    }
    if (rightChild < currentSize && heap[rightChild].labor <= heap[smallest].labor)
    {
        if(heap[rightChild].labor == heap[smallest].labor)
        {
            if(heap[rightChild].treatment < heap[smallest].treatment)
            {
                smallest = rightChild;
            }
        }
        else
        {
            smallest = rightChild;
        }
    }
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::swap(preg *x, preg *y)
{
    preg temp;
    temp.name = x->name;
    temp.labor = x->labor;
    temp.treatment = x->treatment;

    x->name = y->name;
    x->labor = y->labor;
    x->treatment = y->treatment;

    y->name = temp.name;
    y->labor = temp.labor;
    y->treatment = temp.treatment;
}

void MinHeap::printHeap() {
    cout << "The heap array is currently {";
    for (int i = 0; i < currentSize; i++)
    {
        cout << heap[i].name << " " << heap[i].labor;
        if (i < currentSize-1) {
            cout << endl;
        }
    }
    cout << "}" << endl;
}

