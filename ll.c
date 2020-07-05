#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int val;
	struct linked_list *next;
} sll;

sll *init_sll () {
	sll *new = NULL;
	return new;
}

sll *create_node (int val) {
	sll *new = (sll *)malloc(sizeof(sll));
	new->val = val;
	new->next = NULL;
	return new;
}

int sll_remove (sll **root, sll *node) {
	sll *c_node = *root;
	sll *prev = NULL;
	while (c_node != NULL) {
		if (c_node == node) {
			//delete root
			if (prev == NULL)
				*root = c_node->next;
			else {
				prev->next = c_node->next;
			}
		}
		prev = c_node;
		c_node = c_node->next;

	}

	return -1;
}

int sll_insert (sll **root, sll *node) {
	node->next = *root;
	*root = node;
	return 0;
}

void sll_traverse (sll *root) {
	while (root != NULL) {
		printf ("%d\n", root->val);
		root = root->next;
	}
}

sll *sll_find (sll *root, int val) {
	while (root != NULL) {
		if (root->val == val)
			return root;
		root = root->next;
	}
	return NULL;
}


int main () {
	//ititialize a list
	sll *root = init_sll();
	sll *temp = create_node(4);
	sll_insert (&root, temp);
	temp = create_node(78);
	sll_insert (&root, temp);
	temp = create_node(455);
	sll_insert (&root, temp);
	temp = create_node(4544);
	sll_insert (&root, temp);
	temp = create_node(451);
	sll_insert (&root, temp);
	temp = create_node(458);
	sll_insert (&root, temp);
	temp = create_node(4545);
	sll_insert (&root, temp);
	temp = create_node(4512);
	sll_insert (&root, temp);
	sll_traverse (root);
	sll *node_to_remove = sll_find(root, 451);
	sll_remove (&root, node_to_remove);
	sll_traverse (root);
	node_to_remove = sll_find(root, 4512);
	sll_remove (&root, node_to_remove);
	sll_traverse (root);
}
