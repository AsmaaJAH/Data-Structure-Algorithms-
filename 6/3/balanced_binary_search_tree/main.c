#include<stdio.h>
#include<stdlib.h>



#define SIZE 10000
int preOrderArr[SIZE];


struct TreeNode
{
	int data;
	struct TreeNode* left, *right;
};


struct TreeNode* CreateNewNode(int data)
{
	struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

//build tree
struct TreeNode* sortedArrToBST(int nums[], int start, int end)
{

	if (start > end)
	return NULL;

	//make the median or the middle element s a  root
	int mid = (start + end)/2;
	struct TreeNode *root = CreateNewNode(nums[mid]);

	// recursion of the left subtree
	root->left = sortedArrToBST(nums, start, mid-1);

    //recursion of the right subtree
    root->right = sortedArrToBST(nums, mid+1, end);

	return root;
}



// print preorder traversal
int i=0;
void preOrderTraversal(struct TreeNode* node)
{
	if (node == NULL)
		return;
	preOrderArr[i]= node->data;
	i++;
	preOrderTraversal(node->left);
	preOrderTraversal(node->right);

}

void printly(int N){
    for (int i=0; i<N-2;i++){
        printf("%d,",preOrderArr[i]);
    }
    //print the last element without comma after it
    printf("%d",preOrderArr[N-1]);
}

int main()
{
    int N; //num of elements in the Balanced tree
    scanf("%d",&N);
    int nums[N];
    for(int i = 0; i <N; i++){
        scanf("%d",&nums[i]);
    }


	/* Convert List to BST */
	struct TreeNode *root = sortedArrToBST(nums, 0, N-1);
	preOrderTraversal(root);
	printly(N);

	return 0;
}
