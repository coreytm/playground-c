#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
	int index;
	struct Node* next;
} Node;

struct Node* new_node(int index);
void insert(struct Node* head, int index);
void delete(struct Node* head, int index);
void traverse(struct Node* head);


#endif
