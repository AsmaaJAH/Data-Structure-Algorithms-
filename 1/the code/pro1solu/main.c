#include <stdio.h>
#include <stdlib.h>


#define ARRSIZE 5
int main()
{
    int   counter_pos=0  ,counter_neg=0;
    float sum_pos    =0  ,sum_neg=0;

    float positive[ARRSIZE]={0,0,0,0,0};
    float negative[ARRSIZE]={0,0,0,0,0};

    float nums[ARRSIZE];

    printf("Enter 5 numbers:\n");
    for (int i=0;i<ARRSIZE; i++)
    {

            scanf("%f",&nums[i]);

            if(nums[i]>0)
            {
                positive[i]=nums[i];
                sum_pos+=positive[i];
                counter_pos++;

            }else if(nums[i]==0){
                printf("u have just entered a zero!\n");

            }else{
                negative[i]= nums[i];
                sum_neg+=negative[i];
                counter_neg++;
            }
    }

    printf("Number of positive numbers:%d \n",counter_pos);
    printf("Number of negative numbers:%d \n",counter_neg);

    printf("Average of positive numbers:%f \n", sum_pos/counter_pos);
    printf("Average of negative numbers:%f \n", sum_neg/counter_neg);

    return 0;
}
