#include "parser.h"
void parser::find() {
	int i = 1;

	while (getline(file, ection)) {
		std::cmatch result;
		if (std::regex_match(ection.c_str(), result, regulars[0])) {
			if (!do_alloc(result[1], result[4])) {
				std::cout << "somfing is bed in alloc\n";
			}
		}
		else if (std::regex_match(ection.c_str(), result, regulars[1])) {
			if (!do_dealloc(result[3])) {
				std::cout << "somfing is bed in dealoc\n";
			}
		}
		else if (std::regex_match(ection.c_str(), result, regulars[2])) {
			if (!do_opiration(result[1], result[3])) {
				std::cout << "somfing is bed in opiration\n";
			}
		}
		else {
			std::cout << "Not_correct_instruction: " << i << "\n";
			return;
		}
		i++;

	}
	return;
}
bool parser::reduce_links(const std::string&name) {
	if (elements.find(name) != elements.end()) {
		elements[name]->count--;
		if (elements[name]->count == 0) {
			bool flag = memory->dealloc(elements[name]->ptr);
			delete elements[name];
			return flag;
		}
		return 1;

	}
	return 1;
}
bool parser::do_dealloc(std::string name) {
	bool flag=reduce_links(name);
	elements.erase(name);
	return flag;

}

bool parser::do_alloc(std::string name, std::string number) {
	 
	bool flag = reduce_links(name);
	elements[name] = new referens_count;
	elements[name]->ptr =(bool*) memory->alloc(atoi(number.c_str()));
	int* t = (int*)elements[name]->ptr + 1;
	elements[name]->count++;
	if (elements[name]->ptr == nullptr) {
		return 0;
	}
	return flag;
}

bool parser::do_opiration(std::string name1, std::string name2) {
	bool flag=reduce_links(name1);
	if (elements.find(name2) != elements.end()) {
		elements[name1] = elements[name2];
		elements[name1]->count++;
		return flag;
	}
	return 0;
}