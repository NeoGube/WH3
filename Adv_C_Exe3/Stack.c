#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"


/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	return(destroyStack(s->head->next));
	s->head->next = NULL;

}

void push(Stack* s, char data)
{
	charNode* n = (charNode*)malloc(sizeof(charNode));
	charNode* j = (charNode*)malloc(sizeof(charNode));
	n->data = data;
	if (!s->head) {
		s->head = n;
		s->head->next = NULL;
	}
	else {
		n->next = s->head;
		j = s->head;
		s->head = n;
		s->head->next = j;

	}
}

char pop(Stack* s){
	if (!isEmptyStack(s)){
		charNode* j = (charNode*)malloc(sizeof(charNode));
		char ja = s->head->data;
		if (s->head->next){
			
			j->next = s->head->next;
			s->head = j->next;
			return ja;
		}
		s->head = NULL;
		return ja;
	}
	return NULL;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL )
		return 1;
	else if (s != NULL)
		return 0;
}



void printStack(const Stack* s) {
	if (isEmptyStack(s)){
		return;
	}
	charNode* n = s->head;
	while (n!=NULL) {
		printf("%c->", n->data);
		n = n->next;
	}
	printf("\n");
	
}



/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence){
	Stack help; 
	char p = '#';
	char* seek = strtsr(sentence,p);
	int x =strlen(sentence)- strlen(seek),z=x;
	for (int i = 0; i < x; i++){
		printf("%c", sentence[i]);
	}
	seek = strstr(seek, p);
	x= strlen(sentence) - strlen(seek);
	for (int j=z; j < x ; j++){
		push(&help, sentence[j]);
	}
	printStack(&help);
	if (seek = strtsr(sentence, p)){
		return(seek);
	}
	else{
		printf("%s", seek);
	}
}

int isPalindrome(Stack* s){
	if (isEmptyStack(s)){
		return 1;
	}
	else if (!s->head->next) { return 1; }
	else {
		Stack d;
		Stack* a = s;
		int x = 0;
		charNode* j = (charNode*)malloc(sizeof(charNode));
		charNode* t = (charNode*)malloc(sizeof(charNode));

		j = s->head;
		while (j->next) {
			x++;
			j = s->head;
		}
		j = s->head;
		x /= 2;
		for (int z = 0; z < x; z++){
			push(&d, j->data);
			t = j->next;
			pop(a);

		}
		pop(a);
		int l = 0;
		for (int n = 0; n < x; n++){
			if (a->head->data==d.head->data){
				l++;
				a->head = a->head->next;
				d.head = d.head->next;
			}
		}
		if (l==x){
			return 1;
		}
	}
	return 0;
}

void rotateStack(Stack* s, int n)
{
	
}