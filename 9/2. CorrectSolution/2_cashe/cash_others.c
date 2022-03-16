#include<stdio.h>
#include <stdlib.h>

typedef struct node P;
struct node {
	int data;
	int key;
	P* Next;
	P* Prev;
};

/******************************************************************************/

P* Createlinkedlist(void);
P* insert(P* start);
P* print(P* start);

/******************************************************************************/

int length = 0;
unsigned int size = 0;

/******************************************************************************/

int main(void) {
	int NumberOfoperations, operation;
	P* start = NULL;

	/*************/

	scanf("%d %d", &NumberOfoperations, &size);

	/*************/

	for (int i = 0; i < NumberOfoperations; i++) {
		scanf("%d", &operation);
		if (operation < 1 || operation > 2) {
			printf("Error\n");
		} else {
			switch (operation) {
			case 1:
				if (length == 0) {
					start = Createlinkedlist();
				} else {
					start = insert(start);
				}
				break;

			case 2:
				start = print(start);
			}

		}

	}
	return 0;
}

/******************************************************************************/

P* Createlinkedlist(void) {
	P* new = (P*) malloc(sizeof(P));
	int k, v;
	scanf("%d %d", &k, &v);
	if (size < 1) {
		printf("Error\n");
		return new;
	}
	new->data = v;
	new->key = k;
	new->Next = NULL;
	new->Prev = NULL;
	length++;
	return new;
}

/******************************************************************************/

P* insert(P* start) {
	int k, v, flag = 0;
	P* ptr3 = start;

	scanf("%d %d", &k, &v);
	/*      return if cash =0  */
	if (size < 1) {
		printf("Error\n");
		return start;
	}

	/*      check if there is node has the same key    */
	while (1) {
		if (ptr3->key == k) {
			flag = 1;
			break;
		}
		if (ptr3->Prev != NULL) {
			ptr3 = ptr3->Prev;
		} else
			break;
	}
	/*        if we find node has the same key         */
	if (flag == 1) {
		/*        if the node is the start node            */
		if (ptr3 == start) {
			if (length > 1) {
				ptr3->Prev->Next = NULL;
				start = ptr3->Prev;
				free(ptr3);
				length--;
			} else {
				ptr3->data = v;
				flag = 2;
			} // flag equall 2 indicate that the process of insert alreade completed
		}

		/*       if the node is in the middle or end      */
		else {
			/*       last                */
			if (ptr3->Prev != NULL) {
				ptr3->Prev->Next = ptr3->Next;
				ptr3->Next->Prev = ptr3->Prev;
			}
			/*       middle              */
			else {
				ptr3->Next->Prev = NULL;
			}
			free(ptr3);
			length--;
		}
	}
	/*                   to check the cash is full or not if it full delete node from rare           */
	if (length >= size && flag != 2) {
		if (size > 1) {
			P* ptr2 = start;
			start->Prev->Next = NULL;
			start = start->Prev;
			free(ptr2);
			length--;
		} else if (size == 1) {
			start->data = v;
			start->key = k;
			flag = 2;
		}
	}
	/*                       insert process                             */
	if (flag != 2) {
		P* new = (P*) malloc(sizeof(P));
		P* ptr = start;
		new->data = v;
		new->key = k;
		new->Prev = NULL;
		while (ptr->Prev != NULL) {
			ptr = ptr->Prev;
		}
		ptr->Prev = new;
		ptr->Prev->Next = ptr;
		length++;
	}
	return start;
}

/******************************************************************************/

P* print(P* start) {
	int k;
	int flag = 0;
	P* ptr3 = start;
	P* ptr4 = start;
	scanf("%d", &k);
	/*                      check if there is any element in cash or not            */
	if (length > 0) {

		/*                      search to node which have searched key                  */
		while (1) {
			if (ptr3->key == k) {
				flag = 1;
				break;
			}
			if (ptr3->Prev != NULL) {
				ptr3 = ptr3->Prev;
			} else
				break;
		}
		/*                 flag 1 mean we find it              */
		if (flag == 1) {
			/*               check it is the start node or not     */

			if (ptr3 == start) {
				printf("%d\n", ptr3->data);
				if (length > 1) {
					ptr3->Prev->Next = NULL;
					start = ptr3->Prev;
					while (ptr4->Prev != NULL) {
						ptr4 = ptr4->Prev;
					}
					ptr3->Next = ptr4;
					ptr3->Prev = NULL;
					ptr4->Prev = ptr3;
				}
			}
			/*                the searched now in the middle or last         */
			else {
				printf("%d\n", ptr3->data);
				if (ptr3->Prev != NULL) {
					ptr3->Prev->Next = ptr3->Next;
					ptr3->Next->Prev = ptr3->Prev;
					while (ptr4->Prev != NULL) {
						ptr4 = ptr4->Prev;
					}
					ptr3->Next = ptr4;
					ptr3->Prev = NULL;
					ptr4->Prev = ptr3;
				}
			}
		}
		/* print not found in case we don't find it */
		else {
			printf("Not Found\n");
		}
	}
	/* print not found in case cash =  0  */
	else {
		printf("Not Found\n");
	}
	return start;
}

