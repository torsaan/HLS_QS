#include "quicksort.h"
#include <string.h>

// XOR swap function, to use less memory 
//static void swap(char *a, char *b) {
//    if (a != b) {  
//        *a ^= *b; //XOR #1
//        *b ^= *a; //XOR #2
 //       *a ^= *b; //XOR #3 
  //  }
//}


//Partition function for quicksort 
static int partition(char *A, int low, int high) {
    //Last element picked as pivot 
    char pivot = A[high];
    int i = low - 1; //i tracks posistions of elements less than or equal to the pivot
    
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            //XOR swap
            if (&A[i] != &A[j]) { 
                A[i] ^= A[j]; //XOR#1
                A[j] ^= A[i]; //XOR#2
                A[i] ^= A[j]; //XOR#3
            }
        }
    }

    // Inline XOR swap for final position
    if (&A[i + 1] != &A[high]) {
        A[i + 1] ^= A[high]; //XOR#1
        A[high] ^= A[i + 1]; //XOR#2
        A[i + 1] ^= A[high]; //XOR#3
    }
    //Return index of pivot
    return i + 1;
}

//Quicksort function 
static void quicksort(char *A, int low, int high) {
    if (low < high) {
        //Partition array , get index of the pivot 
        int p = partition(A, low, high);
        //Use quicksort to the left and right partitions (Low,High)
        quicksort(A, low, p - 1); //Sort the left array 
        quicksort(A, p + 1, high); //Sort the right array 
    }
}
//Call for a good(sorted) time
void sort(char *A) {
    int size = strlen(A); //Determine length of the array 
    quicksort(A, 0, size - 1); //Call quicksort on array 
}
