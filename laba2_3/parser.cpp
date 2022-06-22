#include "parser.h"

parser::parser(virtual_memory* memory) {
    regulars.push_back(std::regex("([\\w]+)(=new)([\(])([\\d]+)([\)])(;)"));
    regulars.push_back(std::regex("(ShowVar;)"));
    now = new block;
    this->memory = memory;
}
void parser::parse() {
    std::cmatch result;
    if (std::regex_match(ection.c_str(), result, regulars[0])) {
        if (!do_new(result[1], result[4])) {
            std::cout << "somfing is bed in alloc\n";
            std::cout << result[0];
        }
    }
    else if (std::regex_match(ection.c_str(), result, regulars[1])) {
        std::cout << "ShowWar:\n";
        if (!do_ShowVar()) {
            std::cout << "somfing is bed in dealoc\n";
        }
    }

    else {
        std::cout << "Not_correct_instruction: " << ection << "\n";
        return;
    }

}
bool parser::do_new(std::string name, std::string size) {
    block* serf = now;
    while (serf != nullptr&&serf->elements!=nullptr) {
        if (serf->elements->find(name) == serf->elements->end()) {
            serf = serf->parent;
        }
        else {
            if (!try_new(atoi(size.c_str()), serf, name)) {
                return 0;

            }
        }
    }
    if (!try_new(atoi(size.c_str()), now, name)) {
        return 0;
    }
    return 1;

}
bool parser::delite_not_show_elements() {
    if (not_show_elements.begin() == not_show_elements.end()) {
        return 0;
    }
    std::map<std::string, void*>* elements = not_show_elements.back();
    if (elements->begin() == elements->end()) {
        return 0;
    }
    memory->do_delete((elements->begin())->second);
    elements->erase(elements->begin());
    if (elements->begin() == elements->end()) {
        not_show_elements.pop_back();
        delete elements;
    }
    return 1;


}
bool parser::try_new(const int size, block* serf, std::string& name) {

    void* ptr = memory->do_new(size);
    while (ptr == nullptr && delite_not_show_elements()) {

        ptr = memory->do_new(size);
    }
    if (ptr == nullptr) {
        return 0;
    }
    if ((serf->elements) == nullptr) {
        serf->elements = new std::map<std::string, void*>;
    }
    (*serf->elements)[name] = ptr;
    return 1;

}
bool parser::do_ShowVar() {
    block* serf = now;
    if (serf == nullptr) {
        return 0;
    }
    while (serf != nullptr) {
        serf->ShowVar(memory);
        serf = serf->parent;
    }
    return 1;

}
void parser::clear_elements() {
    for (auto i = not_show_elements.begin(); i != not_show_elements.end(); i++) {
        delete (*i);
    }
    while (now != nullptr) {
        delete now->elements;
        block* prev = now;
        now = now->parent;
        delete prev;
    }
}
