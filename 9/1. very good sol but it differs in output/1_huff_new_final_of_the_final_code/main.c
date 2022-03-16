///------------------------------------------ASMAA GAMAL ABDEL-HALEM MABROUK NAGY----------------------------------------------------------------
///-------------------------------------------------------15010474-------------------------------------------------------------------------------
///---------------------Huffman encoding and decoding using max heap tree and the concatination priority is for the min freq nodes---------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


//Global declarations & initialization
#define MAX_CHAR 26

#define maxSIZE 10000


int  n=0;                             //Number of leaf nodes of tree == num of chars
int  freq[maxSIZE]={0};
char strCOPY[maxSIZE]={0};
char strTOencode[maxSIZE]={0};
char strTOdecode[maxSIZE]={0};



struct heapNode
{
	int freq;

	char Data;

	int Parent,Lchild,Rchild;

};

typedef struct heapNode              HTNode;
typedef struct heapNode             *HuffmanTree;


HuffmanTree hTree=NULL;                 //hTree is a struct pointer to the beginning of the array that will contain the elements of the heap tree
typedef char   **HuffmanCode;           // pointer to pointer to a char type


/*
it's the same as saying:
typedef struct
{
	int freq;

	char Data;

	int Parent,Lchild,Rchild;

}   HTNode,     *HuffmanTree;
*/



//-----------------------------------functions prototypes ----------------------------------------------

//input
int  getInput();
int  remove_duplicates( );
void Remove_AllOccurrence(char *str);
void ascendingOrderString();
void revereseArray(char str[], int start, int end);


// Initialize tree to encode and decode
void Initialization();
void encode();
void decode();

//huffman code
void HuffmanCoding (char *,int *,int);
void select        (int j,int *s1,int *s2);   //Select two nodes with zero parents and minimum weight
void find          (char *code,char *text,int i,int m);




//-------------------------------------------------// My Main Driver //--------------------------------------------
int	main()
{

    Initialization();

    encode();

    decode();

	return	0;
}

//----------------------------------------------------------remaining Funtions-----------------------------------------------------


void Remove_AllOccurrence(char *str)
{
	int i, j, k;

	for(i = 0; i < strlen(str); i++)
  	{
  		for(j = i + 1; str[j] != '\0'; j++)
  		{
  			if(str[j] == str[i])
			{
  				for(k = j; str[k] != '\0'; k++)
				{
					str[k] = str[k + 1];
				}
 			}
		}
	}
}


void ascendingOrderString()
{
  int i, j;
  char temp;
  int stringLength = strlen(strTOencode);
  for (i = 0; i < stringLength - 1; i++) {
    for (j = i + 1; j < stringLength; j++) {
      if (strTOencode[i] > strTOencode[j]) {
        temp = strTOencode[i];
        strTOencode[i] = strTOencode[j];
        strTOencode[j] = temp;
      }
    }
  }
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

int remove_duplicates( )
{

    //remove duplicates
    Remove_AllOccurrence(strTOencode);
    strTOencode[strlen(strTOencode)-1]='\0'; //putting a null instead of the last enter \n to remove it

    int distinct=strlen(strTOencode);



    //sorting ascending
    ascendingOrderString();

    //reverse to be decending
    revereseArray(strTOencode,0,   distinct-1 ); //name, start ,end


/*
    //debug:
    printf("here %d\n",distinct);
*/

    //distinct elemnts is from 0 to n-1 but last loop make it to n size
	return distinct; //-1 to remove the enter '\n' from the last
}

int getInput()
{
    //str to encode
   fgets(strCOPY, maxSIZE, stdin);                                // it will add a null at the ending of the string
   if(strlen(strCOPY)<2 ||strlen(strCOPY)>maxSIZE ) return 0;    //strlen() is working without computting this null '\0'


    //str to decode
   fgets(strTOdecode, maxSIZE, stdin);
   if(strlen(strTOdecode)<1 ||strlen(strTOdecode)>maxSIZE ) return 0;
/*/
   //debug:
   printf("strlen(strTOdecode) = %ld  \n",strlen(strTOdecode));
   for (int i=0; i<strlen(strTOdecode) ; i++)
             printf("%c",strTOdecode[i]);
*/

   //copy
   for (int i=0; i<strlen(strCOPY) ; i++)
          strTOencode[i]=strCOPY[i];


   //remove duplicates
   int distinct=-1;
   distinct = remove_duplicates( strlen(strTOencode) );

   //get freq
   int itemFreq=0;
   for(int i=0; i< distinct; i++)
   {
       //for each unique element, compare withe the original array and compute its freq
       for(int j=0; j< strlen(strCOPY); j++)
       {
           if (strTOencode[i]==strCOPY[j])
           {
                    itemFreq++;
           }
       }
        freq[i]=itemFreq;
        itemFreq=0;
   }

/*/

//print
   for (int i=0; i< distinct; i++)
        printf("%c--->%d" , strTOencode[i], freq[i]);

/*/


  return distinct;
}


//-----------------------//Initialization function to establish huffman tree according to the freq weights----------------------------------

void Initialization()
{

	n =	getInput();
	HuffmanCoding(strTOencode,freq,n);
}

//------------------------------------------------------------------------------
															//An algorithm for constructing heffman tree

void HuffmanCoding(char *character, int *freq, int n)
{
    HuffmanTree p;

    //s1 and s2 are the idx of the two selected nodes to be linked or concatenated now in the tree
	int	biggerSIZE,i,s1,s2;
    biggerSIZE =2*n-1;     //by observation, the size after adding stars will be at most = 2*original size -1

	if(n<=1)
		return;

	//new full array of nodes
	hTree=(HuffmanTree)malloc((biggerSIZE+1)* sizeof(HTNode));


	// Initial value
	for(   p=hTree+1 ,i=1       ;            i<=n     ;          ++i,++p,++character,++freq)
	{
	    //copy or move the chars and its freq to the p array of structs from 1--to-->n
		p->Data=*character;
		p->freq=*freq;

		p->Parent=0;
		p->Lchild=0;
		p->Rchild=0;
	}

	for(                   ;            i<=biggerSIZE     ;          ++i,++p   )
	{
	    //put 0 for all remaining nodes chars & freq from n --to-> biggerSIZE
		p->Data=0;
		p->freq=0;

		p->Parent=0;
		p->Lchild=0;
		p->Rchild=0;
	}

	// n==size of original char string  // so i will generate new '*' node, and put it in the beginning of the second half of array
	for(i=n+1;i<=biggerSIZE;++i)
	{
	    //to combine two nodes s1 and s2  we should select them first
		select(i-1,&s1,&s2);

		//same parent
		hTree[s1].Parent=i;
		hTree[s2].Parent=i;

		//child
		hTree[i].Lchild=s1;
		hTree[i].Rchild=s2;

		//sum of freq
		hTree[i].freq    =     hTree[s1].freq   +   hTree[s2].freq;

		//data
		hTree[i].Data    ='*';
	}
}

//---------------------------------- to start the heap huffman tree Select two nodes with zero parents and min freq to be at bottom

void select(int j, int *s1, int *s2)
{
	int	idx;
	for(idx=1;idx<=j;idx++)           //j==n ==size ==num of distincit chars
        {
            //select the first node teqblk without parent yet
              if (hTree[idx].Parent==0)
                {
                    *s1=idx;
                    break;
                }

        }


	for(;idx<=j;idx++)
        {
            //if idx traverse the heap and found a node that have no parent yet, and its freq is less the freq of the *s current node
            		if(        (hTree[idx].Parent==0)      &&     (hTree[idx].freq   <   hTree[*s1].freq)              )
                                *s1=idx;									// Then s1 is the sequence number of the smallest node

        }

	hTree[*s1].Parent=1;	// initial any small value of 1  in advance, it will change later, but putting it here is to avoid being affected when finding summary points and judging conditions




	////-------same for the second node
	for(idx=1;idx<=j;idx++)
		if(hTree[idx].Parent==0)
		{
			*s2=idx;
			break;
		}

    // loop for those who haven't been visited, which is the starting point for comparison
	for(;idx<=j;idx++) //j==size
		if(          (hTree[idx].Parent==0)      &&      (idx!=*s1)      &&       (hTree[idx].freq    <    hTree[*s2].freq))
            *s2=idx;									  // Find the other node with less freq
}


//-------------------------------------------------------encode----------------------------------------------------------------

void encode()
{

	int	i,f,c,start;
	char *outCode;
    HuffmanCode HufCODE;  //// pointer to pointer to a char type called HuffCODE
	{
		HufCODE=(HuffmanCode)malloc(  (   n +1    ) * sizeof (char*));

		outCode=(char *)malloc    (  n *sizeof(char)   );
		outCode[n-1]='\0'; //null to initialize

		for(i=1;i<=n;++i)
		{
                start=n-1;
                for(c=i, f=hTree[i].Parent  ;           f!=0  ;          c=f, f=hTree[f].Parent)
                {
                    if (hTree[f].Lchild==c)
                        outCode[--start]='0';
                    else
                        outCode[--start]='1';
                }
                //decrease the HufCODEsize
                //determine the whole real path traversal of the tree edges of this char or the real length of this concatenated code = n - current index = to iterate again and put the remaining chars in the remaining  concatenated memory space
                HufCODE[i]=(char *)malloc((n-start)* sizeof(char));

                //put the remaining in so copy in order to concatenate the small HufCODE together
                strcpy(    HufCODE[i],   &outCode[start]);
		}
		free(outCode); //free tot out code if u needed to re-use later in another fun call
	}
}

//---------------------------------------------------------- decoding------------------------------------------------------
void decode()
{

	int	biggerSIZE,i;
	char *code,*text;

	code=(char*)malloc(sizeof(char));
    for(i=1;  strTOdecode[i]!='\0';i++)
	{
		code=(char *)realloc(code,(i+1)*sizeof(char));
	}

    //the max size of corresponding text to this code is that every single digit in the code will be translated to one char , so i will just use len(strTOdecode) to malloc
	text=(char *)malloc( strlen(strTOdecode) *sizeof(char));

	biggerSIZE=2* n -1;

    //if 0 , go left in the Left sub tree, starting at m == bottom and going up
	if(*code=='0')
		find(code,text,hTree[biggerSIZE].Lchild,biggerSIZE);

	//if 1 , go right in the right sub tree
	else if(*code=='1')
		find(code,text,hTree[biggerSIZE].Rchild,biggerSIZE);


	//printing
	puts(text);

}

//---------------------------recursivly find the corresponding char leaf node according to 0    1 string in decoding

void find(char *code,char *text,int idx, int biggerSIZE)
        {
            if(*code!='\0')
            {

                               //increase the code ptr cause it is now still in the parent node  '0' or '1' comming from the above decode fun
                                code++;

                                // If base case,leaf node
                                if(hTree[idx].Lchild==0 && hTree[idx].Rchild==0)
                                {
                                            *text=hTree[idx].Data;					   	// Save leaf node characters in text
                                            text++;


                                            //just to make sure this is the end level
                                            if((*code=='0'))
                                                find(code,text,hTree[biggerSIZE].Lchild,biggerSIZE);	   // Continue to find from the left subtree of the root node

                                            else if ((*code=='1'))
                                                find(code,text,hTree[biggerSIZE].Rchild,biggerSIZE);	   // Continue to search from the right subtree of the root node


                                }else // it had one or two childs
                                {
                                            if(*code=='0')
                                                find(code,text,hTree[idx].Lchild,biggerSIZE);	     	 // Find from the left subtree of this node

                                            else if ((*code=='1'))
                                                find(code,text,hTree[idx].Rchild,biggerSIZE);			 // Find from the right subtree of this node


                                }

            }else //if the code is now null this is the end of text too
                *text='\0';
}
///------------------------------------------------------------- DONE!thanks to ALLAH ^^ ----------------------------------------------------




