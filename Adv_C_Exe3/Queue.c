#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Queue.h"

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	if (q->head == NULL)
	{
		return;
	}
	intNode* p = q->head;
	while (!isEmptyQueue(q)) {
		q = q->head->next;
		free(p);
	}
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* p = (intNode*)malloc(sizeof(intNode));
	p->data = data; // set element data
	p->next = NULL;
	if (!isEmptyQueue(q)) q->tail->next = p; // not Empty?
	//Add after last:
	else q->head = p; // Otherwise - it becomes
	//first
	q->tail = p; // update queue tail
}

unsigned int dequeue(Queue* q)
{
	if (q->head == NULL)
	{
		printf("Cannot dequeue an empty queue!");
		return 0;
	}
	int dtemp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;
	if (q->head == NULL) //if queue gets empty
		q->tail = NULL;//both head and tail NULL
	free(p);
	return dtemp;
}

int isEmptyQueue(const Queue* q)
{
	return ((q->head == NULL && q->tail == NULL));

}


void printQueue(const Queue* q) {
	if (isEmptyQueue(q)) return;
	intNode* p = q->head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("|\n");

}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q)) return;
	intNode* p = q->tail;
	intNode* temp = q->head;
	p->next = q->head;
	while (temp->next != p) {
		temp = temp->next;
	}
	temp->next = NULL;
	q->head = p;
	q->tail = temp;

}

void cutAndReplace(Queue* q)
{
	if (isEmptyQueue(q)) return;
	int count = 0, sum = 0;
	intNode* temp = q->head;
	while (temp != NULL) {
		count++;
		sum += temp->data;
		temp = temp->next;
	}
	if (count % 2 != 0) {
		int avg = sum / count;
		intNode* p = (intNode*)malloc(sizeof(intNode));
		p->data = avg;
		p->next = NULL;
		q->tail->next = p;
		q->tail = q->tail->next;
		count++;
	}
	for (size_t i = 0; i < count / 2; i++)
	{
		rotateQueue(q);
	}
}

void sortKidsFirst(Queue* q)
{
	if (isEmptyQueue(q)) return;
	Queue* temp = q;
	Queue* p = (Queue*)malloc(sizeof(Queue));
	p->head->data = dequeue(temp);
	p->tail->next = NULL;
	while (!isEmptyQueue(temp))
	{
		intNode* remove = temp->head;
		if (remove->data > p->head->data) {
			while (remove->data > p->tail->data)
			{
				p = p->tail->next;
			}
			remove->next = p->tail;
		}
		else {
			remove->next = p->head;
			p->head = remove;
		}
	}


	Queue queue;
	initQueue(&queue);
	enqueue(&queue, 7);
	enqueue(&queue, 4);
	enqueue(&queue, 9);
	enqueue(&queue, 3);
	enqueue(&queue, 2);
	enqueue(&queue, 1);
	enqueue(&queue, 6);
	printQueue(&queue);
	printf("%d\n", dequeue(&queue));
	printQueue(&queue);
	rotateQueue(&queue);
	printQueue(&queue);
	cutAndReplace(&queue);
	printQueue(&queue);
	//sortKidsFirst(&queue);



}