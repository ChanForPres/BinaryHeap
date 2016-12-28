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
 int INUSE = 0;
 int TREEHEIGHT = 0;
 int MAXSIZE = 0;


struct Node* root = NULL;
/*
void insert(int data);
void deleteNode(int val);
int extractMax();
void siftUp(int data);
void siftDown(int data);
int getMax();
int getMin();
void changePriority(int val, int newP);
*/

node createHeap(int maxSize) {
    // Alloc node array w/ #size
    if (maxSize < 0) {
        
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


void swap(int parent,int child) {
    
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
        printf("%d\n", head[i].priority);
    }
}


// Pass in location of node to sift, assume arr starts at 1
/*
 if (node[spot] <= node[parent])
 return
 else // Node > parent
 swap (node,parent)
 siftup(parent)
 */

void siftUp (int spot) {
    
    int parent = floor(spot/2);
    
    if (root[spot].priority <= root[parent].priority || parent <= 0)
        return;
    else // Node > parent
        swap(parent, spot);
  //  printTree();
    siftUp(parent);
    
}

void siftDown (int spot) {
    // Compare & switch w/ child until balanced
    int Lchild = 2*spot;
    int Rchild = (2*spot) + 1;
    
    // Check if node is leaf
    if (Lchild> MAXSIZE && Rchild > MAXSIZE) {
        return; // no way to sift down further
    }
    else if ((root[spot].priority >= root[Lchild].priority)&&(root[spot].priority >= root[Rchild].priority)) {
        return; // Node in proper order
    }
    else {
        // Node needs to be swapped w/ larger child
        int greaterChild = (root[Lchild].priority >= root[Rchild].priority) ? Lchild : Rchild;
        swap(spot, greaterChild);
  //      printTree();

        siftDown(greaterChild);
    }
    
}

void insert(int data) {
    
    // Check if data is legal
    
    
    
    // Maintain Complete tree - Insert at rightmost empty leaf, sift up
    // Rightmost is located at index[INUSE + 1]
    
    if (INUSE<MAXSIZE) {
        root[INUSE+1].priority = data;
      //  printTree(root);
        siftUp(INUSE+1);
    }
   
    // Check if arr not full, if full, create new arr and
    else if (INUSE==MAXSIZE) {
        // Allocate 2 * MAXSIZE + 1
 //        printf("New MaxSize = %d", (2*MAXSIZE)+1);
 //        printf("Curr inUse = %d", INUSE);

       // node temp = (node) malloc(((2*MAXSIZE)+1)* sizeof(struct Node));
      
        printFull(root);
        MAXSIZE  *=2;

        node temp = createHeap(MAXSIZE);

       // printf("\nbefore maxsize: %d\n", MAXSIZE);
        // copy over elements
        for (int i =1; i< INUSE+1; i++) {
            temp[i].priority = root[i].priority;
            printf("%d", root[i].priority);

            printf("%d", temp[i].priority);
        }
        free(root);
        root = temp;
     //   printFull(temp);

  //      printFull(root);
        
        // add new element
        root[MAXSIZE+2].priority = data;
    }
    INUSE++;
  //  printf("Curr inUse = %d", INUSE);

}










