struct ll_node_st {
	int val;
	ll_node *prev;
	ll_node *next;
} dll_node;

class ll {
private:
	dll_node *head;
	dll_node *mid;
	int size;
public:
	ll() {
		size = 0;
		head = NULL;
		mid = NULL;
	}

	dll_node *create_node(int val)
	{
		dll_node *node = new node;
		node->val = val;
		node->prev = NULL;
		node->next = NULL;
	}

	int get_mid()
	{
		return mid->val;
	}

	void put_mid(int val)
	{
		dll_node *new_node = create_node(val);

		if (head == NULL) {
			head = new_node;
			mid = new_node;
		}
		else {
			dll_node *temp = mid;
			if (size == 1) {
				head = new_node;
				mid = new_node;
				mid->next = temp;
				temp->prev = head;
			}
			if (size % 2 == 0) {
				temp->prev = ;
				mid = new_node;
				
			}
		}
		size++;
	}

	int get_back()
	{
	}

	void put_back()
	{
	}

	int get_front()
	{
	}

	void put_back()
	{
	}	
}
