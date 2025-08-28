#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int value;
	struct Node *next;
}Node, *PtrNode;

void createNode(PtrNode* head, int value);
void printList(PtrNode head);
void deleteNode(PtrNode* head, int value);

int main(void) {
	PtrNode head = NULL;
	int value = 5;

	createNode(&head, value);
	value++;
	createNode(&head, value);
	value++;
	createNode(&head, value);
	printList(head);

	deleteNode(&head, 6);
	printf("\n");
	printList(head);

	return 0;
}

void createNode(PtrNode* head, int value){
	PtrNode newNode = (PtrNode)malloc(sizeof(Node));
	if (!newNode) {
		printf("Allocation Failed!");
		exit(1);
	}

	newNode->next = *head;
	newNode->value = value;
	*head = newNode;
}

void printList(PtrNode head) {
	for (PtrNode curr = head; curr != NULL; curr = curr->next) {
		printf("[ %d ]", curr->value);
		if (curr->next != NULL){
			printf(" -> ");
		}
	}
}

void deleteNode(PtrNode* head, int value) {
	PtrNode* trav = head;

	for (; *trav && (*trav)->value != value; trav = &(*trav)->next) {}

	if (*trav) {
		PtrNode temp = *trav;
		*trav = (*trav)->next;
		free(temp);
	}
}

