#include "virtual_memory.h"

int* virtual_memory_1::alloc_node(const uint& size, node* now) {
	int* information = nullptr;
	if (now->size <= size + sizeof(node) + sizeof(int)) {
		if (now->prev != nullptr) {
			now->prev->next = now->next;
		}
		else {
			head = now->next;
		}
		if (now->next != nullptr) {
			now->next->prev = now->prev;
		}
		information = (int*)now;
		(*information) = get_node_size(now) - sizeof(int);
		return (information);
	}
	else {
		information = (int*)((bool*)(now + 1) + (now->size) - size - sizeof(int));
		(*information) = size;
		now->size -= (size + sizeof(int));
		return (information);

	}
}
	 
bool* virtual_memory_1::alloc(const uint& size) {
	node* now = head;
	if (now != nullptr) {
		do {
			if (now->size >= size) {
				int* b= (int*)alloc_node(size, now);
				return (bool*)(b+1);
			}
			now = now->next;

		} while (now != nullptr);
	}
	return nullptr;
}

bool virtual_memory_1::dealloc(void* ptr) {
	int* information = ((int*)ptr) - 1;
	node* now = head;
	if (now != nullptr) {
		node* last = now;
		do {
			last = now;
			if ((bool*)now > (bool*)information) {
				return merge_elem(now->prev, information, now);
			}
			now = now->next;
		} while (now != nullptr);
		return merge_elem(last, information, last->next);
	}
	return merge_elem(nullptr, information, nullptr);
		 

}

bool virtual_memory_1::merge(node* first, node* second) {
	if (first == second) {
		return 0;
	}
	if (second != nullptr) {
		if (first + get_node_size(first) == second) {
			first->size += get_node_size(second);
			first->next = second->next;
			first->prev = second->prev;
			return 1;
		}
		else {
			first->next = second;
			first->prev = second->prev;
			second->prev = first;
		}
	}
	return 0;
		 

}
bool virtual_memory_1::merge_elem(node* prev, int* information, node* next) {
	if (information == nullptr)
		return 0;
	node* now = ((node*)information); set_all(now);
	if (prev == nullptr && next == nullptr) {
		head = now;
		return 1;
	}
	else if (prev == nullptr) {
		merge(now, next);
		head = now;
		return 1;
	}
	else if (next == nullptr) {
		prev->size += get_node_size(now);
		return 1;
	}
	now->next = next;
	now->prev = prev;
	merge(now, next);
	merge(prev, now);
	return 1;
		 

}