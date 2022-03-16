#include<stdio.h>

#define SIZE 10000

///////Quick sort

void swap(long int *a, long int *b)
{
  long int t = *a;
  *a = *b;
  *b = t;
}
long int partition(long int array[], long int low, long int high) {

  long int pivot = array[high];
  long int i = (low - 1);

  for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
             {
              i++;
              swap(&array[i], &array[j]);
            }
    }
   // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the index of the break or partition point
  return (i + 1);
}

void quickSort(long int array[], long int low, long int high)
 {
  if (low < high)
    {
        long int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

////beciede who is better in value by concatination
long int IntConcat(long int a, long int b)
{
    long int t=10;
    while(b>=t)
        t*=10;
    return a*t+b;
}



int main()
{
    //input
    long int N, nums[SIZE];
    scanf("%ld",&N);
    for (int i=0; i<N;i++)
    {
        scanf("%ld",&nums[i]);
    }

    //quickSort
    quickSort(nums, 0, N - 1);
    for(int i=0;i<N-1;i++)
        for(int j=i+1;j<N;j++)
            if(IntConcat(nums[i],nums[j])<IntConcat(nums[j],nums[i]))
                swap(&nums[i],&nums[j]);

    //print
    for(int i=0;i<N;i++)
            printf("%ld",nums[i]);

}
