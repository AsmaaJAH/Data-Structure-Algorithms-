#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int Q_len = pow(10, 6);
int E_len = pow(10,9);

int queue[1000000];
int rear = - 1;
int front = - 1;
void enqueue()
{

      int addElement;
      if (rear != Q_len - 1){
                  /*If queue is not full */
            if (front == - 1)
                  /*If queue is initially empty */
                  front = 0;
            scanf("%d", &addElement);
            rear++;
            queue[rear] = addElement;
      }
}
void dequeue()
{
      if (front == - 1 || front > rear)
      {
            //Queue is empty or Underflow
            return ;
      }
      else
      {
            front ++;
      }
}
void printly()
{
      if (front == - 1 || front > rear)
            //Queue is empty
             printf("Empty\n");
      else
      {
            for (int i = front; i < rear; i++){
                printf("%d", queue[i]);
                printf(",");

            }
            //printing the last element in the line
            printf("%d", queue[rear]);
            printf("\n");
      }
}
int main()
{
      int E,Q;
      scanf("%d",&Q);
      if (Q>=1 && Q<= (Q_len))
      {
          for(int i=0; i<Q ;i++)
          {
                scanf("%d", &E);
                if(E==1)
                    enqueue();
                else if(E==2)
                    dequeue();
                else if(E==3)
                    printly();
                else
                    return 0;
          }
      }

    return 0;
}
