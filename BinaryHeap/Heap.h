//
//  Heap.h
//  BinaryHeap
//
//  Created by Marcus Chan on 12/27/16.
//  Copyright © 2016 Marcus Chan. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#include <stdio.h>






struct Node {
    
    int priority;
    
};
typedef struct Node* node;

void printTree(node head);
void printUsed(node head);
void printFull(node head);

void insert(int data, node root);
void deleteNode(int val);
int extractMax();
void siftUp(int data, node root);
void siftDown(int data, node root);
int getMax();
int getMin();
void changePriority(int val, int newP);
node createHeap(int size);
void swap(int val1,int val2, node root);

// Create dynamic array, store ptr to root
// Create new array twice as large when full, copy over data



#endif /* Heap_h */
