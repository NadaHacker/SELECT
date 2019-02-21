/*
Jared Holzmeyer
Dr. Morse
CS 315
2/21/19
SELECT Algorithm
*/

#include <stdlib>
#include "Select.h"
/*
< 3 4 3 44 55 | 2 1 566 33 21 45 | 44 21>
*/
int Select(int *A, int p, int r, int i){
  if (r-p == 1)
    return A[1];
  int size = r - p + 1;
  int 
  for (int i = 0; i < (size/5)+1; i++){
    
  }
  for (int i = 0; i < 5; i++){
    
  }
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
