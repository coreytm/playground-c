#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
	int index;
	struct Node* prev;
	struct Node* next;
} Node;

Node* new_node(int index);

// returns tail
Node* insert(Node* head, int index);

// returns tail
Node* delete(Node* head, int index);

// traverse all nodes following node->next path and return tail
Node* traverse_forward(Node* head);

// traverse all nodes following node->prev path and return head
Node* traverse_backward(Node* tail);

#endif
