#include <iostream>
#include "parser.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    virtual_memory* my_laba1 = new virtual_memory_1;
    virtual_memory* my_laba2 = new virtual_memory_2;
    // parser parser_1("C:\\lib\\laba.txt",my_laba1);
    // parser_1.find();
    parser parser_2("C:\\lib\\laba.txt", my_laba2);
    parser_2.find();
    parser_2.show_information();
    std::cout << "Hello World lisa!\n";
}
