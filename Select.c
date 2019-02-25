/*
Jared Holzmeyer
Dr. Morse
CS315
2/24/2019
Quiz 5: #3
Select.c
*/

#include<stdlib.h>
#include<stdio.h>
#include "Select.h"

int medianIS(int A[], int end){
  // insersion sort
  for(int j = 1; j < end; j++){
    int key = A[j];
    int i = j - 1;
    while (i > -1 && A[i] > key){
      A[i+1] = A[i];
      i--;
    }
    A[i + 1] = key;
  }
  // return middle if A is odd
  if (end % 2 != 0){
    return A[(end/2)];
  }

  // return floor(end/2) if even
  else{
    return A[(end/2)-1];
  }
}

// function to divide the array into elements less than x and greater than x
//      where x is in the midde. Finds x's order statistic
int partition(int A[], int p, int r, int x) {
  
  // setup for typical partition algorithm
  int i; 
  for (i=p; i<r; i++) 
    if (A[i] == x) 
      break; 
  swap(&A[i], &A[r]); 

  // normal partition algorithm
  i = p; 
  for (int j = p; j <= r - 1; j++) 
    { 
      if (A[j] <= x) 
        { 
	  swap(&A[i], &A[j]); 
	  i++; 
        } 
    } 
  swap(&A[i], &A[r]); 
  return i; 
}

// basic function to swap the location of two elements
void swap(int *a, int *b) 
{ 
    int tmp = *a; 
    *a = *b; 
    *b = tmp; 
} 

int Select(int * A, int p, int r, int i) {

  // size of subarry
  int size = r-p+1;
  
  // STEP 1 and STEP 2:
  //array of medians with proper size of groups of 5
  int median[(size+4)/5];
  int j;

  // divide A into groups of 5 and store the medians of each
  for (j=0; j<size/5; j++) 
    median[j] = medianIS(A+p+j*5, 5);
  
  // takes care of group at end with less than 5 elements
  if (j*5 < size) 
    { 
      median[j] = medianIS(A+p+j*5, size%5);  
      j++; 
    }
  
  // median of medians variable
  int x;

  // STEP 3:
  // end recursion when there is only one median otherwise find more medians
  if (j == 1)
    x = median[j-1];
  else
    x = Select(median, 0, j-1, j/2);

  // STEP 4:
  // k is the order statistic of x
  int k = partition(A, p, r, x); 

  // STEP 5:
  // check if k is correct location
  if (k-p == i-1) 
    return A[k];

  // search lower half from k
  if (k-p > i-1)  
    return Select(A, p, k-1, i);

  // search higher half from k
  return Select(A, k+1, r, i-k+p-1); 
}

// for testing purposes only
int main()
{
  //int A[] = {1, 4, 8, 9, 10, 30, 4, 3, 5, 7, 8};
  int A[] = {4,66,99,1, 3, 7};
  int n = sizeof(A)/sizeof(A[0]);
  int k = 5;
  int ordStat = Select(A, 0, n-1, k);
  printf("Order Statistic %d: %d\n", k, ordStat);
  return 0;
}
