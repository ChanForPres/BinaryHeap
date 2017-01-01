    //
//  Heap.c
//  BinaryHeap
//
//  Created by Marcus Chan on 12/27/16.
//  Copyright © 2016 Marcus Chan. All rights reserved.
//

#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Define globals in .c file
  int INUSE = 0,
TREEHEIGHT = 0,
   MAXSIZE = 0,
    allocInt = 0,
    allocNode = 0;


node createHeap(int maxSize) {
    struct Node* root = NULL;

    // Alloc node array w/ #size
    if (maxSize < 0) {
         printf("Cannot allocate array of size < 0" );
        return NULL;
    }
    root = (node)(malloc((maxSize+1) * sizeof(struct Node)));
    
    
    if (root == NULL) {
        printf(" failed to alloc Heap");
        return NULL;
        
    }
    MAXSIZE = maxSize;
    
    for (int i = 1; i< maxSize+1; i++) {
        root[i].priority = -1;
       // printf("%d ",root[i].val);

    }
    return root;
}


void swap(int parent,int child, node root) {
    
    // Swap pointer values
    int temp = root[parent].priority;
    root[parent].priority = root[child].priority;
    root[child].priority = temp;
    
    
}

void printUsed(node head) {
    for (int i =1; i< INUSE+1; i++) {
         printf("%d", head[i].priority);
    }
    
     printf("\n");
}

void printFull(node head) {
    for (int i =1; i< MAXSIZE+1; i++) {
        printf("%d", head[i].priority);
    }
     printf("\n" );
}


// Pass in location of node to sift, assume arr starts at 1
/*
 if (node[spot] <= node[parent])
 return
 else // Node > parent
 swap (node,parent)
 siftup(parent)
 */

 void siftUp (int spot,node root) {
    
    int parent = floor(spot/2);
    
    if (root[spot].priority <= root[parent].priority || parent <= 0)
        return;
    else // Node > parent
        swap(parent, spot,root);
    siftUp(parent, root);
    
}

void siftDown (int spot,node root) {
    // Compare & switch w/ child until balanced
    int Lchild = 2*spot;
    int Rchild = (2*spot) + 1;
    
    // Check if node is leaf
    if (Lchild> INUSE && Rchild > INUSE) {
        return; // no way to sift down further
        
    }
    else if ((root[spot].priority >= root[Lchild].priority)&&(root[spot].priority >= root[Rchild].priority)) {
        return; // Node in proper order
    }
    else {
        // Node needs to be swapped w/ larger child
        int greaterChild = (root[Lchild].priority >= root[Rchild].priority) ? Lchild : Rchild;
        swap(spot, greaterChild,root);

        siftDown(greaterChild, root);
    }
    
}

 node insert(int data,node root) {
    
    // Check if data is legal
    
    
    
    // Maintain Complete tree - Insert at rightmost empty leaf, sift up
    // Rightmost is located at index[INUSE + 1]
    
    if (INUSE<MAXSIZE) {
        root[INUSE+1].priority = data;
        siftUp(INUSE+1,root);
    }
   
    // Check if arr not full, if full, create new arr and
    else if (INUSE==MAXSIZE) {
        // Allocate 2 * MAXSIZE + 1
 //        printf("New MaxSize = %d", (2*MAXSIZE)+1);
 //        printf("Curr inUse = %d", INUSE);

       // node temp = (node) malloc(((2*MAXSIZE)+1)* sizeof(struct Node));
      
       // printFull(root);
        MAXSIZE  *=2;

        node temp = createHeap(MAXSIZE);

       // printf("\nbefore maxsize: %d\n", MAXSIZE);
        // copy over elements
        for (int i =1; i< INUSE+1; i++) {
            temp[i].priority = root[i].priority;
    
        }

        free(root);
        root = temp;
       

  
        // add new element
        root[INUSE+1].priority = data;
        siftUp(INUSE+1,root);

    }

    INUSE++;
    
   // printf("Curr inUse = %d\n", INUSE);
   // printFull(root);
    return root;
}

void deleteNode(int index,node root) {
    // First check node dne
    if (INUSE<index) {
        printf("Deletion Failure: node dne");
        return;
    }
    
    // Swap w/ right most leaf
    swap( INUSE, index, root);

    // delete right most node
    root[INUSE].priority = -1;
   
  //  printFull(root);
    
    // Sift down
    siftDown(index,  root);
   // printFull(root);

    // Sift up
    siftUp(index,  root);
    //printFull(root);

    INUSE--;
}

void changePriority(int index, int newP, node root){
    // Check if valid priority
    if (newP < 1) {
        printf("changePriority failed: cannot have priority < 1" );
        return;
    }
    
    
    // Change priority to newP
    root[index].priority  = newP;
    printFull(root);
    
    // siftUp
    siftUp(index, root);
    printFull(root);

    
    // siftDown
    siftDown(index, root);

    
}

int getMax(node root) {
    
    return root[1].priority;
    
}

int getMin(node root, int min,int index) {
    //compare all leaves
    // recursively cycle through Lchild,Rchild, keep track of min
    int Lchild = 2*index;
    int Rchild = (2*index) + 1;
    

    if (min > root[index].priority && root[index].priority > 0) {
        // Update min
        min = root[index].priority;
        //  printf("%d", min);
        
    }
    
    if (Lchild> INUSE && Rchild > INUSE) {
        return min; // no way to sift down further
        
    }
    
   
    // While next child exists, recurse through
    
   min= getMin(root, min,Lchild ); //  Lchild ~ 2*n
   min= getMin(root, min,Rchild ); //  Rchild ~ 2*n + 1

    
    return min;
}


int extractMax(node root) {
    
    
    int max = root[1].priority;
    
    // Swap root w/ last leaf
    swap(1, INUSE, root);
    
    // Delete root
    deleteNode(INUSE, root);
    // Siftdown leaf
    siftDown(1, root);
    
    return max;
}


// Returns sorted arr of size INPUT
void heapSort( int* tosort,int size) {
    // Create empty priorityQ unsorted array size & insert elements in Q

    
    node temp = buildHeap(tosort, size);
    // Heap doesn't build right, INUSE, MAXSIZE are 0

    
    
        for (int i = size-1; i >= 0;i--) {
    
            tosort[i] = extractMax(temp);
        }

 

    freeNodearr(temp);

    
}

// Pass in size of array
node buildHeap(int* data, int size) {
  
    
    // Given unsorted arr, insert into priority queue
    node temp = createHeap(size);
    
    for (int i = 0; i < size; i++) {
        // Problems w/ insert: MAXSIZE,INUSE starts at data[1]
        insert(data[i], temp);
    
    }
    
    // return priorityQ
    return temp;
    
}

void freeIarr(int* arr) {
    if (arr != NULL) {
        free(arr);
    }
    else {
        printf("Unable to free int* - NULL ptr");
    }
}

void freeNodearr(node root) {
    if (root != NULL) {
        free(root);
    }
    else {
        printf("Unable to free node* - NULL ptr");

    }
}

