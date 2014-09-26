/*
20140926@Teradata Fri by lfqy


About counting sort:

key hypothesis:
The values to be sorted are not bigger than a certain constant k.

key idea:
If in the array there are m_e values that are smaller than a certain element e(whose value is v_e) in the sorted array the element e will be in position m_e+1. More specifically, we just count how many values in the array that are not bigger than a certain element e(whose value is v_e). If there is n_e element that are not bigger than e, it means that the element e should be the n_eth increasely and we can just put the element e at the position n_e.(If we use the array start with 0, then the index of element e should be n_e-1.)

Pseudocode:
Parameters:
A is the input array (unsorted), B will contain the sorted elements (i.e. it is the output), and k is the maximum among the values of A. A and B must have the same length n and in fact the lenth
of C is k+1. The index of A and B starts with 1 and the index of C starts from 0.
COUNTING-SORT (A, B, k)
   //Initialize the count of every value with 0.
1  for i := 0 to k
2    C[i] := 0
   //Count how many times each values accurs.
3  for j := 1 to A.length
4    C[A[j]] := C[A[j]] + 1
5  //We just plus the C[i] and C[i-1] and in fact we can get the position of corresponding value in the increasing sequence.
6  for i := 1 to k
7    C[i] := C[i] + C[i - 1]
8  //Now, what we need to do is put every element of A at the right calculted position in a new array.
9  for j := A.length downto 1
10   B[C[A[j]]] := A[j]
11   C[A[j]] := C[A[j]] - 1

*/

#include <stdio.h>
#include <stdlib.h>
void countingSort(int *a, int *b, int n, int k);
int main()
{
    int a[8] = {2,5,3,0,2,3,0,3};
    printf("Hello World!\n");
    int b[8];
    countingSort(a, b, 8, 5);
    return 0;
}
void countingSort(int *a, int *b, int n, int k)
{
    int i;
    int *c = malloc(sizeof(int) * (k + 1));
    if(!c)
        exit(1);
    for(i = 0; i <= k; i++)
        c[i] = 0;
    for(i = 0; i < n; i++)
        c[a[i]] = c[a[i]] + 1;
    for(i = 1; i <= k; i++)
        c[i] = c[i] + c[i-1];
    //for(i = 0; i < n ; i++) is ok, too. You can start with either end.
    for(i = n-1; i >= 0 ; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    //Print for test.
    for(i = 0;i < n; i++)
        printf("%d ", b[i]);
    printf("\n");
}
