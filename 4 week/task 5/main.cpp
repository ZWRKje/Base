#include <iostream>
#include <string>
#include <vector>
#include <map>

struct student {
	std::string name;
	std::string soname;
	int day;
	int month;
	int year;
};

void action(const std::string& todo, std::map<int, std::vector<student>>& book) {

	int num = 0;
	if (todo == "name") {
		std::cin >> num;
		if (book.count(num)) {
			for (auto i : book[num]) {
				std::cout << i.name << " " << i.soname << "\n";
			}
		}
		else {
			std::cout << "bad request" << "\n";
		}
	}
	else if (todo == "date") {
		int num;
		std::cin >> num;
		if (book.count(num)) {
			for (auto i : book[num]) {
				std::cout << i.day << "." << i.month << "." << i.year << "\n";
			}
		}
		else {
			std::cout << "bad request" << "\n";
		}
	}
	else {
		std::cin >> num;
		std::cout << "bad request" << "\n";
	}
}
int main() {
	size_t n;
	std::cin >> n;
	std::map<int, std::vector<student>> book;
	for (size_t i = 0; i < n; ++i) {
		std::string name = {};
		std::string soname = {};
		int day = 0;
		int month = 0;
		int year = 0;
		std::cin >> name >> soname >> day >> month >> year;
		book[i + 1].push_back({ name, soname, day, month, year });
	}
	std::cin >> n;
	std::string todo = {};
	for (size_t i = 0; i < n; ++i) {
		std::cin >> todo;
		action(todo, book);
	}
	return 0;
}