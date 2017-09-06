#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node node;

struct Node{
	int item;
	node* next;
};

node* tail = NULL;

node* createList(){
	return NULL;
}

node* insert(node* head, int item){
	node* new_node = malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;
	if(head == NULL){
		tail = new_node;
		return new_node;
	}
	tail->next = new_node;
	tail = new_node;
	return head;
}

int isPrime(node* head, int num){
	node* current = head;
	while(current != NULL && current->item <= sqrt(num)){
		if(!(num%current->item))
			return 0;

		current = current->next;
	}

	head = insert(head,num);

	return 1;
}


int main(){
	node* primos = createList();
	int num = 3;

	primos = insert(primos,2);
	printf("2\n");

	while(1){
		if(isPrime(primos,num)) printf("%d \n", num);

		num+=2;
	}

	return 0;
}
