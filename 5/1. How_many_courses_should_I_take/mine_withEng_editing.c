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

int isEmpty(Node* head)
{
    return head == NULL;
}


//removes element on head of queue 
Node * dequeue(Node* head) // returns a Node* which is the new head  
{
 	
 if (head == NULL){
 return head;
 }	
	

   Node* temp;
   temp = head;
   head = head->next;

 return head;
}




void enqueue(Node* head, int d, int i)
{

    Node* start = head;

    Node* temp = newNode(d, i);
    
    
	
    // Special Case: The head of list has less priority than new node. So insert new node firstly
    if (  head->priority  >   i)
    {    //lower num indicates higher priority

        // Insert New Node before head
        temp->next = head;
        head =  temp;
    }
    else {
	
        // Traverse and find a position
        while (start->next != NULL &&  start->next->priority < i) //elle wrah is less than it
            {
            
                start = start->next;
            }


        temp->next = start->next;
        start->next = temp;
        
    }
}


int main()
{
    int n,d,i;
   
    scanf("%d ",&n);

    Node* priorityQueue = newNode(d, i); //hya only one node f al awl w b3deen push in it using its address zy  ma hwa 3awz

    for(int j=0;j<n;j++)
    {
            scanf("%d %d",&d,&i);
            if (d<i)
            {
            	if (j==0){
            	priorityQueue->data = d;        //bad implementation bs 3shan lazm yb2a feh value in the head (first node) w mynf3sh n5leha be ay value kda; 
            	priorityQueue->priority =i;
            	continue;
            	}
           
                enqueue(priorityQueue,d,i);
            
            }
    }



// days  counts the days passed in the semester so far after taking each course
int days = 0;
while (!(isEmpty(priorityQueue))){

		
	if ((days+priorityQueue->data) <= priorityQueue->priority){
	count++;

	 days = days + priorityQueue->data;
	
		 priorityQueue = dequeue(priorityQueue); // lw m7ttsh el return of dequeue (new head) fel head of queue kda el head hyfdl zy ma howa mbyt8yrsh;
		
	
	}
	else{

	        priorityQueue = dequeue(priorityQueue);
		}

}





    printf("%d\n", count);

    return 0;
}
