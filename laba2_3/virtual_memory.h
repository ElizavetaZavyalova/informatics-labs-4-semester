#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H
#include <iostream>
#include <vector>
#define MIN_KVAL 5
#define MIN_SIZE 32
#define luint unsigned long long int
class virtual_memory
{
    struct information {
        int kval= MIN_KVAL;
        bool tag = 1;
    };
    struct node {
        node* next = this;
        node* prev = this;

    };


    bool* ptr = nullptr;
    int size = 0;
    int kval = 0;
    std::vector<node*> list;
    int  give_size(int size);
    node* pop_node(node*& root);
    node* pop_node(node*& root, node* element);
    void push_node(node*& root, node*element);

public :
    int give_size(void* element);
    virtual_memory(int size=2000);
    void* do_new(int size);
    void do_delete(void*ptr);
};
#endif // VIRTUAL_MEMORY_H
