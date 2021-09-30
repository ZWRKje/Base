#include <iostream>
#include <vector>

void add(std::vector<std::vector<std::string>>& eventMounth, const int& param, const std::string& event) {
	eventMounth[param].push_back(event);
}

void dump(std::vector<std::vector<std::string>>& eventMounth, const int& param) {
	std::cout << eventMounth[param].size() << " ";
	for (auto i : eventMounth[param])
		std::cout << i << " ";
	std::cout << std::endl;
}

void next(std::vector<std::vector<std::string>>& eventMounth, std::vector<size_t>& month, int& currentMounth) {
	currentMounth++;
	if (currentMounth >= 12) {
		currentMounth = 0;
	}
	std::vector<std::vector<std::string>> tempMounth;
	size_t n = eventMounth.size();
	if (n < month[currentMounth]) {
		eventMounth.resize(month[currentMounth]);
	} else if (n > month[currentMounth]) {
		for (size_t i = month[currentMounth]; i < n; ++i)
			tempMounth.push_back(eventMounth[i]);
		eventMounth.resize(month[currentMounth]);
		for (size_t i = 0; i < tempMounth.size(); ++i) {
			for (auto x : tempMounth[i])
				eventMounth[month[currentMounth] - 1].push_back(x);
		}
	}
}

void action(const std::string& str, std::vector<std::vector<std::string>>& eventMounth, std::vector<size_t> mounth) {
	static int currentMonth = 0;
	if (str == "ADD") {
		int param = 0;
		std::string event;
		std::cin >> param;
		std::cin >> event;
		add(eventMounth, param - 1, event);
	} else if (str == "DUMP") {
		int param = 0;
		std::cin >> param;
		dump(eventMounth, param - 1);
	} else if (str == "NEXT") {
		next(eventMounth, mounth, currentMonth);
	}
}


int main() {
	std::vector<size_t> mounth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::vector<std::vector<std::string>> eventMounth(mounth[0]);

	int nCom = 0;
	std::string str;
	std::cin >> nCom;
	for (int i = 0; i < nCom; ++i) {
		std::cin >> str;
		action(str, eventMounth, mounth);
	}

	return 0;
}