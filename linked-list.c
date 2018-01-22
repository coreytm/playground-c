#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

Node* new_node(int index){
	printf("creating node with index %d\n", index);	

	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = NULL;
	
	return node;
}

void insert(Node* head, int index){
	Node* node = new_node(index);
	
	if(head == NULL) {
		printf("adding index %d as head\n", index);
		head = node;
		return;
	}
	
	Node* tmpHead = head;
	int pos = 1;
	while(tmpHead->next != NULL && tmpHead->next->index < index){
		tmpHead = tmpHead->next;
		pos++;
	}
	
	printf("adding index %d at position %d\n", index, pos);
	node->next = tmpHead->next;
	tmpHead->next = node;

	return;
}

void delete(Node* head, int index) {
	if(head == NULL) {
		printf("The linked-list is empty!\n");
		return;
	}
	
	if(head->index == index) {
		printf("deleting head with index %d\n", index);

		struct Node* tmp = head->next;
		free(head);
		head = tmp;
		return;
	}

	Node* tmpHead = head;
	int pos = 0;
	while(tmpHead->next != NULL && tmpHead->next->index != index){
		tmpHead = tmpHead->next;
		pos++;
	}

	if(tmpHead->next == NULL){
		printf("index %d does not exist\n", index);
		return;
	}
	
	printf("deleting index %d at position %d\n", index, pos);
	Node* tmp = tmpHead->next;
	tmpHead->next = tmpHead->next->next;
	free(tmp);

	return;
}

void traverse(Node* head) {
	if(head == NULL) {
		printf("The linked-list is empty!\n");
		return;
	}
	
	Node* tmpHead = head;
	int pos = 0;
	while(tmpHead->next != NULL){
		printf("position: %d index: %d\n", pos, tmpHead->index);
		tmpHead = tmpHead->next;
		pos++;
	}
	
	// print the last node
	printf("position: %d index: %d\n", pos, tmpHead->index);

	return;
}

int main() {
	printf("Linked List\n\n");

	struct Node* head = new_node(0);
	traverse(head);

	insert(head, 1);
	traverse(head);

	insert(head, 2);
	traverse(head);

	insert(head, 4);
	traverse(head);

	insert(head, 3);
	traverse(head);

	return 1;
}
