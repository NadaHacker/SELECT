/*
Jared Holzmeyer
Dr. Morse
CS 315
2/21/19
SELECT Algorithm
*/

#include <stdlib.h>
#include <stdio.h>
#include "Select.h"
/*
< 0 1 2 3  4    5 6 7   8  9    10 11 12
< 3 4 3 44 55 | 2 1 566 33 21 | 45 44 21>
*/
int medianIS(int A[], int end){
  for(int j = 1; j < end; j++){
    int key = A[j];
    int i = j - 1;
    while (i > -1 && A[i] > key){
      A[i+1] = A[i];
      i--;
    }
    A[i + 1] = key;
  }
  for (int i = 0; i < end; i++){
    printf("%d: %d\n",i, A[i]);
  }
  if (end % 2 != 0)
    return A[(end/2)+1];
  else 
    return A[end/2];
}
int Select(int *A, int p, int r, int i){
  int size = r-p+1;
  int medians[(size+4)/5], j;
  for (j = 0; j < size/5; j++){ 
    medians[j] = medianIS(A+p+j*5, 5);
  }
  if (j*5 < size){
    medians[i] = medianIS(A+p+i*5, size % 5);
    i++;
  }
  /* for (int i = 0; i < size/5+1; i++){ */
  /*   printf("%d: %d\n",i, medians[i]); */
  /* } */
  return 0;
}

int main(){
  int A[] = {1, 4, 8, 9, 10, 30, 4, 3, 5, 7, 8};
  // {1, 3, 4, 4, 5, 7, 8, 8, 9, 10, 30}
  
  /* for (int i = 0; i < 11; i++){ */
  /*   printf("%d: %d\n",i, A[i]); */
  /* } */
  int n = sizeof(A)/sizeof(A[0]), k = 5;
  int ans = Select(A, 0, n-1, k);
  return 0;
}
/*
    1. Divide the n-elements of input array into floor(n/5) groups of 5
    elements each and at most one group of remaining elenets n mod 5
    2. Find the median of each of the ceiling(n/5) groups by using insertion
    sort and find medians of each group
    3. Use Select recursively to find the medians of the medians
    4. Partition the input array around median of medians x
    (using Partition(A, p, r, x)). Let k be one or more than the number
    of elemetns on the lower side of x. X is the kth order statistic.
    (x is the pivot point for partition)
    5. If i=k, return x, else call recursively Select on lower and upper
    side depending on if i < k or i > k
    Note: lower median if even
*/
