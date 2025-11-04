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
            //Inserts a new node at the end of heap array.
            data[size] = idx;
            size++;
            // Restores the order using upheap, beginning from the new position.
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
        // Loops while pos is greater than zero.
        while (pos > 0) {
            // Calculates the parent's index.
            int parent = (pos - 1) / 2;
            // Check the weight of parent's index.
            if (weightArr[data[pos]] < weightArr[parent]) {
                // If it is found to be smaller a swap is made.
                int tmp = data[pos];
                data[pos] = data[parent];
                data[parent] = tmp;
                // moves pos to where parent is.
                pos = parent;
            } else {
                // If the element is properly ordered and greater than or equal to the parent, the heap is satisfied and stops.
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // Loops while the heap property remains true.
        while (true) {
            int parent = pos;
            int leftChild = 2 * pos + 1;
            int rightChild = 2 * pos + 2;
            // Stores the element with the smallest weight as 'smallest' from the listed elements of
            // parent, left child, and right child. It starts with parent as smallest and will precede to check for the smallest value from the rest of the elements.
            int smallest = parent;

            // Checks if there is a left child and if the weight is smaller than the smallest weight set at parent.
            if (leftChild < size && weightArr[data[leftChild]] < weightArr[data[smallest]]) {
                smallest = leftChild;
            }
            // Checks if there is a right child and if the weight is smaller than the smallest weight set at parent or left Child if applicable.
            if (rightChild < size && weightArr[data[rightChild]] < weightArr[data[smallest]]) {
                smallest = rightChild;
            }
            // In a scenario where parent is still smallest after checking left child and right child, order is verified so it stops.
            if (smallest == parent)
                break;

            // After checking the child elements if they were smaller than the element set to parent a swap is initiated to satisfy the min-heap property.
            int tmp = data[parent];
            data[parent] = data[smallest];
            data[smallest] = tmp;

            // Update the new position to that of the smallest child.
            pos = smallest;
        }
    }
};

#endif