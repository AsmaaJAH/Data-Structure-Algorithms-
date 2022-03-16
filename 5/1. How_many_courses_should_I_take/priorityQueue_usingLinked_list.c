#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
#include <ctype.h>


int  count=0;
typedef struct node {
    int data;

    // Lower in time comes first,  so they  indicate higher priority
    int priority;

    struct node* next;

} Node;

//Node==struct node
struct node* newNode(int d, int i) //i==priority
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = i;
    temp->next = NULL;

    return temp;
}

int isEmpty(Node** head)
{
    return (*head) == NULL;
}

// Removes the element with (earliest deadlines)the highest priority
void removeLast(Node** head)
{
    if(!isEmpty(head))
    {
                Node* start = (*head);
                while (start->next != NULL )//w2fa2nd before it
                {
                            //traversal to the last node
                            start = start->next;
                            printf("removeLast\n");

                }


                //remove
                struct node* temp = start;
                (start) = (start)->next;
                free(temp);
    }else
    {
        printf("0");//count
        exit(0);
    }

}

// Return the value at last element  priority
int peekLasti(Node** head)
{
    Node* start = (*head); //
    while (start->next != NULL )
    {
                //traversal to the last node
                start = start->next;
                printf("peekLasti\n");

    }


    return start->priority;
}

int sum(Node** head)
{
    int res=0;
    Node* start = (*head);
    while (start != NULL )//d5lte feeh
            {
                res= res+ (start->data);
                //traversal including the last element
                start = start->next;
                printf("sum\n");

            }

    return res;
}


void push(Node** head, int d, int i)
{
    Node* start = (*head);

    Node* temp = newNode(d, i);

    // Special Case: The head of list has less priority than new node. So insert new node firstly
    if ((*head)->priority       >   i)
    {    //lower num indicates higher priority

        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {

        // Traverse and find a position
        while (start->next != NULL &&  start->next->priority < i) //elle wrah is less than it
            {
                start = start->next;
                printf("push\n");


            }


        temp->next = start->next;
        start->next = temp;
    }
}



int main()
{
    int n,d,i;
    scanf("%d",&n);

    //initialize the first node ever
    scanf("%d%d",&d,&i);
    Node* priorityQueue = newNode(d, i);     //hya only one node f al awl w b3deen push in it using its address zy  ma hwa 3awz
    count++;
    if (d>i) //remove what u have just put
    {
                    removeLast(&priorityQueue);
                    count--;
    }

    //initialize the remaining nodes
    for(int j=1;j<n;j++)
    {
            printf("main_for\n");
            scanf("%d%d",&d,&i);
            if (d<i)
            {
                push(& priorityQueue, d, i);
                count++;


            }
    }



    while(sum(&priorityQueue) > peekLasti(&priorityQueue))
    {
        removeLast(&priorityQueue);

        count--;
        if (isEmpty(&priorityQueue))
        {
            printf("%d", count);
            exit(0);

        }
        printf("main_while\n");

    }


    printf("%d", count);

    return 0;
}
