#define _CRT_NO_SECURE_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void addToHead(int arg) {
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->next = first;
	newNode->data = arg;
	first = newNode;
}

void printList() {
	struct Node* pointer = first;
	while (pointer != NULL) {
		printf("(%d) -> ", pointer->data);
		pointer = pointer->next;
	}
	printf("NULL \n");
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* pointer = first;
	while (pointer != NULL) {
		if ((pointer->data) == value) {
			return 1;
		}
		pointer = pointer->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node * delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct Node* ptr = first;
	int sum = 0;
	while (ptr != NULL) {
		sum += ptr->data;
		ptr = ptr->next;
	}
	return sum;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 == 1) {
			ptr->data *= 10;
		}
		ptr = ptr->next;
	}
}

void iX100(int i){
	struct Node* ptr = first;
	int c = 0;
	while (ptr != NULL) {
		if (c == i) {
			ptr->data *= 100;
			return;
		}
		ptr = ptr->next;
		c++;
	}
}

void r(struct Node * start) {
	if (start->next == NULL) {
		printf("NULL <- (%d)", start->data);
	}
	else {
		r(start->next);
		printf(" <- (%d)", start->data);
	}
}

void reversePrint(struct Node* start) {
	r(start);
	printf("\n");
}


int main() {
	addToHead(10);
	addToHead(20);
	addToHead(40);
	addToHead(30);
	addToHead(50);
	printList();
	printList();

	return 0;
}