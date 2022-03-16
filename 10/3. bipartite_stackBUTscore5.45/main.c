//Asmaa Gamal
//15010473
// Bipartite Graph using Adjacency Matrix and a DFS stack in C
#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>
#include<math.h>

int Nvertics;
bool isBipartite(int G[][Nvertics], int n, int cols)
{
    int u = 0, v = 0;
    int top = 0;
    int *stack = calloc(n, sizeof(int));
    int *color = calloc(n, sizeof(int));
    int *visited = calloc(n, sizeof(int));
    int *pushBACK = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        color[i] = 1;
        stack[top++] = i;

        while (top)
        {
            u = stack[--top];
            pushBACK[u] = 0;
            visited[u] = 1;

			/* Visit each neighbor of u. */
            for (int j = 0; j < cols; j++)
            {
                v = G[u][j];
                if (visited[v]) continue;

                if (color[u] == color[v]) return false;

                color[v] = -color[u];


				if (pushBACK[v]) continue;

                stack[top++] = v;
                pushBACK[v] = 1;
            }
        }
    }

	return true;
}




//zero initialization
void Init(int arr[][Nvertics]) {
  int i, j;
  for (i = 0; i < Nvertics; i++)
    for (j = 0; j < Nvertics; j++)
      arr[i][j] = 0;
}

//push pack
void addEdge(int arr[][Nvertics], int i, int j) { //a=i=index-1
  arr[i-1][j-1] = 1;
  arr[j-1][i-1] = 1;
}


int main() {

  int Edges, a,b;
  scanf("%d%d",&Nvertics,&Edges);

  if(Nvertics>=0 && Nvertics<=pow(10,4) && Edges>=0 && Edges<=pow(10,4) )
   {
      int adjMatrixGraph[Nvertics][Nvertics];
      Init(adjMatrixGraph);

      for (int i=0; i <Edges; i++)
      {
            scanf("%d %d",&a,&b);
            addEdge(adjMatrixGraph, a, b);
      }

      isBipartite(adjMatrixGraph,Nvertics,Nvertics) ? printf( "Yes\n") : printf("No\n");

   }
  return 0;
}

/*
Use the vertex colouring algorithm:

1) Colour any one of your vertices red.

2) Identify all uncoloured vertices that are adjacent to a red vertex. Colour them blue.

3) Identify all uncoloured vertices that are adjacent to a blue vertex. Colour them red.

4) Repeat steps 2 and 3 until all the vertices are coloured red or blue.

5) If there are any two vertices adjacent of the same colour, then your graph is not bipartite, otherwise it is bipartite.

6) If the graph is bipartite, the colouring algorithm will have created the two required sets of points (one red and one blue).
*/
/*
bool isBipartite(int Graph[][Nvertics]) {
        struct Stack* s = createStack(Nvertics);
        int arr visted[Nvertics];
        for (int i = 0; i < Nvertics; i++) {
            if (vis[i] > 0) continue;
            vis[i] = 1;
            push(s,i);
            while (!isEmpty(s)) {
                int curr = s.top;
                pop(s);
                int edges[Nvertics] = graph[curr];
                for (int next=1; i< Nvertics ;next++)
                    if (vis[next] == 0) {
                        vis[next] = vis[curr] ^ 3;
                        push(s,next);
                    } else if (vis[curr] == vis[next]) return false;
            }
        }
        return true;
}



// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
 */

