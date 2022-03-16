#include <stdio.h>
#include <stdlib.h>


#define SIZE 10000

int N,r, nums[SIZE]; //r removals

//merge sort using 2 aux arrays
void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  //break
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // merge by picking the bigger and put it in his right place
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // put the remaining elements in either L or M
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;    // m== breaking point of the arr

    //recursion
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    //final tot arr
    merge(arr, l, m, r);
  }
}

void duplictionSorting()
{
    /* sort by decreasing frequency (assuming N > 0) */
    for (int i = 0;;) {
        /* find the most repeated sequence in [i..N-1] */
        int rep = nums[i];
        int n = 1, j, k;
        for (j = k = i + 1; j < N; j++) {
            if (nums[j] == nums[j - n]) {
                rep = nums[j];
                k = j + 1;
                n++;
            }
        }
        if (n == 1) {
            /* no more duplicates, f-sort completed */
            break;
        }
        i += n;
        if (k > i) {
            /* shift the repeated sequence in place */
            while (k-- > i) {
                nums[k] = nums[k - n];
            }
            while (n-- > 0) {
                nums[k--] = rep;
            }
        }
    }

}

void revereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
        return n;

    // To store index of next unique element
    int j = 0;


    for (int i=0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            arr[j++] = arr[i];

    arr[j++] = arr[n-1];

    return j;
}

int main()
{
    //input of the global variables
    scanf("%d%d",&N,&r);
    if (r>N)
    {
       printf("0");

    }else if (r==N)
    {
        printf("%d\n",r-N); //print 0

    }else{

                              //taking input nums array from the user
                              for (int i=0; i<N;i++)
                                {
                                    scanf("%d",&nums[i]);
                                }

                              //ascending order by value
                              mergeSort(nums, 0, N - 1);

                              //ascending order by num of duplicates
                              duplictionSorting();

                              //decending
                              revereseArray(nums,0,N-1);


                              //remove or delete  the r removals
                                int count=0; //count == num of elements remaining in array after removal
                                int numsAfterRemoval[N-r];
                                for(int i=r; i<N; i++)
                                    {
                                        numsAfterRemoval[count] = nums[i];
                                        count++;
                                    }


                                //num of distinct elements
                                int distinct=-1;
                                distinct = removeDuplicates(numsAfterRemoval, count);


                                //then print Distinct
                                printf("%d\n",distinct);


        }


  return 0;

}
