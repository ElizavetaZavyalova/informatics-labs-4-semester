#include "virtual_memory.h"
 

bool* virtual_memory_2::alloc(const uint& size) {
	lint new_size = (size < sizeof(node)) ? (sizeof(node)) : (size);
	node* now = head;
	if (now != nullptr) {
		do {
			//int h = now->get_size();
			if (get_size(now) >= new_size) {
				return (bool*)alloc_node(new_size, now);
			}
			now = now->next;

		} while (now != nullptr);
	}
	return nullptr;
}

void* virtual_memory_2::alloc_node(lint new_size, node* now) {
	if (get_size(now) < new_size + 2 * sizeof(lint)) {
		if (now->prev != nullptr) {
			now->prev->next = now->next;
		}
		if (now->next != nullptr) {
			now->next->prev = now->prev;
		}
		if (head == now) {
			head = now->next;
		}
		set_size(now,(-1)*get_size(now));
		return now;
	}
	lint* ptr_m = (lint*)((bool*)now + get_size(now) - new_size - sizeof(lint));
	(*ptr_m) = (-1)*new_size;
	lint* ptr_l = ((lint*)((bool*)now + get_size(now)));
	*ptr_l = -new_size;
	set_size(now, get_size(now) - new_size - 2*sizeof(lint));
	 
	return (ptr_m+1);
}
bool virtual_memory_2::dealloc(void* ptr) {
	lint* size_l = ((lint*)ptr) - 1;
	lint* size_r = (lint*)(((bool*)(size_l + 1)) + (*size_l));
	if ((*(size_l - 1)) < 0) {
		node* nod = (node*)ptr;
		set_ptr(nod);
		set_size(nod,(-1)*(*size_l));
		nod->next = head;
		head = nod;
		if ((*(size_r + 1)) < 0)
			return 0;		
		
			node* nod_r = (node*)(size_r + 2);
			if (nod_r->prev != nullptr) {
				nod_r->prev->next = nod_r->next;
			}
			if (nod_r->next != nullptr) {
				nod_r->next->prev = nod_r->prev;
			}
			set_size(nod, get_size(nod) + 2 * sizeof(lint) + *((size_r + 1)));
		
	}
	else if((*(size_l - 1)) > 0) {
		node* nod_l = (node*)((bool*)(size_l - 1) - (*(size_l - 1)));
		set_size(nod_l, (*(size_l - 1)) + (-1)*(*size_l) + 2 * sizeof(lint));
		if ((*(size_r + 1)) > 0) {
			node* nod_r = (node*)(size_r + 2);
			if (nod_r->prev != nullptr) {
				nod_r->prev->next = nod_r->next;
			}
			if (nod_r->next != nullptr) {
				nod_r->next->prev = nod_r->prev;
			}
			set_size(nod_l, get_size(nod_l) + 2 * sizeof(lint) + *((size_r + 1)));
		}
	}
	return 0;
}