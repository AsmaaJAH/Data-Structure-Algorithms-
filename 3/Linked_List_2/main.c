#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

int checkPalindrome(struct Node** left, struct Node* right);

void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}






int main() {
    //input
    int X;
    scanf("%d",&X);
    //transforming a negative num into a +ve one
    if (X<0){
        X= X* -1;
    }

    //split into digits
    struct Node* head = NULL;
    while(X > 0)
    {
        int digit = X % 10;  //split last digit from number
        push(&head, digit);
        X = X / 10;
    }


    //check if the number, X, is palindrome or not
    if (checkPalindrome(&head,head)) {
        printf("YES");
    }
    else {
        printf("NO");
    }



    return 0;
}





int checkPalindrome(struct Node** left, struct Node* right)
{
    // end conditions or terminator
    if (right == NULL) {
        return 1;
    }

    int check;
    check =   checkPalindrome(left, right->next)         &&         ( (*left)->data == right->data);
    (*left) = (*left)->next;

    return check;
}
