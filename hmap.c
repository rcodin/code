#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//insert key value
//get value for key

typedef struct key_value_pair {
	char *str;
	int size;
	int val;
} kv;

typedef struct linked_list {
	int val;
	struct linked_list *next;
} sll;

typedef struct hash_map {
	kv *data;
	int cap;
} hmap;

hmap *init_hmap (int cap) {
	hmap *new = (hmap *)malloc (sizeof (hmap));
	new->data = (kv *)malloc (sizeof (kv) * cap);
	new->cap = cap;
	for () {
	}
}

// implement the hash index generator algo
int get_idx (char *key, int size, int cap) {
	int idx = 0;
	for (int i = 0; i < size; i++) {
		char c = key[i];
		idx += c;
		idx = idx % cap;
	}
	return idx;
}

void insert (hmap *hm1, char *key, int size, int val) {
	
}

void get (hmap *hm1, char *key, int size) {
	
}

int main () {
	//ititialize a list
	char str[100];
	while (1) {
		gets(str);
		printf("%d\n", get_idx (str, strlen(str), 82));
	}
}
