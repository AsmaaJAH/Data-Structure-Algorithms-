#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int n;
int  SIZE=pow(10,4);
int iDeadline[10000];  // priority queue using array
int itemCount = 0;



bool isFull(){
   return itemCount == SIZE;
}

int sum(int iDeadline[]){
    int res=0;
    for (int i =0 ;i<itemCount;i++)
    {
        res= res+ iDeadline[i];
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
                 iDeadline[itemCount] = data;
                 itemCount++;

              }else
              {

                   iDeadline[itemCount] = data;
                  //ascending order for all entered elements not for the itemCount only because of this test case: " 4 /n 20 30 /n 15 30  /n 20 30 /n  15 30"
                  for (int i = 0; i < n ; i++)
                    {
                        for (int j = i+1; j < n ; j++)
                         {
                               if(iDeadline[i] > iDeadline[j])
                               {
                                   temp = iDeadline[i];
                                   iDeadline[i] = iDeadline[j];
                                   iDeadline[j] = temp;
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
          iDeadline[i]=SIZE*2;



    if (n<=SIZE && n>=1)
    {
        for(int j=0;j<n ;j++)
        {
            scanf("%d%d",&d,&i);

            if(d<=SIZE &&d>=1 && i<=SIZE && i>=1)
            {

                    //add this element to the queue
                    enqueue(i);

            }

        }
    }

   printf("%d\n",itemCount);
   return 0;
}
