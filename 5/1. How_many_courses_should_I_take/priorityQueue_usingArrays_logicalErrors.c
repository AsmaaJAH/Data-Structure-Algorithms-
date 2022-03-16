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
    for (int i =0 ;i<itemCount;i++)
    {
        res= res+ duration[i];
    }
    return res;
}



void enqueue(int data)
{
   int temp=0;
   if(!isFull())
    {

              // if empty
              if(itemCount == 0)
              {
                 duration[itemCount] = data;
                 itemCount++;

              }else
              {

                   duration[itemCount] = data;
                  //ascending order for all entered elements not for the itemCount only because of this test case: " 4 /n 20 30 /n 15 30  /n 20 30 /n  15 30"
                  for (int i = 0; i < n ; i++)
                    {
                        for (int j = i+1; j < n ; j++)
                         {
                               if(duration[i] > duration[j])
                               {
                                   temp = duration[i];
                                   duration[i] = duration[j];
                                   duration[j] = temp;
                               }
                         }
                    }

                 itemCount++;
              }
   }
}

void dequeue(){
    itemCount--;
}


int main() {
    int d,i,iMax=0,tempMax=0;
    scanf("%d",&n);


    //initialize all elements of the min priority queue with value bigger than the max value of 10000 == SIZE*2
    for (int i=0;i< n ; i++)
          duration[i]=SIZE*2;



    if (n<=SIZE && n>=1)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d%d",&d,&i);
            //finding the biggest deadline or the max i
            if (i > iMax)
            {
                tempMax=iMax;        //copy to store the old Max
                iMax=i;             // put the new i deadline as the biggest one
            }
            if(d<=SIZE &&d>=1 && i<=SIZE && i>=1)
            {

                    //add this element to the queue
                    enqueue(d);

                    if (sum(duration)>iMax){
                        //if this element will make ur sum exceed the deadline of i remove this element
                        dequeue();
                        if (iMax==i)
                        {
                            iMax= tempMax;
                        }
                    }
            }

        }
    }

   printf("%d\n",itemCount);
   return 0;
}

