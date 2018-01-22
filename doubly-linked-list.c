#include <stdio.h>
#include <stdlib.h>
#include "doubly-linked-list.h"

Node* new_node(int index){
	printf("creating node with index %d\n", index);	

	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->prev = NULL;
	node->next = NULL;

	return node;
}

Node* insert(Node* head, int index){
	Node* node = new_node(index);
	
	if(head == NULL){
		printf("inserting node with index %d as head \n", index);
		head = node;
		return head;
	}
	
	Node* tmpHead = head;
	int pos = 1;
	while(tmpHead->next != NULL && tmpHead->next->index < index){
		tmpHead = tmpHead->next;
		pos++;
	}
	
	printf("inserting node with index %d at position %d\n", index, pos);
	node->next = tmpHead->next;
	node->prev = tmpHead;
	tmpHead->next = node;
	tmpHead->next->prev = tmpHead; 

	return traverse_forward(tmpHead);
}

Node* delete(Node* head, int index){
	if(head == NULL) {
		printf("doubly-linked-list is empty!\n");
		return head;
	}
	
	if(head->index == index){
		printf("deleting head with index %d\n", index);
		Node* tmp = head;
		head = head->next;
		head->prev = NULL;
		free(tmp);

		return traverse_forward(head);
	}

	Node* tmpHead = head;
	int pos = 1;
	while(tmpHead->next != NULL && tmpHead->next->index != index) {
		tmpHead = tmpHead->next;
		pos++;
	}

	if(tmpHead->index == index){
		printf("deleting index %d at position %d\n", index, pos);

		if(tmpHead->index == index){
                        Node* tmp = tmpHead;
                        tmpHead->next = tmpHead->next->next;
                        tmpHead->prev = tmp->prev;
                        free(tmp);
                }
	}
	
	return traverse_forward(tmpHead);
}

Node* traverse_forward(Node* head){
	printf("traversing doubly-linked-list forward\n");

	if(head == NULL){
		printf("the doubly-linked-list is empty!\n");
		return head;
	}
	
	Node* tmpHead = head;
	int pos = 0;
	while(tmpHead->next != NULL){
		printf("index: %d position: %d\n", tmpHead->index, pos);
		tmpHead = tmpHead->next;
		pos++;
	}

	// print the last node
	printf("index: %d position: %d\n", tmpHead->index, pos);
	
	// return the tail of the doubly-linked-list
	return tmpHead;
}

Node* traverse_backward(Node* tail){
	printf("traversing doubly-linked-list backward\n");

	if(tail == NULL) {
		printf("tail is NULL!\n");
		return tail;
	}
	
	Node* tmpTail = tail;
	int pos = 0;
	while(tmpTail->prev != NULL) {
		printf("index: %d position: %d\n", tmpTail->index, pos);
		tmpTail = tmpTail->prev;
		pos++;
	}

	// print the first node
	printf("index: %d position: %d\n", tmpTail->index, pos);
	
	// return the head of the doubly-linked-list
	return tmpTail;
}

int main() {
	Node* head = new_node(0);
	Node* tail = head;

	tail = insert(head, 3);
	tail = insert(head, 1);
	tail = insert(head, 4);
	tail = insert(head, 2);

	traverse_forward(head);
	traverse_backward(tail);

	return 1;
}
