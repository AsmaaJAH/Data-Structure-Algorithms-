#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void pushAtEnd(struct Node** head, int data)
{
    struct Node* pushedNode = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head;

    pushedNode->data  = data;

    pushedNode->next = NULL;

    if (*head == NULL)
    {
       *head = pushedNode;
       return;
    }else
    {
        // traverse to the last node
        while (last->next != NULL) last = last->next;

        last->next = pushedNode;
        return;
    }


}

void displayList(struct Node * head)
{
    struct Node* temp= head;
    if (head!=NULL)
        {
                while(temp!=NULL)
                {
                    printf("%d\n",temp->data);
                    temp= temp->next;
                }
        }
};
struct Node * reverseList(struct Node* head, int N, int recursionCount ){

    struct Node* prev , *current, *nextNode , * headCopy;

    if(head==NULL||head->next==NULL || recursionCount==0)
        return head;


    headCopy = head;
    current = head;
    prev = NULL;
    nextNode = current->next;


    int i = 1;
    while (nextNode != NULL)
    {
        current->next = prev;
        prev = current;
        current = nextNode;
        nextNode = nextNode->next;
        ++i;
        if (i == N)
            break;
    }

    current->next = prev;

    recursionCount--;
    headCopy->next = reverseList(nextNode, N,recursionCount);

    return current;
};


int main() {

    int S,N;
    scanf("%d%d",&S,&N);
    if( (S>=1)  && (S<= 10000) && (N>=1) && (    N <= pow(10,9)    ))
    {
        int digit;
        struct Node* head = NULL;
        for (int i =0; i<S ;i++)
        {
                scanf("%d",&digit);
                pushAtEnd(&head, digit);
        }


        if (N==1 || S<N || S==1)
        {
                displayList(head);
        }
        else if (N!=1 && S>=N  )
        {
            int recursionCount =S/N;
            head = reverseList(head,N,recursionCount);
            displayList(head);

        }


    }




    return 0;
}
