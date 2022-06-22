#pragma once
#include <map>
#include <list>
#include <regex>
#include <fstream>
#include "virtual_memory.h"

 

class parser {
	struct referens_count {
		int count = 0;
		bool* ptr = nullptr;
	};
	virtual_memory *memory=nullptr;
	std::string ection = "";
	std::map<std::string, referens_count*>elements;
	std::fstream file;
	std::vector<std::regex> regulars;
	parser(virtual_memory* memory) {
		regulars.push_back(std::regex("([\\w]+)(=alloc)([\(])([\\d]+)([\)])(;)"));
		regulars.push_back(std::regex("(dealloc)([\(])([\\w]+)([\)])(;)"));
		regulars.push_back(std::regex("([\\w]+)(=)([\\w]+)(;)"));
		this->set_virtual_memory(memory);
	}
public:
	parser(const std::string& file_name, virtual_memory* memory):parser(memory){
		file.open(file_name);
	}
	~parser() {
		file.close();
	}
	void set_virtual_memory(virtual_memory* memory) {
		this->memory = memory;
	}
	void find();
	bool do_dealloc(std::string name);  
	bool do_alloc(std::string name, std::string number);
	bool do_opiration(std::string name1, std::string name2); 
	bool reduce_links(const std::string&name);
	void show_information(){
		int all_memory = 0;
		int max = 0;
		int j = 0;
		std::cout << "Занятые блоки:\n";
		for (auto i = elements.begin(); i != elements.end(); i++) {
			if (i->second->count > 0) {
				i->second->count = -(i->second->count);
					std::cout << ++j << ")" << memory->get_size(i->second->ptr) << "\n";
					all_memory += memory->get_size(i->second->ptr);
					if (memory->get_size(i->second->ptr) > max) {
						max = memory->get_size(i->second->ptr);
					} 
				
			}
		}
		std::cout << "Вся занятая память:" << all_memory << "\n";
		std::cout << "Кол-во занятых блоков:" << j << "\n";
		std::cout << "Самый длинный блок занятоой памяти:" << max << "\n";
		memory->show_information();
	}
};
