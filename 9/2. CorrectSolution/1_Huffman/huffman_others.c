#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct data queue;
struct data
{
char value;
int freq;
queue* right;
queue* left;	
queue* next;
};
queue* head=NULL;

/**********************************************************/

void ascendingstring(char arr[],int n);
void freq(char arr[]);
void enqueue(queue* new);
void tree(void);
void treenodes(queue * new);
void decode(queue* root,char arr[]);

//void Decode(queue * root,char * arr);

/**********************************************************/

int final[2][100];
int N=0;
int counter2=0;


/**********************************************************/

int main(void){	

int swap=1;
int temp;
char s[100];
char e[100];
	gets(s);
    gets(e);
	int length = strlen(s);
  ascendingstring(s,length);
freq(s);



/**********************************************************/
while(swap!=0)
{
swap=0;
for(int i=1;final[1][i]!=0;i++)
{
if(final[1][i]<final[1][i-1])	
{
temp=final[1][i];
final[1][i]=final[1][i-1];
final[1][i-1]=temp;

temp=final[0][i];
final[0][i]=final[0][i-1];
final[0][i-1]=temp;
swap++;
}	
}	
}
/**********************************************************/
swap=1;
while(swap!=0)
{
swap=0;
for(int i=1;final[1][i]!=0;i++)
{
if(final[0][i]>final[0][i-1] &&final[1][i]==final[1][i-1])	
{
temp=final[1][i];
final[1][i]=final[1][i-1];
final[1][i-1]=temp;

temp=final[0][i];
final[0][i]=final[0][i-1];
final[0][i-1]=temp;
swap++;
}	
}	
}
/**********************************************************/
int counter=0;
while(final[1][counter]!=0)
{
if(counter==0)
{
queue* new = (queue*) malloc(sizeof(queue));
head=new;
new->value=(char)final[0][counter];
new->freq=final[1][counter];
new->left=NULL;
new->right=NULL;
new->next=NULL;
}	
else
{
queue* ptr=head;
queue* new = (queue*) malloc(sizeof(queue));
new->value=(char)final[0][counter];
new->freq=final[1][counter];
new->left=NULL;
new->right=NULL;
new->next=NULL;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=new;
}		
counter++;
}
/**********************************************************/
tree();

decode(head,e);

	return 0;
}


/**********************************************************/

void freq(char arr[])
{
int counter =1,counter2=0;
int flag=0;
final[0][0]=arr[0];
final[1][0]=1;
while(arr[counter]!='\0')
{
if(arr[counter]!=arr[counter-1])
{
counter2++;
final[0][counter2]=arr[counter];
final[1][counter2]++;
}
else
{
final[1][counter2]++;	
} 
counter++;
}	
}

/**********************************************************/

void ascendingstring(char arr[],int n) 
{
int i, j;
char temp;
for (i = 0;i<n-1;i++) 
{
for (j=i+1;j<n;j++)
{
if (arr[i]>arr[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
}

/**********************************************************/

void tree(void)
{
while(head->next!=NULL)
{
queue* new=(queue*)malloc(sizeof(queue));
new->value='=';
new->freq=head->freq+head->next->freq;
new->left=head;
new -> right = head->next;
head=head->next->next;
treenodes(new);
}
}
/**********************************************************/

void decode(queue* root,char arr[])
{
 queue *newroot = root;
 int i=0;
 while(arr[i]!='\0')
 {
      if(arr[i] == '1')
       newroot=newroot->right;        
      else
       newroot = newroot->left;
      if(newroot->value!='='){
       printf("%c",newroot->value);
       newroot=root;
      }
	  i++;
 }  
}

/**********************************************************/

void treenodes(queue* new)
{
queue* ptr=head;
queue* ptr2=NULL;
if(head!=NULL){
if((new->freq==ptr->freq)&&(new->value>ptr->value))
{
head=new;
new->next=ptr;
}
else if(new->freq<ptr->freq)
{
head=new;
new->next=ptr;
}
else{
while ((ptr!=NULL)&&(ptr->freq<=new->freq))
{
if((new->freq==ptr->freq)&&(new->value>ptr->value))
{
new->next=ptr;
ptr2->next=new;
return;
}
ptr2=ptr;
ptr=ptr->next;
}
new->next = ptr;
ptr2->next = new;
}
}
else
{
new->next=NULL;
head=new;
}
}

/**********************************************************/




