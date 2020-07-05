#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int *arr;
	int f;
	int b;
	int size;
	int cap;
} qu;

qu *init_queue(int cap) {
	qu *new = (qu *)malloc(sizeof(qu));
	new->arr = (int *)malloc(sizeof(int) * cap);
	new->cap = cap;
	new->size = 0;
	new->f = 0;
	new->b = -1;
	return new;
}

int push(int val, qu *q1) {
	if (q1->size == q1->cap)
		return -1;
	q1->b++;
	q1->arr[q1->b] = val;
	q1->size++;
}

int pop(qu *q1) {
	if (q1->size == 0)
		return -1;
	int val = q1->arr[q1->f++];
	return val;
}

int main()
{
	qu *q1 = init_queue(4);
	push (46, q1);
	push (49, q1);
	push (466, q1);
	push (455555, q1);
	push (4555544, q1);
	push (455551, q1);
	printf ("%d\n", pop (q1));
	printf ("%d\n", pop (q1));
	printf ("%d\n", pop (q1));
	printf ("%d\n", pop (q1));
	printf ("%d\n", pop (q1));
	printf ("%d\n", pop (q1));
	printf ("%d\n", pop (q1));
	printf ("%d\n", pop (q1));
	while (1) {
		sleep(1);
		printf("%d\n", q1->b);
		push (466, q1);
		push (455555, q1);
		push (4555544, q1);
		push (455551, q1);
		printf ("%d\n", pop (q1));
		printf ("%d\n", pop (q1));
		printf ("%d\n", pop (q1));
		printf ("%d\n", pop (q1));
	}
}
