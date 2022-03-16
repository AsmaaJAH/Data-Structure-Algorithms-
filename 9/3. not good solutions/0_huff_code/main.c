#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <queue>
#include <unordered_map>

#define EMPTY_STRING ""

// A Tree node
typedef struct Node  Node;
struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};

// Function to allocate a new tree node
 Node* getNode(char ch, int freq, Node* left, Node* right)
{

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));


    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to be used to order the heap
bool  Node_comp(const Node* l, const Node* r)
{

        // the highest priority item has the lowest frequency
        return l->freq > r->freq;
}

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node* root) {
    return root->left == NULL && root->right == NULL;
}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, char  str[], char huffmanCode[])
{
    if (root == NULL) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->left, strcat(str,"0"), huffmanCode);
    encode(root->right, strcat(str,"1"), huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
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

// Builds Huffman Tree and decodes the given input text
void buildHuffmanTree(char text[])
{
    // base case: empty string
    if (text == EMPTY_STRING) {
        return;
    }

    // count the frequency of appearance of each character
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of the highest priority
        // (the lowest frequency) from the queue

        Node* left = pq.top(); pq.pop();
        Node* right = pq.top();    pq.pop();

        // create a new internal node with these two nodes as children and
        // with a frequency equal to the sum of the two nodes' frequencies.
        // Add the new node to the priority queue.

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // `root` stores pointer to the root of Huffman Tree
    Node* root = pq.top();




    if (isLeaf(root))
    {
        // Special case: For input like a, aa, aaa, etc.
        while (root->freq--) {
            printf("%c", root->ch);
        }
    }
    else {
        // Traverse the Huffman Tree again and this time,
        // decode the encoded string
        int index = -1;
        while (index < (int)encodedStr.size() - 1) {
            decode(root, index, encodedStr);
        }
    }
}

char encodedStr[maxSIZE];
int main()
{

   char text[maxSIZE];
   fgets(text, maxSIZE, stdin); // it will add a null at the ending of the string
   if(strlen(text)<2 ||strlen(text)>maxSIZE ) return 0;


   fgets(encodedStr, maxSIZE, stdin);
   if(strlen(encodedStr)<1 ||strlen(encodedStr)>maxSIZE ) return 0;

    buildHuffmanTree(text);

    return 0;
}
