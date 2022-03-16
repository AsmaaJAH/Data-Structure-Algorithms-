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
void getMedian(int nums[], int N)
 {

    int mid = N/2;
    float median=INT_MIN;

    //for odd arrays, there is only one median
    if (N % 2 == 1)
        printf("%d", nums[mid]);



    //for even arrays, there are 2 elements as median
    else
    {
        median= (nums[mid-1]+ nums[mid]) / 2.0 ; //their sum over their count ==  their avarage

        //check if the fraction is zeros
        int fraction= abs (median*100); //-10%3=2 so i will make it 10%3=1
        fraction=fraction%100;
        if (fraction<5) //01,02,03,04 ignore them
            printf("%d",(int)median);
        else
            printf("%0.1f", median );
    }
 }


int main()
{
    int N;
    scanf("%d",&N);

    if ( N==0 )
    {
        printf("Not Exist");
        return 0;

    }else if(N>0 && N<= pow(10,4))
    {

            int nums[N];

            //taking input nums array from the user
            for (int i=0; i<N;i++)
               {

                 scanf("%d",&nums[i]);

                 if((nums[i]>pow(10,9))||(nums[i]< -1*pow(10,9)) )
                         {
                             return 0;
                         }

               }

            //ascending order
            heapSort(nums, N);

            //find & print median
            getMedian(nums, N);
    }
return 0;
}
