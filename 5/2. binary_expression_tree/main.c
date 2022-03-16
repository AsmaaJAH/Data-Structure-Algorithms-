#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */   ///    if the input expression is A B C D use  isalpha(value)
#include<string.h>
#include <math.h>

int MaxSIZE=pow(10,4);


char stack[10000];
int top = -1;


void push(char item)
{
	if(top >= MaxSIZE-1)
	{
		//Stack Overflow.
		exit(0);
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}


char pop()
{
	char data ;

	if(top <0)
	{
		//stack under flow: invalid
		exit(0);
	}
	else
	{
		data = stack[top];
		top --;
		return(data);
	}
}


int is_operator(char symbol)
{
	if(symbol == '%' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


int precedence(char symbol)
{

	if(symbol == '%' || symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void buildPostfix(char infix[], char postfix[]) //build stack tree to transform the infix to postfix

{
    //closing the expression from both sides
	push('(');
	strcat(infix,")");

	int i=0, j=0;
	char value=infix[i];
	char x;





	while(value != '\0')
	{
		if(value == '(')
		{
			push(value);
		}
		else if( isdigit(value) )
		{
			postfix[j] = value;
			j++;
		}
		else if(is_operator(value) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(value))
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
			push(x);
			// reverse what u have just done if the while loop ended or  terminate because u have popped one extra item


			push(value);
		}
		else if(value == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix[j] = x;
				j++;
				x = pop(); // dont push the x again especially if it is a (
			}
		}
		else
		{ // operand not '(' nor ')' and nor operator
        // Invalid infix Expression
			exit(0);
		}
		i++;
		value = infix[i]; //update
	}



	//top should be exactly zero
	if(top>0)
        //Invalid
		exit(0);

	if(top>0)
		//Invalid
		exit(0);


	postfix[j] = '\0';                    /* else puts() will print entire postfix[] upto max SIZE */
}

int main()
{
	char S[MaxSIZE], postfix[MaxSIZE];

	//gets(S);                            //warning: implicit declaration of function ‘gets’; did you mean ‘fgets’?   warning: the `gets' function is dangerous and should not be used.
    fgets(  S, sizeof(S), stdin);        //infix  input


	buildPostfix(S,postfix);
	puts(postfix);                     // print output

	return 0;
}
