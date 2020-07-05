#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct key_value_pair  {
	char *key;
	int key_len;
	int val;
} kv;

typedef struct singly_linked_list {
	kv data;
	struct singly_linked_list *next;
} sll_node;

typedef struct hash_map {
	sll_node **arr;
	int cap;
} hmap;


typedef struct hash_map hmap;

hmap *init_hmap (int cap) {
	hmap *new = (hmap *)malloc(sizeof(hmap));
	new->arr = (sll_node **)malloc (sizeof(sll_node *) * cap);
	for (int i = 0; i < cap; i++) {
		new->arr[i] = NULL;
	}
	new->cap = cap;
	return new;
}

// implement the hashing algorithm here
int get_idx (hmap h, char *key, int len) {
	int idx = 0;
	int i = 0;
	for (i = 0; i < len; i++) {
		idx += (key[i] * i);
		idx = idx % h.cap;
	}
	printf("%s %d\n", key,idx);
	return idx;
}

sll_node *create_sll_node(char *key, int k_len, int val) {
	sll_node *new = (sll_node *)malloc (sizeof(sll_node));
	kv *data = &new->data;
	data->key = key;
	data->key_len = k_len;
	data->val = val;
	return new;
}

void insert(hmap *h, char *key, int k_len, int val) {
	int idx = get_idx (*h, key, k_len);

	sll_node *new_node = create_sll_node(key, k_len, val);
	new_node->next = h->arr[idx];
	h->arr[idx] = new_node;
}

int str_comp(char *str1, int str1_len, char *str2, int str2_len) {
	if (str1_len != str2_len)
		return 1;
	for (int i = 0; i < str1_len; i++) {
		if (str1[i] != str2[i])
			return 1;
	}
	return 0;
}

int get_sll_val(sll_node *root, char *key, int k_len) {
	int depth = 0;
	while (root != NULL) {
		if (!str_comp(key, k_len, root->data.key, root->data.key_len))
			return  root->data.val;
		root = root->next;
	}
	return -1;
}

int get(hmap *h,char *key, int k_len) {
	int idx = get_idx (*h, key, k_len);

	return get_sll_val(h->arr[idx] ,key, k_len);
}

int main ()
{
	hmap *h = init_hmap(100);
	insert(h, "abc", 3, 4);
	insert(h, "abd", 3, 54);
	insert(h, "a", 1, 122);
	insert(h, "abdm", 4, 988);
	insert(h, "mra", 3, 54);
	insert(h, "abdmarrpu", 8, 55);
	printf("%d\n", get(h, "abc", 3));
	printf("%d\n", get(h, "a", 1));
	printf("%d\n", get(h, "abdmarrpu", 8));
	return 0;
}
