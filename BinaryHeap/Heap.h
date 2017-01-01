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



#define ELEMCOUNT(x) (sizeof(x) / sizeof((x)[0]))


struct Node {
    
    int priority;
    int inuse ;
    int treeheight ;
    int maxsize ;
};
typedef struct Node* node;

void printUsed(node head);
void printFull(node head);
// Changed insert to return arr
 node insert(int data, node root);
void siftUp(int data, node root);
void siftDown(int data, node root);
node createHeap(int size);
void swap(int val1,int val2, node root);
void deleteNode(int val,node root);
int getMax(node root);
int getMin(node root,int min,int index);
int extractMax(node root);
void changePriority(int val, int newP,node root);


void heapSort(int* unsorted,int size);
node buildHeap(int* data,int size);
void freeIarr(int* arr);
void freeNodearr(node root);

// Create dynamic array, store ptr to root
// Create new array twice as large when full, copy over data



#endif /* Heap_h */
