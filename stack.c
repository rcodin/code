#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int *arr;
	int size;
	int cap;
} st;

st *init_stack (int cap) {
	st *new = (st*)malloc(sizeof(st));
	new->arr = (int *)malloc(sizeof(int) * cap);
	new->cap = cap;
	new->size = 0;
	return new;
}

int push(int val, st *st1) {
	if (st1->size == st1->cap)
		return -1;

	st1->arr[st1->size++] = val;
	return 0;
}

int pop(st *st1) {
	if (st1->size == 0)
		return -1;
	return st1->arr[--st1->size];
}


int main()
{
	st *st1 = init_stack(5);
	printf ("%d\n", push(4, st1)); // #1 push
	printf ("%d\n", push(45, st1)); // #2 push
	printf ("%d\n", push(4000, st1)); // #3 push
	printf ("%d\n", push(41, st1)); // #4 push
	printf ("%d\n", push(444, st1)); // #5 push
	printf ("%d\n", push(4465, st1)); // #6 push, should fail
	printf ("%d\n", pop(st1));
	printf ("%d\n", pop(st1));
	printf ("%d\n", pop(st1));
	printf ("%d\n", pop(st1));
	printf ("%d\n", pop(st1));
	printf ("%d\n", pop(st1));
	printf ("%d\n", push(4465, st1)); // #6 push, should fail
	printf ("%d\n", pop(st1));
}
