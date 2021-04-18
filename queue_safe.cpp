#include <iostream>
#include <stdlib>

using namespace std;

class Queue {
	private:
		void **arr;
		size_t size;
		int front_index;
		int end_index;
		mutex mtx;
	public:
		Stack (size_t size) {
			this->size = 0;
			this->capacity = size;
			this->arr = (void **)malloc(size * sizeof(void *));
		}

		void push(void *elem) {
			if (this->capacity == this->size)
				return;
			mtx.lock();
			this->end_index = (++this->end_index) % this->capacity;
			arr[this->end_index] = elem;
			this->size++;
			mtx.unlock();
		}

		void *pop() {
			if (this->size == 0)
				return NULL;
			void *elem = arr[this->front_index];
			mtx.lock();
			this->front_index = (++this->front_index) % this->capacity;
			this->size--;
			mtx.unlock();
			return elem;
		}

		void front() {
			return arr[front_index];
		}

		void end() {
			return arr[end_index];
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
