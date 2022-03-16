#include <stdio.h>
#include <stdlib.h>

struct node{    //  CREATE A NODE THAT CONSISTS OF DATA , POINTER TO NEXT NODE
int data;
struct node *next;
}*top=NULL;

void push(int data)  //PUSH -> INSERT AT THE BEGINNING (TOP OF STACK)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));

    if (newNode==NULL)      //UNABLE TO ALLOCATE MEMORY FOR THE NEW NODE
    {
        return;
    }
    else
    {
        newNode->data=data;     //ASSIGN THE DATA IN THE NEW NODE
        newNode->next=top;      //UPDATE THE POINTER OF THE NODE
        top=newNode;            //UPDATE THE TOP OF STACK
    }
}

int pop()      //POP-> DELETE AT THE BEGINNING (TOP OF STACK)
{
    struct node *toDelete;

    if(top==NULL)           //THE STACK IS EMPTY
    {
        return 0;
    }
    else
    {
        toDelete=top;       //ASSIGN THE TOP OF STACK TO BE DELETED
        top=top->next;      //UPDATE THE TOP OF STACK TO THE NEXT ONE
        return(toDelete->data);
        free(toDelete);     //FREE THE MEMORY
    }
}

int isEmpty()           //CHECK WHETHER THE STACK IS EMPTY OR NOT
{
    if (top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int isBipartite(int V, int G[V][V] , int src )
{
    int arr[V];
    int i;
    int u,v;
    for (i=0 ; i<V ; ++i)
    {
        arr[i] = -1;
    }

    arr[src] = 1;
    push(src);

    while(isEmpty()==0)
    {
        u=pop();

        if( G[u][u] == 1 )
        {
            return 0;
        }

        for (v=0; v<V ; ++v)
        {
            if( G[u][v] && arr[v] == -1 )
            {
                arr[v] = 1-arr[u];
                push(v);
            }
            else if( G[u][v] && arr[v] == arr[u] )
            {
               return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int V,E;        // V -> NUMBER OF VERTICES    E -> NUMBER OF EDGES
    int i,j;        // COUNTERS
    int a,b;        // GENERAL VERTICES
    int flag;       // TO CHECK WHAT THE FUNCTION RETURNS
    int src=0;

    scanf("%d",&V);
    scanf("%d",&E);

    int G[V][V];

    //INITALIZE ALL THE VALUES IN THE MATRIX WITH ZERO
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            G[i][j]=0;
        }
    }

    for(i=0;i<E;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);

        // IF THERE IS AN EDGE BETWEEN 2 VERTICES a & b -> SET '1' IN THE MATRIX

        G[a-1][b-1]=1;
    }


    flag=isBipartite(V,G,src);

    if(flag ==1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}
