#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 10005

int first = 1;

void printPreOrder(int *arr, int l, int r)
{
    if(l > r)
        return;
    int mid = (l+r)/2;
    if(first)
    {
        printf("%d", arr[mid]);
        first = 0;
    }
    else
        printf(",%d", arr[mid]);
    printPreOrder(arr, l, mid-1);
    printPreOrder(arr, mid+1, r);
}


int main() {

    int arr[MAX_SIZE];
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n;i++)
        scanf("%d", arr + i);
    printPreOrder(arr, 0, n-1);
    return 0;
}
