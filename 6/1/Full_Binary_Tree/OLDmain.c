#include <stdio.h>
#include <stdlib.h>
int Q_len = pow(10, 4);

typedef struct
{
    int data;
    struct TreeNode *right, *left;
}TreeNode;

typedef struct
{
    int front, rear;
    //capacity
    Node* arr[10000];
}queue;

int isEmpty(queue* q)
{
    return (q->front == -1 || (q->front     >     q->rear) );
}

int isFull(Queue* q)
{
    return (q-> rear == Q_len - 1);
}
void enqueue(queue*front,queue* rear, TreeNode* item)
{
    if (isFull(q))
        return;
    rear ++;
    q->arr[rear] = item;
    q->size = q->size + 1;
 }

struct TreeNode * buildTree(int[] numbers,int n){

struct queue *front = NULL;
struct queue *rear = NULL;
struct TreeNode*root;

int index=0;
root= (struct TreeNode*)malloc(sizeof(struct TreeNode));
root->data= numbers[index];

enqueue (&front,&rear,root);



};

int main()
{
    printf("Hello world!\n");
    return 0;
}
