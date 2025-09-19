#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}List, *PtrList;


PtrList createNode(int data) {
	PtrList newNode = (PtrList)malloc(sizeof(List));

	if (!newNode) {
		printf("\nMemory Allocation Failed!\n");
	}
	else {
		newNode->data = data;
		newNode->next = NULL;
	}

	return newNode;
}

void insertFirst(PtrList* head, int data) {
	PtrList newNode = createNode(data);

	newNode->next = *head;
	*head = newNode;
}

void insertLast(PtrList* head, int data) {
	PtrList newNode = createNode(data);
	if (*head) {
		PtrList trav = *head;

		for (; trav->next; trav = trav->next) {}

		trav->next = newNode;
	}
	else {
		*head = newNode->next;
	}
}


void printList(PtrList head) {
	for (PtrList curr = head; curr != NULL; curr = curr->next) {
		printf("%d%s", curr->data, (curr->next) ? " -> " : "\n");
	}
}

void deleteNode(PtrList* head, int data) {
	PtrList* trav = head;
	for (; *trav && (*trav)->data != data; trav = &(*trav)->next) {}

	if (*trav) {
		PtrList temp = *trav;
		*trav = (*trav)->next;
		free(temp);
	}
	else {
		printf("\nNode with that data not found!\n");
	}
}

void deleteFirst(PtrList* head) {
	if (!*head) {
		printf("\nList is Empty!\n");
	}
	else {
		PtrList temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}


void deleteLast(PtrList* head) {
	if (!*head) {
		printf("\nList is Empty!\n");
	}
	else if (!(*head)->next) {
		free(*head);
		*head = NULL;
	}
	else {
		PtrList* trav = head;
		for (; (*trav)->next && (*trav)->next->next; trav = &(*trav)->next) {}

		free((*trav)->next);
		(*trav)->next = NULL;
	}
}


int main() {
	PtrList head = NULL;
	printList(head);

	printf("\nInserting at First\n");
	insertFirst(&head, 10);
	insertFirst(&head, 20);
	insertFirst(&head, 30);
	printList(head);

	printf("\nInserting Last\n");
	insertLast(&head, 60);
	printList(head);

	printf("\nDeleting 20\n");
	deleteNode(&head, 20);
	printList(head);

	printf("\nDeleting First\n");
	deleteFirst(&head);
	printList(head);

	printf("\nDeleting Last\n");
	deleteLast(&head);
	printList(head);


	return 0;
}