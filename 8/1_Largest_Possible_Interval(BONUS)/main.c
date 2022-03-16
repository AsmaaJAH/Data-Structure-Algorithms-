#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
 {
            int temp = *a;
            *a = *b;
            *b = temp;
  }

void heapify(int nums[], int N, int i) //heapify ( array name , total num of elements, the node that we will arrange starting from it to the bottom )
{
            // Find the largest, then Swap and heapify again recursively
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < N && nums[left] > nums[largest])
               largest = left;

            if (right < N && nums[right] > nums[largest])
              largest = right;


            if (largest != i)
                {
                      swap(&nums[i], &nums[largest]);
                      heapify(nums, N, largest);
                }

  }

void heapSort(int nums[], int N)
{
                // Build max heap starting down at non leaves and going up to the root
                for (int i = (N / 2) - 1; i >= 0; i--) // if n=10 so i will start at node 4 to node 0
                          heapify(nums, N, i);

                //  ascending order for the heap by putting the biggest element in the back , then heapify the heap again,to get the highest at root again
                for (int i = N - 1; i >= 0; i--)
                    {
                          swap(&nums[0], &nums[i]);
                          heapify(nums, i, 0);
                    }
}

void getINTERVAL(int nums[],int N)
{
    int largestINTERVAL=INT_MIN;
    int interval;
    for(int i=0; i<N-1;i++)
        {


                interval= nums[i+1]-nums[i]; //bigger - smaller  in this sorted heap will always gives me the absolute difference

                if (interval > largestINTERVAL )
                    largestINTERVAL=interval;
        }

        printf("%d",largestINTERVAL);

}


int main()
{
    int N;
    scanf("%d",&N);

    if (N<=0|| N==1)
    {
        printf("0");

    }else
    {

            int nums[N];

            //taking input nums array from the user
            for (int i=0; i<N;i++)
               {
                 scanf("%d",&nums[i]);
               }

            //ascending order
            heapSort(nums, N);

            //print the largest absolute interval between any two inorder consecutive integers in the list
            getINTERVAL(nums,N);
    }
return 0;
}
