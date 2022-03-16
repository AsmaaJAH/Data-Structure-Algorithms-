#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /******************************************* inputs ***********************************************/
    int n ,m,mat1_counter=0 ;
    scanf("%d%d",&n,&m);
    int mat1[n][m];

    if( n==0    ||    m==0    ||   n > (2^31) - 1     ||     n< -(2^31)  ||  m > (2^31) - 1    ||    m< -(2^31) )
    {
        printf("Not Valid");
    }else
    {


        for(int i=0; i<n;i++){
            for(int j=0; j<m ; j++){
                       scanf("%d",&mat1[i][j]);
                       mat1_counter++;
            }
        }

    }



    int k ,w,mat2_counter=0;
    scanf("%d%d",&k,&w);
    int mat2[k][w];

    if( k==0    ||    w==0    ||   k> (2^31) - 1     ||    k< -(2^31)  ||   w> (2^31) - 1    ||    w< -(2^31) )
    {
        printf("Not Valid");
    }else
    {


        for(int i=0; i<k;i++){
            for(int j=0; j<w ; j++)
            {
                       scanf("%d",&mat2[i][j]);
                       mat2_counter++;
            }
        }
    }
        /******************************************* multiplication ***********************************************/
    int out[n][w];
    if ( (mat1_counter > (n*m)/2) &&(mat2_counter > (k*w)/2) && m==k)
    {




                for(int i=0; i<n;i++)
                {
                    for(int j=0; j<w ; j++)
                    {
                        out[i][j]=0;
                        for(int c=0;c<k;c++)
                        {
                            out[i][j]+=mat1[i][c]*mat2[c][j];
                        }
                    }
                }
                /******************************************* output ***********************************************/


                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<w;j++)
                    {
                            printf("%d ",out[i][j]);
                    }

                    printf("\n");
                }

    }else
    {
            printf("Not Valid");
    }




    return 0;
}
