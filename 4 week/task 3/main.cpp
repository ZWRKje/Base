#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main() {
	std::ifstream file("input.txt");
	std::string str = {};
	double num = 0.0;
	if (file.is_open()) {
		std::cout << std::fixed << std::setprecision(3);
		while (std::getline(file, str)) {
			num = std::stod(str);
			std::cout << num << "\n";
		}

	}
	return 0;
}