#include <stdio.h>
#include <stdlib.h>
////////--------------------------------------------firstly: constructing the BST tree using the level by level traversal -----------------------------------
#include <stdbool.h>


#define SIZE 10000
//global
int N; // number of elements in the tree
int traversal[SIZE]; // tree data after traversal it

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

    queue->array = (struct node**) malloc(queue->size * sizeof( struct node* ));

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

// level order traversal
void  levelOrder(struct node* root)
{
    struct Queue* queue = createQueue(SIZE);

    Enqueue(root, queue);
    int i=0;
    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);

         traversal[i]=temp->data ;
         i++;
        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }

}
////////--------------------------------------------secondly: finding the most freq item using the inorder traversal -----------------------------------
int counter=0;
void inorderTraversal(struct node*root){
        if(root==NULL) return;
        inorderTraversal(root->left);
        traversal[counter]= root->data;
        counter++;
        inorderTraversal(root->right);
}


struct BSTNode
{
    struct BSTNode *left;
    int data;
    int freq;
    struct BSTNode *right;
};

// A structure to store data and its frequency
 struct dataFreq
{
    int data;
    int freq;
};
typedef struct dataFreq dataFreq;
typedef struct BSTNode BSTNode;



/* Function for qsort() implementation. Compare frequencies to
   sort the array according to decreasing order of frequency */
int compare(const void *a, const void *b)
{
    return ( (*(const dataFreq*)b).freq - (*(const dataFreq*)a).freq );
}

/* Helper function that allocates a new node with the given data,
   frequency as 1 and NULL left and right  pointers.*/
BSTNode* newNode(int data)
{
    struct BSTNode* node = (struct BSTNode*) malloc(sizeof( struct BSTNode )) ;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->freq = 1;
    return (node);
}

// A utility function to insert a given key to BST. If element
// is already present, then increases frequency
BSTNode *insert(BSTNode *root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (data == root->data) // If already present
        root->freq += 1;
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to copy elements and their frequencies to count[].
void store(BSTNode *root, dataFreq count[], int *index)
{
    // Base Case
    if (root == NULL) return;

    // Recur for left substree
    store(root->left, count, index);

    // Store item from root and increment index
    count[(*index)].freq = root->freq;
    count[(*index)].data = root->data;
    (*index)++;

    // Recur for right subtree
    store(root->right, count, index);
}

// The main function that takes an input array as an argument
// and sorts the array items according to frequency
dataFreq count[SIZE], copy[SIZE];
void sortByFrequency(int arr[], int n)
{
    // Create an empty BST and insert all array items in BST
    struct BSTNode *root = NULL;
    for (int i = 0; i < n; ++i)
        root = insert(root, arr[i]);

    // Create an auxiliary array 'count[]' to store data and
    // frequency pairs. The maximum size of this array would
    // be n when all elements are different
    //dataFreq count[n];
    int index = 0;
    store(root, count, &index);

    // Sort the count[] array according to frequency (or count)
    qsort(count, index, sizeof(count[0]), compare);

    // Finally, traverse the sorted count[] array and copy the
    // i'th item 'freq' times to original array 'arr[]'
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        for (int freq = count[i].freq; freq > 0; freq--)
            if(count[i].data!=-1){
                copy[j].data = count[i].data;
                copy[j].freq = count[i].freq;
                j++;
            }

    }

}

void printArray( int n)
{
    int maxFreq =copy[0].freq;
    for (int i = 0; i < n; i++)
        if ( (copy[i].data !=copy[i-1].data) && (copy[i].freq == maxFreq) ) //most biggest freq
            printf("%d\n", copy[i].data);

}


int main()
{
    struct node* root = NULL;
    struct Queue* queue = createQueue(SIZE);

    scanf("%d",&N);
    int nums[N];
    for(int i = 0; i <N; i++){
        scanf("%d",&nums[i]);
        buildTree(&root,nums[i],queue);
    }

    //re-traversal the tree
    inorderTraversal(root);

    sortByFrequency(traversal, N);
    printArray( N);


    return 0;
}

