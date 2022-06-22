#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <map>
#include "virtual_memory.h"
#include <regex>
#include <fstream>
#include <list>


/*struct block {
    block* parent = nullptr;
    std::vector<block*> chields;
    std::map<std::string, void*> elements;
    void ShowVar() {
        for (auto i = elements.begin(); i != elements.end(); i++) {
            std::cout << i->first << ":" << "\n";
        }
    }

};*/


class parser{
    std::list<std::map<std::string, void*>*> not_show_elements;
    struct block {
        block* parent = nullptr;
        std::map<std::string, void*>* elements=nullptr;
        void ShowVar(virtual_memory* memory) {
            if (elements == nullptr) {
                return;
            }
            for (auto i = elements->begin(); i != elements->end(); i++) {
                //int d = 0;
                std::cout << i->first << ":" << memory->give_size(i->second)<<  "\n";
            }
        }

    };
    void get_c(char&c){
        do {
            c = file.get();

        } while (c == ' ' || c == '\n');
    }
    virtual_memory* memory = nullptr;
    std::ifstream file;
    std::vector<std::regex> regulars;
    std::string ection = "";
    block* now = nullptr;
    parser(virtual_memory* memory) ;
    void parse();
    bool do_new(std::string name, std::string size);
    bool delite_not_show_elements();
    bool try_new(const int size, block* serf, std::string& name);
    bool do_ShowVar();
    void clear_elements();
public:
    parser(const std::string& file_name, virtual_memory* memory) :parser( memory) {
        file.open(file_name.c_str());
        if (!file.is_open()) {
            std::cout << "file not found\n";
        }
    }
    ~parser() {
        file.close();
        clear_elements();
    }
    void find() {
        char c = ' ';
        int bracket = 0;
        while (!file.eof()) {
            get_c(c);
            if (c == '{') {
                bracket++;
                block* next = new block;
                next->parent = now;
                next->elements = new std::map<std::string, void*>;
                now = next;
            }
            else if (c == '}') {
                bracket--;
                if (bracket < 0) {
                    clear_elements();
                    //exeption;
                }
                not_show_elements.push_back(now->elements);
                block* prev = now;
                now = now->parent;
                delete prev;
            }
            else if (c == ';') {
                this->ection += c;
                parse();
                this->ection = "";
            }
            else {
                ection += c;
            }
        }
        if (bracket != 0) {
            clear_elements();
            //exeption
        }
    }


};

#endif // PARSER_H
