#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>  //for INT_MAX


#define maxSIZE 10000

typedef struct prioQueue prioQueue;
struct prioQueue{
    char data;
    int prio;
};
//first prio que
prioQueue pri_que[maxSIZE];
int front1=-1, rear1=-1, queueSize1=-1;

//second prio que
prioQueue second_prio_que[maxSIZE];
int front2=-1, rear2=-1, queueSize2=-1;



void insert_by_priority(prioQueue que[],int data, int prio, int *front , int *rear,int * queueSize )
{
    //overflow
    if ((*rear) >= maxSIZE - 1)  return;


    //first inserstion
    if ((  (*front) == -1) && ((*rear) == -1))
    {
        (*front)  ++;
        (*rear)++;
        queueSize++;
        que[*rear]->data = data;
        que[*rear]->prio = prio;
        return;
    }
    else
        check(que,data, prio);
    (*rear) ++;
}

//arranging the min priority queue in freq
void check(prioQueue que[], int data, int prio, int front, int rear)
{
    int i,j;
    //arranging according to freq
    for (i = 0; i <= rear; i++)
    {
                if (prio < que[i].prio)
                {
                    for (j = rear + 1; j > i; j--)
                    {
                        //if the new data is smaller then return this old item to the back by one step and put the new data at the beginning
                        que[j] = que[j - 1];
                    }
                    que[i]->data = data;
                    que[i]->prio = prio;
                    return;


                //if equal freq arrange acording to the decreasing order ascii code
                }else if (prio ==que[i]->prio)
                {
                    if(data >= pri_que[i]->data && data !='*')
                    {
                            for (j = rear + 1; j > i; j--)
                                {
                                    //if the new data is smaller then return this old item to the back by one step and put the new data at the beginning
                                    que[j] = que[j - 1];
                                }
                                que[i]->data = data;
                                que[i]->prio = prio;
                                return;

                    }

                }
    }
    que[i] = data;
    que[i].prio = prio;
}

void delete_by_priority(int data, int front, int rear)
{
    int i;

    // empty
    if ((front==-1) && (rear==-1)) return;

    for (i = 0; i <= rear; i++)
    {
        if (data == que[i])
        {
                    for (; i < rear; i++)
                    {
                        pri_que[i] = pri_que[i + 1];
                    }

                   rear--;

                   if (rear == -1) front = -1;
        }
    }

}

void display_pqueue()
{
    //empty
    if ((front == -1) && (rear == -1)) return;

    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }

    front = 0;
}


void dequeuing_two_elements()
{


    int real_size= queueSize +1;
    for(int i=0; i< strlen(pri_que)-1 ;i+=2){
        insert_by_priority ( second_prio_que  ,        '*'    ,       pri_que[i].prio  +  pri_que[i+1].prio, &front2, &rear2, &queueSize2)
        real_size-=2;
        front1 -=2;

    }

    //combine the last element by its correct prio with the second queue elements
    if (real_size==1){
        insert_by_priority(second_prio_que, pri_que[strlen(pri_que)-1].data , pri_que[strlen(pri_que)-1].prio ,&front1, &rear1 ,&queueSize1);
    }

    if(){

    }

}

int main()
{
   char str[maxSIZE];
   fgets(str, maxSIZE, stdin); // it will add a null at the ending of the string
   if(strlen(str)<2 ||strlen(str)>maxSIZE ) return 0;




   char encodedStr[maxSIZE];
   fgets(encodedStr, maxSIZE, stdin);
   if(strlen(encodedStr)<1 ||strlen(encodedStr)>maxSIZE ) return 0;

   int freq=0;
   for(int i=0; i< strlen(str; i++)
   {
       for((int j=i+1; j< strlen(str; j++))
       {
           if (str[i]==str[j])
           {
                    freq++;
           }
           insert_by_priority(str[i],freq);
           freq=0;
       }
   }
   dequeue ()

    return 0;
}
