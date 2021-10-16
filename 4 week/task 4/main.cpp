#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main() {
	std::ifstream file("input.txt");
	size_t column = 0;
	size_t line = 0;
	file >> line;
	file >> column;
	file.ignore(1);
	std::string com;

	for (size_t i = line; i > 0; --i) {
		for (size_t j = column; j > 1; --j) {
			std::getline(file, com, ',');
			std::cout << std::setw(10) << com << " ";
		}
			std::getline(file, com);
		if (!file.eof()) {
			std::cout << std::setw(10) << com << "\n";
		} else {
			std::cout << std::setw(10) << com;
		}
	}



	return 0;
}