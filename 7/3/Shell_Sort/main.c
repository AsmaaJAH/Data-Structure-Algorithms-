#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

void shellSort(int array[], int N)
{
           int gap;

          // rearrange iterations instead of recursion
          for (gap=N/2 ; gap>0 ; gap/=2 )
              {
                        for (int i=gap ; i<N ; i ++)
                         {
                                /////swapping to put the smaller elements in the back
                                  int temp = array[i];
                                  int j;
                                  for (j=i ;       j>=gap  && array[j-gap] < temp     ; j -= gap)
                                    {
                                            array[j] = array[j-gap];
                                    }
                                  array[j] = temp;
                        }
             }
}




int main()
{
    int N,K, nums[SIZE]; //Kth largest item in the list
    scanf("%d%d",&N,&K);

    //taking input nums array from the user
    for (int i=0; i<N;i++)
       {
         scanf("%d",&nums[i]);
       }

    //decending order
    shellSort(nums, N);

    //print the Kth largest item in the list
    printf("%d\n",nums[K-1]);
    return 0;
}

