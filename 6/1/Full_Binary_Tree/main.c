#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define SIZE 10000

// A tree node
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node* createNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// A queue node

struct QueueNode {
    struct Node* val;
    struct QueueNode* next;
};

struct Queue
{
    int size;
    struct QueueNode *front;
    struct QueueNode *rear;
};

void initQueue(struct Queue* q)
{
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
}

void pushQueue(struct Queue* q, struct Node* val)
{
    if(q->front == NULL)//empty
    {
        //rear == front == this node
        q->front = (struct QueueNode*)malloc(sizeof(struct QueueNode));
        q->rear = q->front;
        q->front->val = val;
    }
    else
    {
        //increase the rear then put my data in it
        // by making the rear next as my rear
        q->rear->next = (struct QueueNode*)malloc(sizeof(struct QueueNode));
        q->rear = q->rear->next;
        q->rear->val = val;
    }
    //increase the rear-> next by making it points to null
    q->rear->next = NULL;
}


int isQueueEmpty(struct Queue* q)
{
    return q->front == NULL;
}

struct Node* popQueue(struct Queue* q)
{
    struct QueueNode* temp = q->front;
    //increase the front
    q->front = q->front->next;

    if(q->front == NULL)// becomes empty now
        q->rear = NULL;

    struct Node* val = temp->val;
    free(temp);
    return val;
}

int isFullTree(struct Node* root)
{
    //true: empty or no children
    if(!root || (!root->left && !root->right))
        return 1;

    //false: one child only
    if(!root->left || !root->right)
        return 0;

    //check the remaining subtrees
    return isFullTree(root->left) && isFullTree(root->right);
}


struct Node* buildTree()
{
    struct Queue q;

    initQueue(&q);

    int N, num, index = 1;
    scanf("%d%d",&N, &num);
    struct Node* root = createNode(num);
    pushQueue(&q, root);
    while(index < N && !isQueueEmpty(&q))
    {
        struct Node* cur = popQueue(&q);
        if(cur == NULL)
            continue;

        scanf("%d", &num);
        if(num != -1)
            cur->left = createNode(num);


        scanf("%d", &num);
        if(num != -1)
            cur->right = createNode(num);

        index += 2;

        pushQueue(&q, cur->left);
        pushQueue(&q, cur->right);
    }
    return root;
}


int main()
{

    struct Node* root = buildTree();

    if(isFullTree(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
