//
//  main.c
//  BinaryHeap
//
//  Created by Marcus Chan on 12/27/16.
//  Copyright © 2016 Marcus Chan. All rights reserved.
//


#include "Heap.h"

int main(int argc, const char * argv[]) {
    
  //  int maxSize;
  //  scanf("%d",&maxSize);
   // node H = createHeap(maxSize); // Pt to dyn alloc arr
    
   
    
//    node test = createHeap(3);
//    // Test insert 1,2,3
//    insert(1,test);
//    insert(2,test);
//    insert(3,test);
// //   printFull(test);
//
//   test= insert(4,test);
//    
//    printFull(test);
//    
//    // Build heap
//    int arr[] = {1,2,3,4};
//    node test2 = buildHeap(arr, 4);
//    printFull(test2);
    
    // Test BuildHeap
    int intArr[] = {3,4,5,2,1};
    int arrLength = sizeof(intArr) / sizeof(intArr[0]);
  

    
     heapSort(intArr, arrLength);
  

    for(int i =0; i< 5; i++) {
         printf("%d\t", intArr[i]);
    }
    
    
    // Should be 1,2,3,4,5
    return 0;
}
