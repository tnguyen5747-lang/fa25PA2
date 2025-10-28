//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        if (size < 64) {
            //Inserts a new node at the end of heap array
            data[size] = idx;
            size++;
            // Restores the order using upheap, beginning from the new position
            upheap(size -1,weightArr);
        }
    }

    int pop(int weightArr[]) {
        // Checks if the heap is empty.
        if (size == 0) {
            return -1;
        }
        // Store the minimum index.
        int min_idx = data[0];
        // Replaces the root with last element in the array.
        data[0] = data[size -1];
        // Decrements
        size--;
        // If the heap is not empty, restores min-heap property.
        if (size > 0) {
            downheap(0, weightArr);
        }

        return min_idx;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif