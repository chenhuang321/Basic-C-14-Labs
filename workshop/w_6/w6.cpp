
// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include "Grades.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	w6::Grades grades(argv[1]);
	// define the lambda expression for letter
	std::list<std::string> letter;
	try {
	    grades.displayGrades(std::cout, letter);
	}
	catch(const char* e) {}

	std::cout << "\nPress any key to continue ... ";
	std::cin.get();
	return 0;
}