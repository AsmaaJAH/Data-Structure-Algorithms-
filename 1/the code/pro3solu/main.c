#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
void  add(int*matrix_1,int*matrix_2, int*sum);
void print_sum (int* sum);
int main()
{
    int matrix_1[SIZE][SIZE], matrix_2[SIZE][SIZE];
    int sum[SIZE][SIZE]={0};

    printf("Enter ur input matrix_1 of size 3x3: \n");
    for(int i=0; i<3; i++)
    {
      for(int j=0;j<3;j++) {
         scanf("%d", &matrix_1[i][j]);
      }
      printf("\n");
    }


    printf("Enter ur input matrix_2 of size 3x3:\n");
    for(int i=0; i<3; i++)
    {
      for(int j=0;j<3;j++) {
         scanf("%d", &matrix_2[i][j]);
      }
      printf("\n");
    }


    add(matrix_1,matrix_2,sum);
    printf("sum of both matrices: \n");
    print_sum(sum);

    return 0;
}


void add (int*matrix_1,int*matrix_2, int*sum)
{
    for(int i=0; i<3; i++)
    {
          for(int j=0;j<3;j++)
          {
                *((sum+i)+j)=*((matrix_1+i)+j) + *((matrix_2+i)+j);
          }
          printf("\n");
    }

}

void print_sum (int* sum){
    for(int i=0; i<3; i++)
    {
          for(int j=0;j<3;j++)
          {
                printf( "%d ",    *((sum+i)+j)    );
          }

          printf("\n");
    }
}

