#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000

// tree
struct node
{
    int data;
    struct node *right,*left;
};

//  queue
struct Queue
{
    int front, rear;
    int size;
    struct node* *array;
};

// create a tree node
struct node* create_newNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof( struct node ));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct Queue* createQueue(int size)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));

    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node**) malloc
                   (queue->size * sizeof( struct node* ));

    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}



int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}
int isFull(struct Queue* queue)
{  return queue->rear == queue->size - 1;
}

int hasOnlyOneItem(struct Queue* queue)
{  return queue->front == queue->rear;
}

void Enqueue(struct node *root, struct Queue* queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}

struct node* Dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;

    struct node* temp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;

    return temp;
}


//same as dequeue but without changing the front (peek == read without delete)
struct node* getFront(struct Queue* queue)
{  return queue->array[queue->front];
}


int hasBothChild(struct node* temp)
{
    return temp && temp->left && temp->right;
}


//construct BST by level order traversal
// insert a new node
void buildTree(struct node ** root, int data, struct Queue* queue)
{
    struct node *temp = create_newNode(data);

    // If the tree is empty, initialize the root with new node.
    if (!(*root) )
        *root = temp;
    else if ( (*root)->data == -1 )
        *root = temp;



    else
    {
        // front of the queue.
        struct node* front = getFront(queue);


        // left child as the new node
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;



        if (hasBothChild(front))
            Dequeue(queue);
    }

    // for later insertions
    Enqueue(temp, queue);
}



bool isFullTree (struct node* root)
{
    // If empty
    if (root==NULL)
        return true;
    else if (root->data == -1)
        return true;

    //if leaf
    else if ( (root->left == NULL && root->right == NULL) || (root->left->data == -1 && root->right->data == -1))
        return true;

    else if  (root->left->data != -1 && root->right->data != -1)
        {if ( (root->left) && (root->right) )
                        return (isFullTree(root->left) && isFullTree(root->right)); }

    // We reach here when none of the above conditions work
    return false;
}
int main()
{
    struct node* root = NULL;
    struct Queue* queue = createQueue(SIZE);

    int N; // number of elements in the tree
    scanf("%d",&N);
    int nums[N];
    for(int i = 0; i <N; i++){
        scanf("%d",&nums[i]);
        buildTree(&root,nums[i],queue);
    }

    if (isFullTree(root))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}


/*this is a pseudocode:
array = [1,345,456,67,5,68,3]
queue = []

index = 1;
root = new Node(arr[0])

queue.push(root);

while(!queue.empty())
{
    Node cur = queue.pop();
    if(cur == null)
    continue;
    if(arr[index++] != -1)
        cur->left = new Node(arr[index]);
    if(arr[index++] != -1)
        cur->right = new Node(arr[index]);
    queue.push(cur->left);
    queue.push(cur->right);

}*/






/*
//printing
// Standard level order traversal to test above function
void levelOrder(struct node* root)
{
    struct Queue* queue = createQueue(SIZE);

    Enqueue(root, queue);

    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);

        printf("%d ", temp->data);

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }
}
*/
