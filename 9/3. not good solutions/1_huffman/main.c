#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


#define maxSIZE 10000
#define maxTREE_HEIGHT 50
char strCOPY[maxSIZE];


//for building a min heap huffman tree nodes
struct heapNode
 {
  char item;
  unsigned freq;
  struct heapNode *left, *right;
};


struct MinHeapTree
{
  unsigned size;              //counter for insertion and deletion == the count of current existed chars
  unsigned capacity;         //tot num of elements in that should be in the heap == num of nodes in the heap tree which includes thee qiven chars + and it will contain the "*" additional nodes
  struct heapNode **array;   //this is to contain the whole tree elements or the array of nodes in the heap tree
};


struct heapNode *newNode(char item, unsigned freq)
{
  struct heapNode *temp = (struct heapNode *)malloc(sizeof(struct heapNode));

  temp->left = temp->right = NULL;
  temp->item = item;
  temp->freq = freq;

  return temp;
}

//to initialize an empty min heap tree
struct MinHeapTree *createMinHeap(unsigned capacity)
{
  struct MinHeapTree * Heap = (struct MinHeapTree *)malloc(sizeof(struct MinHeapTree));

  Heap->size = 0;

  Heap->capacity = capacity; //the tot num of elements in the heap == num of nodes in the heap tree which includes thee qiven chars + the "*" additional nodes

  Heap->array = (struct heapNode **)malloc(Heap->capacity * sizeof(struct heapNode *));
  return Heap;
}

// swap the min node of the heap
void swap(struct heapNode **a, struct heapNode **b)
{
  struct heapNode *temp = *a;
  *a = *b;
  *b = temp;
}

//min  Heapify
void Heapify(struct MinHeapTree *MinHeapTree, int i) {
  int smallest = i;
  int left = 2*i + 1;
  int right = 2*i+ 2;

  if (left < MinHeapTree->size && MinHeapTree->array[left]->freq < MinHeapTree->array[smallest]->freq)
    smallest = left;

  if (right < MinHeapTree->size && MinHeapTree->array[right]->freq < MinHeapTree->array[smallest]->freq)
    smallest = right;

  if (smallest != i)
    {
        swap(      &MinHeapTree->array[smallest]     ,     &MinHeapTree->array[i]);
        Heapify(MinHeapTree, smallest);
    }
}

// Check if size is equal to 1
int checkSizeOne(struct MinHeapTree * Heap)
 {
  return (Heap->size == 1);
}

//extract Min and swap it with the last element
struct heapNode *extractMin(struct MinHeapTree *minHeap) {
  struct heapNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  (minHeap->size) --;
  Heapify(minHeap, 0);

  return temp;
}

void insertMinHeap(struct MinHeapTree *minHeap, struct heapNode *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  //traverse from bottom (at the level directly before leafs )and going up to root
  while (  i!=0   &&                           minHeapNode->freq       <       minHeap->array[(i-1)/2]->freq )
    {
        minHeap->array[i] = minHeap->array[(i-1)/2];

        // go one level up
        i = (i - 1) / 2;
  }
  //insert in its correct place
  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeapTree *minHeap) {
  int n = minHeap->size - 1;
  int i;

  //build starting from the non-leaves up to the root using heapify
  for (i = (n - 1) / 2; i >= 0; --i)
    Heapify(minHeap, i);
}

bool isLeaf(struct heapNode *root)
{
  if(  !(root->left)             &&          !(root->right)   )

         return true;
  else
        return false;
}

struct MinHeapTree *BuildMinHeap(char item[], int freq[], int size)
{
  //to initialize an empty min heap tree
  struct MinHeapTree *minHeap = createMinHeap(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(item[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

struct heapNode *buildHuffmanTree(char item[], int freq[], int size) {
  struct heapNode *left, *right, *top;
  struct MinHeapTree *minHeap = BuildMinHeap(item, freq, size);

  while (!checkSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('*', left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", arr[i]);

  printf("\n");


}

void decode(Node* root, int * index, char  str[])
{
    if (root == NULL) {
        return;
    }

    // found a leaf node
    if (isLeaf(root))
    {
        printf("%c", root->ch);
        return;
    }

    index++;

    if (str[*index] == '0') {
        decode(root->left, index, str);
    }
    else {
        decode(root->right, index, str);
    }
}



void printHCodes(struct heapNode *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printHCodes(root->left, arr, top + 1);
  }

  if (root->right) {
    arr[top] = 1;
    printHCodes(root->right, arr, top + 1);
  }

  if (isLeaf(root)) {

    printf("  %c   | ", root->item);
    printArray(arr, top);
  }
}


void HuffmanCodes(char item[], int freq[], int size) {
  struct heapNode *root = buildHuffmanTree(item, freq, size);

  int arr[maxTREE_HEIGHT ], top = 0;

  printHCodes(root, arr, top);
}


int remove_duplicates(int n)
{
  int k=-1;
  for(int i = 0; i < n ; i++)
  	{
  		for(int j = i + 1; strCOPY[j] != '\0'; j++)
  		{
  			if(strCOPY[j] == strCOPY[i])
			{
  				for(k = j; strCOPY[k] != '\0'; k++)
				{
					strCOPY[k] = strCOPY[k + 1];
				}
 			}
		}
	}
	return k-1;

}
int compare_qsort (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}


void revereseArray(char str[], int start, int end)
{
    char temp='c';
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{


   char str[maxSIZE];
   fgets(str, maxSIZE, stdin); // it will add a null at the ending of the string
   int actualSIZE=strlen(str);
   if(actualSIZE<2 ||actualSIZE>maxSIZE ) return 0;

   //sorting ascending
    //qsort(strCOPY, distinct-1 , sizeof(char), compare_qsort);

    //reverse to be decending
    //revereseArray(strCOPY,0,distinct-2);



   char encodedStr[maxSIZE];
   fgets(encodedStr, maxSIZE, stdin);
   if(strlen(encodedStr)<1 ||strlen(encodedStr)>maxSIZE ) return 0;

   int itemFreq=0;

   //copy
   for (int i=0; i< actualSIZE; i++)
   {
          strCOPY[i]=str[i];


   }


   //remove duplicates
   int distinct=-1;
   distinct = remove_duplicates(actualSIZE);
   int freq[distinct-1];


   for(int i=0; i< distinct-1; i++)//distinct-1 to not consider the enter as a char
   {
       //for each unique element, compare withe the original array and compute its freq
       for(int j=0; j< actualSIZE; j++)
       {
           if (strCOPY[i]==str[j])
           {
                    itemFreq++;
           }
       }
        freq[i]=itemFreq;
        itemFreq=0;
   }



   /*print
   for (int i=0; i< distinct-1; i++)
   {
        printf("%c--->%d" , strCOPY[i], freq[i]);


   }
   */
   HuffmanCodes(strCOPY, freq, distinct-1);
   return 0;



}





/*
fun to remove duplicates if they are twice only:
      int distinct=-1;
      for(  i = 0;  strTOencode[i] != '\0'      ; i++)
        {

                    if(strTOencode[i] == strTOencode[i-1] )
                     {
                                     for (int j=i; j<len  ;j++){
                                           strTOencode[j-1] = strTOencode[j];

                                     }
                     }
        }

*/


/*
int compare_qsort (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

int removeDuplicates( int n)
{
    //sorting
    qsort(strCOPY, n, sizeof(char), compare_qsort);

    //to remove Duplicates
    if (n==0 || n==1)
        return n;

    // To store index of next unique element
    int j = 0;


    for (int i=0; i < n-1; i++)
        if (strCOPY[i] != strCOPY[i+1])
            strCOPY[j++] = strCOPY[i];

    strCOPY[j++] = strCOPY[n-1];

    return j;
}




void sortString( )
{
    // Initially count of all characters to zero.
    int charCount[MAX_CHAR]={0};
    for (int i=0; i<strlen(strTOencode); i++)
        //find the char order in the ascii code and replace in its correct place by making an array of 26 chars counts ------'a'==97------because----> 'a'-'a' will be 0, 'b'-'a' will be 1, so for location of character in count, array we will do str[i]-'a'.
        charCount[strTOencode[i]-'a']++;



  for(int idx=0; idx<strlen(strTOencode);idx++)
         for (int i=0;i<MAX_CHAR;i++)
                    strTOencode[idx] = (char)('a'+i);
}

*/
