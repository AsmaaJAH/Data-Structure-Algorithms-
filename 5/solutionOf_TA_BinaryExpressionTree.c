#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/******************************** Tree Stack ********************************/
struct TreeNode
{
    char data;
    struct TreeNode *left, *right;
};

struct TreeStackNode {
    struct TreeNode* data;
    struct TreeStackNode *next, *previous;
};

struct TreeStack {
    int size;
    struct TreeStackNode *top;
} *treeStack;

struct TreeStackNode* popTreeNode(){
    if (treeStack->size == 0)
        return NULL;
    treeStack->size--;
    struct TreeStackNode* top = treeStack->top;
    treeStack->top = top->previous;
    return top;
}

void pushTreeNode(struct TreeNode* data) {
    struct TreeStackNode* new = (struct TreeStackNode*) malloc(sizeof (struct TreeStackNode));
    new->data = data;
    new->next = new->previous = NULL;
    treeStack->size++;
    if (treeStack->size == 1) {
        treeStack->top = new;
        return;
    }
    struct TreeStackNode* top = treeStack->top;
    treeStack->top->next = new;
    treeStack->top = new;
    treeStack->top->previous = top;
}

/******************************** Character Stack ********************************/
struct CharStackNode {
    char data;
    struct CharStackNode *next, *previous;
};

struct CharStack {
    struct CharStackNode *top;
    int size;
} *charStack;

struct CharStackNode* popChar() {
    if (charStack->size == 0)
        return NULL;
    charStack->size--;
    struct CharStackNode* top = charStack->top;
    charStack->top = top->previous;
    return top;
}

void pushChar(char data) {
    struct CharStackNode* new = (struct CharStackNode*) malloc(sizeof (struct CharStackNode));
    new->data = data;
    new->next = new->previous  = NULL;
    charStack->size++;
    if(charStack->size == 1) {
        charStack->top = new;
        return;
    }
    struct CharStackNode* top = charStack->top;
    charStack->top->next = new;
    charStack->top = new;
    charStack->top->previous = top;
}

struct CharStackNode* peekChar() {
    return charStack->top;
}

int isCharStackEmpty() {
    return charStack->size == 0;
}

/******************************** Tree Construction ********************************/
int isOperand(char ch) {
    return ch >= '0' && ch <= '9';
}

int getPrecedence(char operation) {
    switch (operation) {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
    case '%':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

struct TreeNode* newTreeNode(char data) {
    struct TreeNode* treeNode = (struct TreeNode*) malloc(sizeof (struct TreeNode));
    treeNode->data= data;
    treeNode->left = treeNode->right = NULL;
    return treeNode;
}

void constructOperationNode() {
    struct TreeNode* node = newTreeNode(popChar()->data);
    struct TreeStackNode* right = popTreeNode();
    struct TreeStackNode* left = popTreeNode();

    node->left = left->data;
    node->right = right->data;
    pushTreeNode(node);
}

struct TreeNode* constructTree(char* expression) {
    for (int i = 0; i < strlen(expression); i++) {
        if (isOperand(expression[i])) {
            pushTreeNode(newTreeNode(expression[i]));
        }
        else if (expression[i] == '(') {
            pushChar(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!isCharStackEmpty() && peekChar()->data != '(' && treeStack->size > 1) {
                constructOperationNode();
            }
            popChar();
        }
        else if (getPrecedence(expression[i])) {
            while (!isCharStackEmpty() && peekChar()->data != '(' && treeStack->size > 1 &&
                   getPrecedence(expression[i]) <= getPrecedence(peekChar()->data)) {
                constructOperationNode();
            }
            pushChar(expression[i]);
        }
    }
    return popTreeNode()->data;
}


void printPostorder(struct TreeNode* node) {
    if(node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c", node->data);
}

/******************************** Main ********************************/
int main()
{
    char expression[10002];
    scanf("%s", expression);
    
    // Initialize stacks
    treeStack = (struct TreeStack*) malloc(sizeof (struct TreeStack));
    treeStack->size = 0;
    charStack = (struct CharStack*) malloc(sizeof (struct CharStack));
    charStack->size = 0;
    
    // Add parenthesis to the expression
    strcat(expression, ")");
    pushChar('(');
    
    // Construct expression tree
    struct TreeNode* root = constructTree(expression);
    printPostorder(root);

    return 0;
}
