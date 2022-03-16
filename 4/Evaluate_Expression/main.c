#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
#include <ctype.h>
int MaxSIZE = pow(10,4);

struct LIFO
{
        int value;
        struct LIFO *next;
};
typedef struct LIFO stack;

void create (stack **top)
{
   *top = NULL;
}

void push (stack **top, int element)
{
    stack *newNode ;

    newNode = (stack *)malloc (sizeof(stack));
    if (newNode  == NULL)
    {
       printf("Not Valid" );
       exit(0);
    }

    newNode ->value = element;
    newNode ->next = *top;
    *top = newNode;
}

int pop (stack **top)
{
   int t;
   stack *p;

   if (*top == NULL)
   {
      printf("Not Valid" );
      exit (0);
   }
   else
   {
      t = (*top)->value;
      p = *top;
      *top = (*top)->next;
      free (p);
      return t;
   }
}

int isEmpty (stack **top)
{
   if (*top == NULL)

        return (1);
    else
        return (0);
}

int main() {

    stack *top;
    create(&top);

    char S[MaxSIZE];
    scanf("%s",S);

    char* ptr;
    ptr=S;



    int num1,num2,result=0,intToChar, last;
    bool digit;
    if(*ptr=='\0')
        {
            printf("Not Valid");
            exit(0);
        }
    while(*ptr != '\0') //    this is the same as if i say:   //realSIZE=strlen(S);  //for (int i=0; i<realSIZE  ;i++)
    {
        digit= isdigit(*ptr);
        if(   (!digit) && (*ptr)!=  '+' &&   (*ptr)!='-'    && (*ptr)!='*'   &&  (*ptr)!='/' &&  (*ptr)!='%'    )
        {
                printf("Not Valid");
                exit(0);
        }
        else if(digit)
        {
                    intToChar= *ptr -48;          // transforming char num---into---> int num
                    push(&top,intToChar);



        }else{


                        num1 = pop(&top);
                        num2 = pop(&top);


                        //the allowed operators are *, /, %, +, -
                        switch (*ptr)
                        {
                            case'*':
                            {
                                result=num1*num2;
                                break;
                            }

                            case'/':
                            {
                                if(num1==0)
                                {
                                     printf("Not Valid");
                                     exit(0);

                                }else{
                                    result=num2/num1;
                                    break;
                                }

                            }

                            case'%':
                            {
                               if(num1==0)
                                {
                                     printf("Not Valid");
                                     exit(0);

                                }else{
                                result=num2%num1;
                                break;
                                }
                            }

                            case'+':
                            {
                                result=num2+num1;
                                break;
                            }


                            case'-':
                            {
                                result=num2-num1;
                                break;
                            }

                        }
                        push(&top ,result);
            }
            ptr++;
    }
    last=pop(&top); //popping the  last remaining element in stack so it should become empty now
    if(  isEmpty(&top)   )
            printf("%d",  last );
    else printf("Not Valid" ); // the user entered an empty string so print not valid

    return 0;
}
