// Tree traversal in C from section 4 at collage
#include<stdio.h>
#include<stdlib.h>        // for exit()
#include<ctype.h>        //for isdigit(char )
#include<string.h>
#include <stdbool.h>      // for using bool in c

int  SIZE = pow(10,4);


//this is: stack == tree== nodes== linked list
struct node
{
      int data;
      struct node* left;
      struct node* right;
};
typedef struct LIFO stack; //stack * ==nptr


void create (stack **top)
{
   *top = NULL;
}

// Create a new Node
struct node*     createNode(int value)
 {
      struct node*   newNode = malloc(sizeof(struct node));

      newNode->item = value;
      newNode->left = NULL;
      newNode->right = NULL;

      return newNode;
}

// Insert child on the left of the parent node
struct node* insertLeft(struct node* root, int value)
 {
      root->left = createNode(value);
      return root->left;
}


// Insert child on the right of the parent node
struct node* insertRight(struct node* root, int value)
{
      root->right = createNode(value);
      return root->right;
}



void postorderTraversal(struct node* root)
 {
      if (root == NULL) return;
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      printf("%d ->", root->item);
}

//priority==p
int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

// from infix to binary expression Tree
// fun will return a stack pointer of the top of it
stack*   build(string&  S)
{

    // Stack to hold output nodes of the tree and postfix
    stack *stNodes; //nptr == top
    create(&stNodes);



    // Stack to hold input infix
    stack * stChars;
    create(&stNodes);

    stack * t, t1, t2;
 /*
    // Prioritising the operators
    int p[123] = { 0 };
    p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
    p[')'] = 0;
*/



    for (int i = 0; i < S.length(); i++)
    {
        if (s[i] == '(') {

            // Push '(' in char stack
            stChars.push(s[i]);
        }

        // Push the operands in node stack
        else if (isalpha(s[i]))
        {
            t = newNode(s[i]);
            stN.push(t);
        }
        else if (p[s[i]] > 0)
        {
            // If an operator with lower or
            // same associativity appears
            while (
                !stC.empty() && stC.top() != '('
                && ((s[i] != '^' && p[stC.top()] >= p[s[i]])
                    || (s[i] == '^'
                        && p[stC.top()] > p[s[i]])))
            {

                // Get and remove the top element
                // from the character stack
                t = newNode(stC.top());
                stC.pop();

                // Get and remove the top element
                // from the node stack
                t1 = stN.top();
                stN.pop();

                // Get and remove the currently top
                // element from the node stack
                t2 = stN.top();
                stN.pop();

                // Update the tree
                t->left = t2;
                t->right = t1;

                // Push the node to the node stack
                stN.push(t);
            }

            // Push s[i] to char stack
            stC.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!stC.empty() && stC.top() != '(')
            {
                t = newNode(stC.top());
                stC.pop();
                t1 = stN.top();
                stN.pop();
                t2 = stN.top();
                stN.pop();
                t->left = t2;
                t->right = t1;
                stN.push(t);
            }
            stC.pop();
        }
    }
    t = stN.top();
    return t;
}

int main()
 {

        char  S [10000]="";


        s = "(" + s;
        s += ")";
        nptr root = build(s);

        // Function call
        postorder(root);
    /*
      struct node* root = createNode(1);
      insertLeft(root, 12);
      insertRight(root, 9);

      insertLeft(root->left, 5);
      insertRight(root->left, 6);


      printf("\nPostorder traversal \n");
      postorderTraversal(root);
    */
}
