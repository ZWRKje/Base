#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream file("input.txt");
	std::ofstream out("output.txt");
	std::string str = {};
	if (file.is_open()) {
		while (std::getline(file, str)) {
			//std::cout << str << "\n";
			out << str << "\n";
		}

	}
	return 0;
}