//Asmaa Gamal
//15010473
// Bipartite Graph using Adjacency Matrix and a DFS stack in C

#include <stdio.h>
#include<stdbool.h>
#include<math.h>

int Nvertics=-1;
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

//to color nodes using stack in the DFS (    LIFO )
bool colorGraph(int G[][Nvertics],int color[],int pos, int c){

    if(color[pos] != -1 && color[pos] !=c)
        return false;

    color[pos] = c;
    bool ans = true;
    for(int i=0;i<Nvertics;i++){
        if(G[pos][i]){
            if(color[i] == -1)
                ans &= colorGraph(G,color,i,1-c);

            if(color[i] !=-1 && color[i] != 1-c)
                return false;
        }
        if (!ans)
            return false;
    }

    return true;
}

bool isBipartite(int Graph[][Nvertics]){
    int color[Nvertics];
    for(int i=0;i<Nvertics;i++)
        color[i] = -1;

    //start at vertex 0
    int pos = 0;
    // two colors 1 and 0 or red and blue
    return colorGraph(Graph,color,pos,1);

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

      isBipartite(adjMatrixGraph) ? printf( "Yes\n") : printf("No\n");

   }
  return 0;
}
