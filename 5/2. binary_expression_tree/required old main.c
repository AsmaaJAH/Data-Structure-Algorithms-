// Tree traversal in C from section 4 at collage
#include<stdio.h>
#include<stdlib.h>            // for exit()
#include<ctype.h>            // for isdigit(char )
#include<string.h>
#include <stdbool.h>      // for using bool in c
#include <math.h>
#include <limits.h>         // for INT_MIN
int  MaxSIZE = pow(10,4);

typedef struct Node{
   // store operator or operand
   char data;

   // only valid for operator
   int precedence;

   struct Node* parent;
   struct Node* left;
   struct Node* right;
}CNode, *PNode;

struct  Node* CreateNode(char x)
{

   struct Node*   p = malloc(sizeof(struct Node));
   p->parent = NULL;
   p->left =NULL;
   p->right = NULL;
   p->data = x;
   return p;
}

bool IsOperator(char x)
{
       // Since the only impact of parentheses () is on precedence,
       // they are not considered as operators here
      if(x == '%' || x == '*' || x == '/' || x == '+' || x =='-')
        {
                                    return 1;
        }else{
                                    return 0;
        }
}



bool IsOperand(char x)
{
    return (x >= '0' && x <= '9');

}


bool IsLeftParenthesis(char x)
{
   return    x == '(';
}

bool IsRightParenthesis(char x)
{
   return    x == ')';
}

//priority * / %
int GetPrecedence(char x)
{
   if (IsOperator(x))
   {
        if (x == '*' || x == '/' || x == '%')
          return 2;
        else
          return 1;
   }else{
         //something went wrong so :
         exit(0);
   }

}



//PNode == struct Node
PNode CreateInfixTree(char S[])
{
   // create a dummy root with minimal precedence
   PNode root = CreateNode('0');
   root->precedence = INT_MIN;   // value from #include <limits.h>

   //previous operand of current operator
   PNode preOperand = NULL;


   //previous operator of current operator
   PNode preOperator = root;


   // impact of previous parenthesis, if any
   int correction = 0;

   char* ptr; // token part of this string == token ==ptr
   ptr=S;
   while(*ptr != '\0')
    {
      if (IsOperand(*ptr)) // num
      {
         preOperand = CreateNode(*ptr);
      }
      else if (IsOperator(*ptr)) // * %  + - /
      {
                 PNode p = CreateNode(*ptr);
                 p->precedence = GetPrecedence(*ptr) + correction;
                 if ( p->precedence       >      preOperator->precedence   )
                 {
                    p->left = preOperand;
                    preOperator->right = p;
                    p->parent = preOperator;
                 }
                 else
                 {
                    preOperator->right = preOperand;
                    PNode q = preOperator->parent;

                    while (p->precedence    <=     q->precedence)          q = q->parent;  //traverse

                    p->left = q->right;
                    q->right = p;
                    p->parent = q;
                 }
                 preOperand = NULL;
                 preOperator = p;

      }
      else if ( IsLeftParenthesis(*ptr))
      {
         correction += 2;
      }
      else if (IsRightParenthesis(*ptr))
      {
         correction -= 2;
      }
      else
      {
         //Not valid  part of  string was found  so , //break;
         exit(0);
      }
      ptr++;
   }

   if (preOperand == NULL) //num
      //Not valid  part of  string was found  so:
       exit(0);
   else preOperator->right = preOperand;



   // delete dummy root
   PNode realRoot = root->right;
   free( root);
   if (realRoot)
       realRoot->parent = NULL;


   return realRoot;
}

void PostOrderTraversal(PNode root) //print the postfix
{
      if (root==NULL) return;
      PostOrderTraversal(root->left);
      PostOrderTraversal(root->right);
      printf("%d", root->data);

}

int main()
{


   char S[MaxSIZE];
   scanf("%s",S);

   PNode root = CreateInfixTree(S);

   PostOrderTraversal(root);
}
