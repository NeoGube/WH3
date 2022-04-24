#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack s;
	initStack(&s);
	push(&s,'a');
	push(&s,'b');
	push(&s,'c');
	printStack(&s);
	char jaiu =pop(&s);
	printStack(&s);
	int g=isPalindrome(&s);
	printf("%d", g);

}