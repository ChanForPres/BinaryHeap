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


//struct Node* root = NULL;

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
     //       printf("%d", root[i].priority);

       //     printf("%d", temp[i].priority);
        }
    //    printFull(temp);

        free(root);
        root = temp;
       

     //   printFull(temp);

  //      printFull(root);
        
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
   
    printFull(root);
    
    // Sift down
    siftDown(index,  root);
    printFull(root);

    // Sift up
    siftUp(index,  root);
    printFull(root);

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
    
    if (Lchild> INUSE && Rchild > INUSE) {
        return min; // no way to sift down further
        
    }
    
    if (min > root[index].priority) {
        // Update min
        min = root[index].priority;
         printf("%d", min);
        
    }
    // While next child exists, recurse through
    
    getMin(root, min,Lchild ); //  Lchild ~ 2*n
    getMin(root, min,Rchild ); //  Rchild ~ 2*n + 1

    
    return min;
}



/*
 FUNCTIONS TO IMPLEMENT : 
 

int extractMax();
*/







