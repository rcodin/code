#include <iostream>
#include <stdlib>

class Stack {
	private:
		void **arr;
		size_t size;
		size_t capacity;
	public:
		Stack (size_t size) {
			this->size = 0;
			this->capacity = size;
			this->arr = (void **)malloc(size * sizeof(void *));
		}
		void push(void *elem) {
			if (this->capacity == this->size)
				return;
			arr[this->size] = elem;
			this->size++;
		}
		void pop() {
			this->size--;
		}
		void top() {
			return arr[this->size - 1];
		}
		void get_size() {
			return this->size;
		}
		void empty() {
			if (this->size == 0)
				return true;
			return false;
		}
}
