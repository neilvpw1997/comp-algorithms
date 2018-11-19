#include <iostream>
using namespace std;
 
typedef struct node{
	int data;
	struct node* next;
} node;

node* new_node(int data){
	node* n = new node;
	n->data = data;
	n->next = NULL;
	return n;
}

typedef struct queue{
	node* front;
	node* rear;
} queue;

queue* create_queue(){
	queue* q = new queue;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void push(queue* q, int x){
	node* n = new_node(x);
	if (q->front == NULL){
		q->front = q->rear = n;
	}
	else {
		q->rear->next = n;
		q->rear = n;
	}
}

int top(queue* q){
	if (q->front == NULL){
		return INT_MIN;
	}
	return (q->front)->data;
}

void pop(queue* q){
	if (q->front != NULL){
		q->front = (q->front)->next;
		if (q->front == NULL){
			q->rear = NULL;
		}
	}
}

int main(){
	queue* q = create_queue();
	push(q, 1);
	push(q, 2);
	push(q, 3);
	cout<<top(q)<<endl;
	pop(q);
	cout<<top(q)<<endl;
	pop(q);
	cout<<top(q)<<endl;
	pop(q);
	cout<<top(q)<<endl;
	return 0;
}
