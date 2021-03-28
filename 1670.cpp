struct ll_node_st {
	int val;
	ll_node *prev;
	ll_node *next;
} dll_node;

class ll {
private:
	dll_node *head;
	dll_node *mid;
	dll_node *back;
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

	int pop_mid()
	{
		int val = -1;

		if (size == 0)
			return -1;
		val = mid->val;
		dll_node *temp = mid;
		if (size == 1 || size == 2) {
			head = head->next;
			head->priv = NULL;
			mid = head;
			back = head;
		}
		else if (size % 2 == 0) {
			mid = mid->next;
			mid->priv = temp->priv;
			(mid->priv)->next = mid;
		}
		else {
			mid = mid->priv;
			mid->next = mid->next;
			(mid->next)->priv = mid;
		}
		delete temp;
		size--;
		return val;
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
			}
			else if (size % 2 == 0) {
				mid = new_node;
				mid->prev = temp;
				mid->next = temp->next;
				temp->next = new_node;
			}
			else {
				mid = new_node;
				mid->next = temp;
				mid->priv = temp->priv;
				temp->priv = new_node;
			}
		}
		size++;
	}

	int pop_back()
	{
		
		int val = -1;
		dll_node *temp = back;
		if (size == 0) {
			return val;
		}
		val = back->val;
		else if (size == 1) {
			head = NULL;
			back = NULL;
			mid = NULL;
		}
		else if (size % 2 == 0) {
			back = back->priv;
			back->next = NULL;	
		}
		else {
			back = back->priv;
			back->next = NULL;
			mid = mid->next;
		}
		size--;
	}

	void put_back(int val)
	{
		dll_node *new_node = create_node(val);
		if (size == 0) {
			head = new_node;
			mid = new_node;
			back = new_node;
		}
		else if (size % 2 == 0) {
			mid = mid->next;
			
		}
	}

	int pop_front()
	{
	}

	void put_back()
	{
	}	
}
