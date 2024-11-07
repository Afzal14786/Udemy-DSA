#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

/* Global Nodes*/

struct Node *first = NULL, *second = NULL, *third = NULL;

void Create_List_1 (int A[], int n) {
	struct Node *temp, *tail;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	tail = first;

	for (int i = 1; i < n; ++i) {
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

void Create_List_2 (int A[], int n) {
	struct Node *temp, *tail;
	second = (struct Node *)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	tail = second;

	for (int i = 1; i < n; ++i) {
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

void Display_lists(struct Node *node) {
	while (node != NULL) {
		printf("%d", node->data);
		if (node->next != NULL) {
			printf("-> ");
		}

		node = node->next;
	}
	printf("\n");
}

void Concat(struct Node *first_list, struct Node *second_list) {
	third = first_list;
	while(first_list->next != NULL) {
		first_list = first_list->next;
	}
	first_list->next = second_list;
}

/*
	program for mearging two lists //
*/

void Merge(struct Node *node1, struct Node *node2) {

	if (node1 == NULL || node2 == NULL) {
		printf("Sorry The Merging Is Not Possible Because Any One List is Empty.\n Kindly Check.\n");
		exit(1);
	}

	struct Node *lastNode;
	if (node1->data < node2->data) {
		third = lastNode = node1;
		node1 = node1->next;
		third->next = NULL;
	} else {
		third = lastNode = node2;
		node2 = node2->next;
		third->next = NULL;
	}

	while (node1 && node2) {
		if (node1->data < node2->data) {
			lastNode->next = node1;
			lastNode = node1;
			node1 = node1->next;
			lastNode->next = NULL;
		} else {
			lastNode->next = node2;
			lastNode = node2;
			node2 = node2->next;
			lastNode->next = NULL;
		}
	}

	if (node1) {
		lastNode->next = node1;
	}

	if (node2) {
		lastNode->next = node2;
	}
}

int main() {
	int A[] = {2,4,6,8,10};
	int B[] = {3,5,7,9,11};

	Create_List_1(A, 5);
	Create_List_2(B, 5);

	printf("Here The First List Look Like.\n");
	Display_lists(first);
	printf("Here The Second List Look Like.\n");
	Display_lists(second);

	// concatination function calling here //
	// Concat(first, second);
	// printf("After Concatination The List Look Like.\n");
	// Display_lists(third);

	// here the merge function calls //
	printf("After Merging The List Look's Like.\n");
	Merge(first, second);
	Display_lists(third);

	return 0;
}