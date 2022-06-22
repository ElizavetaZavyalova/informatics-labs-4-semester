#include "virtual_memory.h"

int  virtual_memory::give_size(int size) {
    int num = -1;
    if (size <= MIN_SIZE) {
        return MIN_KVAL;
    }
    if ((size & (size - 1)) != 0) {
        num++;
    }
    while (size != 0) {
        size = size >> 1;
        num++;
    }
    return num;
}

virtual_memory::node* virtual_memory::pop_node(node*& root) {
    node* resault = root;
    if (root->next == root) {
        root = nullptr;;
    }
    else {
        root = root->next;
        root->prev = root->prev->prev;
        root->prev->next = root->prev->next->next;
    }
    return resault;
}
virtual_memory::node* virtual_memory::pop_node(node*& root, node* element) {
    if (root == element) {
        root = nullptr;
        return element;
    }
    root = element;
    return pop_node(root);
}
void virtual_memory::push_node(node*& root, node*element) {
    if (root == nullptr) {
        root = element;
        element->next = element;
        element->prev = root;
     }
    element->next = root->next;
    element->prev = root;
    root->next->prev = element;
    root->next = element;

}


int virtual_memory::give_size(void* element) {

    return 1<<((((information*)element) - 1)->kval);
}

virtual_memory::virtual_memory(int size) {
    this->kval = give_size(size);
    this->size = 1 << kval;
    ptr = (bool*)malloc(sizeof(bool) *(this->size));
    ((information*)ptr)->kval = kval;
    ((information*)ptr)->tag = 1;
    ((node*)(((information*)ptr) + 1))->next = ((node*)(((information*)ptr) + 1));
    ((node*)(((information*)ptr) + 1))->prev = ((node*)(((information*)ptr) + 1));
    for (int i = MIN_KVAL; i < kval; i++) {
        list.push_back(nullptr);
    }
    list.push_back((node*)(((information*)ptr) + 1));
}
void* virtual_memory::do_new(int size) {
    int kval = give_size(size+MIN_SIZE);
    if (list[kval- MIN_KVAL] != nullptr) {
        node* root= pop_node(list[kval- MIN_KVAL]);
        (((information*)root) - 1)->tag = 0;
    }
    int find = kval;
    while (find <= this->kval) {
        if (list[find - MIN_KVAL] != nullptr) {
            node* root = pop_node(list[find - MIN_KVAL]);
            while (find != kval) {
                find--;
                information* new_node = (information*)(((bool*)(((information*)root) - 1)) + (1 << find));
                new_node->kval = find;
                new_node->tag = 1;
                push_node(list[find - MIN_KVAL], (node*)(new_node + 1));
            }
            (((information*)root) - 1)->tag = 0;
            (((information*)root) - 1)->kval = find;
            return root;
        }
        find++;
    }
    return nullptr;
}
void virtual_memory::do_delete(void*ptr) {
    bool* ptr_delite = (bool*)((information*)ptr-1);
    luint length = reinterpret_cast<luint>((bool*)(((information*)ptr)-1))- reinterpret_cast<luint>(this->ptr);
    int kval=(((information*)ptr) - 1)->kval;
    if (kval == this->kval) {
        (((information*)ptr) - 1)->tag = 1;
        push_node(list[((information*)ptr_delite)->kval - MIN_KVAL], (node*)(ptr));
        return;
    }
    if ((length & (1 << kval)) == 0) {//Если первый элемент
        node* ptr_second = (node*)(((information*)(ptr_delite + (1 << kval))) + 1);
        information* b = (((information*)(ptr_second)) - 1);
        bool t = b->tag;
        if (t) {//если второй свободен
             pop_node(list[kval - MIN_KVAL], ptr_second);
            (((information*)ptr) - 1)->kval++;
            do_delete(ptr);
        }
        else {//если второй занят
            push_node(list[((information*)ptr_delite)->kval - MIN_KVAL],(node*)(((information*)(ptr_delite))+1));
            ((information*)ptr_delite)->tag = 1;
            return;
        }
    }
    else {//Если второй Элемент
        node* ptr_first = (node*)(((information*)(ptr_delite - (1 << kval))) + 1);
        if ((((information*)(ptr_first)) - 1)->tag) {//если первый свободен
            pop_node(list[kval - MIN_KVAL], ptr_first);
            (((information*)ptr_first)-1)->kval++;
            (((information*)ptr_first) - 1)->tag = 0;
            do_delete(ptr_first);
        }
        else {//если первый занят
            push_node(list[((information*)ptr_delite)->kval - MIN_KVAL], (node*)(((information*)(ptr_delite)) + 1));
            ((information*)ptr_delite)->tag = 1;
            return;
        }
    }

}
