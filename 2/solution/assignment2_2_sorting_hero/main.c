#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void do_selection_sort(int count,int* number);


int main()
{

    int N,Q;
    scanf("%d%d",&N,&Q);
    if (N>=0 && (N<=4 * (10^4)) && Q>=0 && (Q<=4 * (10^4)) ) // these are the constraints
    {
        int h[N], t[Q];

        for (int i=0 ; i<N ; i++)
            {
                scanf("%d",&h[i]);

            }
        for (int i=0 ; i<Q ; i++)
            {
                scanf("%d",&t[i]);
            }



        do_selection_sort(N,h);
        do_selection_sort(Q,t);

        int employers=0;
        for (int i=0; i<Q;i++){
            for (int j=0; j<N; j++){
                    if(t[i]<=h[j]){
                        employers++;
                        h[j]=0;
                        break;
                    }

            }
        }

        printf("%d",employers);
        }


    return 0;
}

void do_selection_sort(int count,int* number){

   int i, j, temp;
   // selection sort
   for(i=0;i<count;i++){
      for(j=i+1;j<count;j++){
         if(*(number+i)>*(number+j)){
            temp=*(number+i);
            *(number+i)=*(number+j);
            *(number+j)=temp;
         }
      }
   }


}
