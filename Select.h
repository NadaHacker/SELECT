/*
Jared Holzmeyer
Dr. Morse
CS315
2/24/2019
Quiz 5: #3
Select.h
*/

#ifndef SELECT_H
#define SELECT_H

int medianIS(int A[], int end);

int Select(int * A, int p, int r, int i);

void swap(int *a, int *b) ;

int partition(int A[], int p, int r, int x);

#endif
