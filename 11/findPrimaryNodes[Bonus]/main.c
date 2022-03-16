#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <math.h>

#define MAX 10000

int N,E;                      // vertices && Edges
int adj[MAX][MAX];          //Adjacency Mat
void create_graph();

int  queue[MAX],
     front = 0,
     rear = 0;

void enqueue(int vertex)
{
        if (rear == MAX-1)
                    //Queue Overflow
                    exit(0);
        else
        {
                if (front == 0)  // if initially empty
                        front = 1;
                rear ++;
                queue[rear] = vertex ;
        }
}

bool isEmpty_queue()
{
        if(front == 0 || front > rear )
                return true;
        else
                return false;
}

int dequeue()
{
        int del_item;
        if (front == 0 || front > rear)
        {
               //Queue Underflow
                printf("-1");
                exit(0);

        }else
        {
                del_item = queue[front];
                front++;
                return del_item;
        }
}


int outDegree(int vertex)
{
        int out_deg = 0;
        for(int i=1; i<=N; i++)
                if(adj[vertex][i] == 1)
                        out_deg++;
        return out_deg;
}


void create_graph()
{
        int origin,destin;

        scanf("%d %d",&N, &E);       //num of vertex & edges


        //if all vertices are terminal and primary
        if (N && E==0)
        {
               //printing in ascending order
               for(int i=1;i<=N;i++)
                    printf("%d\n",i);

                exit(0);

        }
        // initialize the adj matrix
        for (int i =1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = 0;
            }
        }


        for(int i=1; i<=E; i++)
        {
                scanf("%d %d",&origin,&destin);

                if( origin > N || destin > N || origin<=0 || destin<=0)
                {
                        //Invalid
                        printf("-1");
                        exit(0);

                }

                else
                        adj[origin][destin] = 1;
        }



}

void bubble_sort(int a[], int n) {
    int i = 0, j = 0, temp;

    for (i = 0; i < n; i++)
    {   // loop n times - 1 per element
        for (j = 0; j < (n - i - 1) ; j++)
        { // last i elements are sorted already

            if (a[j] > a[j + 1])
            {  // swap if order is broken
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
        int i,v,count,topo_order[MAX],outdeg[MAX];
        create_graph();

        int max_edges = N*(N-1);
        if (N >=1 && N <= pow(10,4) && E >=0 && E <= pow(10,4) && E<=max_edges )
        {
                             //Find the outdegree of each vertex*/
                        for(i=1;i<=N;i++)
                        {
                                outdeg[i] = outDegree(i);
                                if( outdeg[i] == 0 )
                                        enqueue(i);
                        }



                        if (isEmpty_queue())
                        {
                            printf("-1");
                            return 0;
                        }


                        count = -1;
                        while(  !isEmpty_queue( ) && count < N )
                        {
                                v = dequeue();
                                count++;
                                topo_order[count] = v;


                                //Delete all edges going to the new terminal vertex v
                                for(i=1; i<=N; i++)
                                {
                                        if(adj[i][v] == 1)
                                        {
                                                adj[i][v] = 0;
                                                outdeg[i] -- ;
                                                if(outdeg[i] == 0)
                                                        enqueue(i);
                                        }
                                }
                        }

                        //ascending order for the vertices that results from the topological order
                        bubble_sort(topo_order, count+1);



                        //printing
                        if (count ==-1)
                        {
                            printf("-1");
                            return 0;
                        }else
                        {
                              for(i=0; i<=count; i++)
                                printf( "%d\n",topo_order[i] );
                        }


        }else
        {
            printf("-1");

        }


        return 0;
}
