#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// definitions & global declarations
#define SIZE 10000
int  decimalBASE= 10;




void swap(long int *a, long int *b) {
  long int temp = *a;
  *a = *b;
  *b = temp;
}


//deciding who is better by concatination
int compareValue_ByConcatination(long int num, long int pivot)
{
    //concatinate num then pivot
    while(pivot>=decimalBASE)
        decimalBASE *= 10;

    long int farward= num*decimalBASE + pivot;



    //concatinate pivot then num
    decimalBASE=10; //returning to its original value
    while(num>=decimalBASE)
        decimalBASE*=10;

    long int reverse= pivot*decimalBASE + num;
    decimalBASE=10; //returning to its original value, for future calling

    if(farward>= reverse) //num > pivot
        return 1;
    else
        return 0;
}





long int partition(long int array[], long int low, long int high) {

  long int pivot = array[high];
  long int i = (low - 1);

  for (long int j = low; j < high; j++)
    {
            if ( compareValue_ByConcatination (array[j] ,pivot))
             {
                  i++;
                  swap(&array[i], &array[j]);
             }
    }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(long int array[], long int low, long int high) {
  if (low < high)
    {
        long int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
  }
}

void print(long int array[], long int size)
{
  for (long int i = 0; i < size; ++i)
    {
        printf("%ld", array[i]);
    }
}

int main()
{
    long int N, nums[SIZE];
    scanf("%ld",&N);
    for (long int i=0; i<N;i++)
    {
        scanf("%ld",&nums[i]);
    }
    quickSort(nums, 0, N - 1);
    print(nums, N);
    return 0;
}



/*

//wrong solutions with a lot of wrong test cases
//the idea her was to decide who is better in value by dividing the num into its digits not by Concatination




#define numOfDIGITS 10
void revereseArray(long int arr[], long int start, long int end)
{
    long int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


//deciding who is better in value by dividing the num into its digits
long int mod[numOfDIGITS]={-1}, numCopy[numOfDIGITS]={-1}, pivotCopy[numOfDIGITS]={-1};

long int  divideDigits(long int num)
{
   long int  count=0;

   while(num > 0) //do till num greater than  0
    {
        mod[count] = num % 10;  //split last digit from number

         num = num / 10;    //divide num by 10. num /= 10 also a valid one
        count++;

    }
    //count == num of digits
    // reverse
    revereseArray(mod,0,count-1);
    return count;
}

//deciding who is better by comparing digits
long int compareValue(long int num, long int pivot) {
    //copy
    long int count=divideDigits(num);
    for(long int i=0;i< count;i++)
         numCopy[i]=mod[i];


    //copy
    long int pivotCount=divideDigits(pivot);
    for(long int i=0;i< pivotCount;i++){
         pivotCopy[i]=mod[i];
    }

    //compare each digit in both nums
    for(long int i=0; i< count ;i++){
        for (long int j=0; j<pivotCount;j++){
            if(numCopy[i]>=pivotCopy[j])
                     return 1;
        }

    }
    //finishing the loop and every digit in the num is smaller than the pivot digits .. no digit in the num is bigger than or equal the pivot
    return 0;

}
*/
