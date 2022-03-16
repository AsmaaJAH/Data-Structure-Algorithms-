#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int Q_len = pow(10, 6);
int E_len = pow(10,9);
// create the stack
struct LIFO
{
        int nums[1000000];
        int top;
};
typedef struct LIFO stack;

int isStackEmpty(stack * s){
    if(s->top==-1) return 1;
    else return 0;

}

int isStackFull(stack *s ){
    if(    s->top ==(Q_len)-1     ) return 1;
    else return 0;
}

int main()
{
    stack s;
    s.top=-1;
    int E,Q, real_size =0 ;
    scanf("%d",&Q);
    if (Q>=1 && Q<= (Q_len))
    {
                for(int i=0; i<Q ;i++)
            {

                    scanf("%d",&E);
                    if (E>=1 && E<= (E_len))
                    {


                            if(E==1)
                            {   if (  !isStackFull(&s)  )
                                {   s.top++;
                                    //push
                                    int element;
                                    scanf("%d",& element);
                                    s.nums[s.top]= element;


                                    //counting num of elements in the stack
                                    real_size++;
                                }


                            }else if(E==2)
                            {    if (  !isStackEmpty(&s)  )
                                {
                                    //pop
                                    //printf("%d\n",s.nums[s.top]);
                                    s.top--;

                                    //counting num of elements in the stack
                                    real_size--;
                                }

                            }else if(E==3)
                            {
                                    if(isStackEmpty(&s))
                                    {
                                            printf("Empty\n");
                                    }else
                                    {
                                            //find min
                                            int min= 2147483647;
                                            for(int i=0;i<real_size ;i++)
                                                {
                                                    if (s.nums[i]<=min)
                                                    {
                                                            min =s.nums[i];
                                                    }

                                                }
                                            printf("%d\n", min);
                                    }

                            }
                    }
            }
    }



    return 0;
}
