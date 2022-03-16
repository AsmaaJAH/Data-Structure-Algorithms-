#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>



int n;
int  SIZE=pow(10,4);
int duration[10000];  // priority queue using array
int itemCount = 0;




bool isFull(){
   return itemCount == SIZE;
}


int sum(int duration[]){
    int res=0;
    for (int i =0 ;i<n ;i++)
    {
        res= res+ duration[i];
    }
    return res;
}



void enqueue(int data){
   int i = 0;

   if(!isFull())
    {

              // if empty
              if(itemCount == 0)
              {
                 duration[itemCount++] = data;
              }else
              {
                 //not empty
                 for(i = itemCount - 1; i >= 0; i-- )
                 {
                            if(data > duration[i])
                            {
                            //shift item back by one step
                               duration[i+1] = duration[i];
                            }else
                            {
                               break;
                            }
                 }

                 //i will be now i-1
                 //so increase it and put the data here because it is now not larger than any thing
                 duration[i+1] = data;
                 itemCount++;
              }
   }
}

int dequeue(){

    //impossible to be empty here in this code and at hacker rank because i wrote the enqueue firstly
    //delete the biggest item that will make ur duration sum exceeds ur courses deadline
    //int biggestItem=duration[0];
    duration[0]=0;

    //decrease the item count, because the array count is starting from 0 to n-1 ,  then
    //remove the min-priority  item
   return duration[--itemCount];

}


int main() {
    int d,i;
    scanf("%d",&n);
    if (n<=SIZE && n>=1)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d%d",&d,&i);

            //add this element to the queue
            enqueue(d);

            if (i<sum(duration)){
                //if this element will make ur sum exceed the deadline of i remove this element
                dequeue();
            }


        }
    }
   printf("%d\n",itemCount);
   return 0;
}

