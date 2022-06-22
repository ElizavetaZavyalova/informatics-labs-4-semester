#include <iostream>
 
typedef unsigned int uint;
typedef long long int lint;
class virtual_memory {
 public:
	virtual bool* alloc(const uint& size)=0;
	virtual bool dealloc(void* ptr)=0;
	virtual void show_information()=0;
	virtual int get_node_size(void* element)=0;
	virtual int get_size(void* element) = 0;
};

 
class virtual_memory_1:public virtual_memory {
	 
	struct node {
		int size = 0;
		node* next = nullptr;
		node* prev = nullptr;
	};
	void set_all(node*& element) {
		element->size = *((int*)element) + sizeof(int) - sizeof(node);
		element->next = nullptr;
		element->prev = nullptr;
	}
	 
	bool* ptr = nullptr;
	int size_of_ptr = 0;
	node* head = nullptr;
	int* alloc_node(const uint& size, node* now); 
	bool merge_elem(node* prev, int* information, node* next);
	bool merge(node* first, node* second);
public:
	int get_size(void* element) {
		int* nod = ((int*)(element))-1;
		return (*nod)+sizeof(int);
	}
	int get_node_size(void* element) override {
		node* nod = (node*)element;
		return ((node*)element)->size + sizeof(node);
	}
	virtual_memory_1(const uint size = 1000) {
		ptr = (bool*)malloc(size+sizeof(node));
		std::cout <<"Размер кучи:"<< size + sizeof(node)<<"\n";
		size_of_ptr = size+sizeof(node);
		head = (node*)ptr;
		head->next = nullptr;
		head->prev = nullptr;
		head->size = size;
	}
	~virtual_memory_1() {
		free(ptr);
	}
	bool* alloc(const uint& size) override;
	bool dealloc(void* ptr) override;   
	void show_information() override {
		node* now = head;
		int all_memory = 0;
		int max = 0;
		int i = 0;
		std::cout << "Своюодные блоки:\n";
		while (now != nullptr) {
			std::cout << ++i << ")" << get_node_size(now) << "\n";
			all_memory += get_node_size(now);
			if (get_node_size(now) > max) {
				max = get_node_size(now);
			} now = now->next;
		}
		std::cout << "Вся свободная память:" << all_memory << "\n";
		std::cout << "Кол-во свободных блоков:" << i << "\n";
		std::cout << "Самый длинный блок свободной памяти:" << max << "\n";
	}
};

class virtual_memory_2 :public virtual_memory {
	struct node {
		node* next = nullptr;
		node* prev = nullptr;
	};
	void set_ptr(node*&element) {
		element->next = nullptr;
		element->prev = nullptr;
	}
	void set_size(node*& element, const  lint& size) {
		lint* size_1 = (lint*)element - 1;
		(*size_1) = size;
		lint* size_2 = (lint*)(((bool*)(size_1 + 1)) + size);
		(*size_2) = size;
	}
	 
	lint get_size(node*& element) {
		return *((lint*)element - 1);
	}
	bool* ptr = nullptr;
	int size_of_ptr = 0;
	node* head = nullptr;
	void* alloc_node(lint size, node* now);
public:
	int get_size(void* element)override {
		lint* b = ((lint*)element - 1);
		return abs(*((lint*)element - 1)) + 2 * sizeof(lint);
	}
	int get_node_size(void* element) override {
		lint* b = ((lint*)element+1);
		return abs(*((lint*)element - 1)) + 2 * sizeof(lint);
	}
	virtual_memory_2(const uint size = 1000) {
		ptr = (bool*)malloc(size + 4*sizeof(lint));
		std::cout << "Размер кучи:" << size + 4*sizeof(lint) << "\n";
		lint* p=((lint*)ptr);
		*p = 0;
		*((lint*)((bool*)((lint*)ptr + 1) + size + 2 * sizeof(lint))) = 0;
		size_of_ptr = size + 2*sizeof(lint);
		head =(node*)((lint*)ptr+2);
		set_ptr(head);
		set_size(head,size);
	}
	~virtual_memory_2() {
		free(ptr);
	}
	bool* alloc(const uint& size) override; 
	bool dealloc(void* ptr) override;
	void show_information() override {
		node* now = head;
		int all_memory = 0;
		int max = 0;
		int i = 0;
		std::cout << "Своюодные блоки:\n";
		while (now != nullptr) {
			std::cout << ++i << ")" << get_node_size(now) << "\n";
			all_memory += get_node_size(now);
			if (get_node_size(now) > max) {
				max = get_node_size(now) ;
			} now = now->next;
		}
		std::cout << "Вся свободная память:" << all_memory <<" +дискрипторы кучи:"<<2*sizeof(lint)<< "\n";
		std::cout << "Кол-во свободных блоков:" << i << "\n";
		std::cout << "Самый длинный блок свободной памяти:" << max << "\n";
	}
};


 
	 