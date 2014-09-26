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
    for(i = n-1; i >= 0 ; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    
    for(i = 0;i < n; i++)
        printf("%d ", b[i]);
    printf("\n");
}
