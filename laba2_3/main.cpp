#include <iostream>
#include "parser.h"
//#include <map>


int main()
{
    virtual_memory* memory = new virtual_memory;
   parser pars("C:\\lib\\laba3.txt",memory);
   pars.find();
   delete memory;
    std::cout << "Hello world!" << "\n";

}
