#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>



// A Queue using Doubly Linked List
typedef struct QNode {
    struct QNode *prev, *next;
    int key;
    int  value;
} QNode;

// FIFO Q as my Memory
typedef struct Queue {
    int count; //current
    int capacity;
    QNode *front, *rear;

} Queue;

// pointers to Queue Nodes
typedef struct cashe {
    int linesP;
    QNode** array;
} cashe;




QNode* newQNode(int key ,int value)
{
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->value = value;
    temp->key   = key;



    temp->prev = temp->next = NULL;

    return temp;
}


Queue* createQueue(int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    // empty
    queue->count = 0;
    queue->front = queue->rear = NULL;


    queue->capacity = capacity;

    return queue;
}

cashe* createCashe(int linesP)
{
    cashe* Cashe = (cashe*)malloc(sizeof(cashe));
    Cashe->linesP = linesP;

    Cashe->array = (QNode**)malloc( Cashe->linesP * sizeof(QNode*));


    // Initialize all as empty
    int i;
    for (i = 0; i < Cashe->linesP; ++i)
        Cashe->array[i] = NULL;

    return Cashe;
}

// if not available a memory
int isFull(Queue* queue)
{
    return queue->count == queue->capacity;
}


int isEmpty(Queue* queue)
{
    return queue->rear == NULL;
}

//delete LRU a key from queue
void deQueue(Queue* queue)
{
    if (isEmpty(queue))
        return;

    // if one node,  front to
    if (queue->front == queue->rear)
        queue->front = NULL;

    // Change rear
    QNode* temp = queue->rear;
    queue->rear = queue->rear->prev;

    //remove previous rear
    if (queue->rear)
        queue->rear->next = NULL;

    free(temp);

    // decrement current keys by 1
    queue->count--;
}

//to both queue and Cashe
void Enqueue(Queue* queue, cashe* Cashe, int key, int value )
{
    // If all full, remove the key at the rear
    if (isFull(queue)) {
        // remove key from Cashe
        Cashe->array[queue->rear->key] = NULL;
        deQueue(queue); // to free the node , the front the previoud
    }


    //a new node in the front
    QNode* temp = newQNode(key  ,value);
    temp->next = queue->front;

    // queue is empty, change front and rear
    if (isEmpty(queue))
        queue->rear = queue->front = temp;
    else // change the front
    {
        queue->front->prev = temp;
        queue->front = temp;
    }

    // Add to Cashe also
    Cashe->array[key] = temp;


    queue->count++;
}



//to call or to print from cache memory:
void rKEY(Queue* queue, cashe* Cashe, int key ,int value)
{
    QNode* reqKey = Cashe->array[key];

    //  1. key is not there, so add to the front
    if (reqKey == NULL)
        Enqueue(queue, Cashe, key,value);

    //  2. key is in memory, move the key to front of queue, change pointer
    else if (reqKey != queue->front) {
        // Unlink
        reqKey->prev->next = reqKey->next;
        if (reqKey->next)
            reqKey->next->prev = reqKey->prev;

        // If requested page is rear, change rear ,because this node will be moved to front
        if (reqKey == queue->rear) {
            queue->rear = reqKey->prev;
            queue->rear->next = NULL;
        }

        // Put key in the beginning
        reqKey->next = queue->front;
        reqKey->prev = NULL;

        // Change prev of current front
        reqKey->next->prev = reqKey;

        queue->front = reqKey;
    }
}

int main()
{

    int linesP, capacityC, operationsE, key, value;
    scanf("%d%d",&linesP,&capacityC);

    Queue* q = createQueue(capacityC);
    cashe* Cashe = createCashe(linesP);
    Queue* copy;


    if ( linesP <= pow(10,6) && linesP >=1 && capacityC <= pow(10,6) && capacityC>=0 )
    {
        for (int i=0;i<linesP;i++)
        {
                        scanf("%d%d",&operationsE,&key);
                        if(capacityC==0 && operationsE==1)
                        {
                                    printf("Error\n");
                                    return 0;

                        } else if(capacityC==0 && operationsE==2)
                        {
                                    printf("Not Found\n");
                                    return 0;
                        }

                        switch(operationsE)
                            {
                                    case 1:

                                                    copy=q;
                                                    scanf("%d",&value);
                                                    while(copy->front!=NULL)
                                                    {

                                                             if (copy->front->key == key)
                                                                {
                                                                    copy->front->value= value;

                                                                    //u acssed it , so bring it to the front , deque , and the re -enque in the back
                                                                    rKEY(q, Cashe, key,value );
                                                                    deQueue(q);
                                                                    Enqueue(q, Cashe, key, value );
                                                                    break; //loop

                                                                } else
                                                                        copy->front =copy->front->next;
                                                    }

                                                    //if not exist
                                                    Enqueue(q, Cashe, key, value );

                                                    break;



                                    case 2:


                                                    copy=q;
                                                    bool notExist;
                                                    while(copy->front!=NULL)
                                                    {
                                                             notExist=true;
                                                             if (copy->front->key == key)
                                                                {

                                                                    printf("%d\n", copy->front->value);
                                                                    //u acssed it , so bring it to the front , deque , and the re -enque in the back
                                                                    rKEY(q, Cashe, key ,copy->front->value);
                                                                    deQueue(q);
                                                                    Enqueue(q, Cashe, key, value );

                                                                    notExist=false;

                                                                    break; //loop

                                                                } else
                                                                        copy->front =copy->front->next;
                                                    }


                                                    if (notExist)
                                                    {
                                                      printf("Not Found\n");
                                                      return 0;

                                                    }


                                                    break;

                                    default:
                                        if(operationsE!=1 &&   operationsE!=2 )
                                           {
                                                        printf("Error\n");
                                                        return 0;
                                            }

                     }


        }
    }
    return 0;
}
