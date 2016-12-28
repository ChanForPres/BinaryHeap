//
//  main.c
//  BinaryHeap
//
//  Created by Marcus Chan on 12/27/16.
//  Copyright © 2016 Marcus Chan. All rights reserved.
//


#include "Heap.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int maxSize;
  //  scanf("%d",&maxSize);
   // node H = createHeap(maxSize); // Pt to dyn alloc arr
    
   // printTree();
    
    // Test insert, siftUp,siftDown
    
    node test = createHeap(3);
    // Test insert 1,2,3
    insert(1,test);
    insert(2,test);
    insert(3,test);
    insert(4,test);

    return 0;
}
