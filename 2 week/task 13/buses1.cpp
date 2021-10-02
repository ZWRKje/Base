#include <iostream>
#include <vector>
#include <map>

void newBus(std::map<std::string, std::vector<std::string>>& bus, std::string& name, const int& param1, std::vector<std::string>& stops, std::vector<std::string>& mem ) {
	mem.push_back(name);
		for (int i = 0; i < param1; ++i) {
		bus[name].push_back(stops[i]);
	}
}
void busesForStop(std::map<std::string, std::vector<std::string>>& bus, const std::string& param1, std::vector<std::string>& mem) {

	bool flag = false;
	for (int i = 0; i < mem.size(); ++i) {
		for (auto s : bus[mem[i]]) {
			if (s == param1) {
				flag = true;
				std::cout << mem[i] << " ";
			}
		}
	}

	if (!flag) {
		std::cout << "No stop" << std::endl;
	}
	else {
		std::cout << std::endl;
	}

}

void stopForBus(std::map<std::string, std::vector<std::string>>& bus, const std::string& param1, std::vector<std::string>& mem)
{
	if (bus.count(param1) == 0) {
		std::cout << "No bus" << std::endl;
	}
	else {
		bool flag = false;
		

		for (auto s : bus[param1]) {
			std::cout << "Stop " << s << ": ";
			for (int i = 0; i < mem.size(); ++i) {
				if (mem[i] != param1) {
					for (auto a : bus[mem[i]]) {
						if (a == s) {
							flag = true;
							std::cout << mem[i] << " ";
						}
					}
				}
				

			}

			if (!flag)
				std::cout << "no interchange" << std::endl;
			else
				std::cout << std::endl;
			flag = false;
		}


	}
}

void allBuses(std::map<std::string, std::vector<std::string>>& bus) {
	if (bus.size() == 0) {
		std::cout << "No buses" << std::endl;;
	}
	else {
		for (auto s : bus) {
			std::cout << "Bus " << s.first << ": ";
			for (auto i : s.second) {
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
	}
}

void action(std::map<std::string, std::vector<std::string>>& bus) {
	static std::vector<std::string> mem;
	std::string comand;
	std::string param1;
	std::cin >> comand;

	if (comand == "NEW_BUS") {
		int param2;
		std::string name;
		std::vector<std::string> stops;
		std::cin >> name;
		std::cin >> param2;
		for (int i = 0; i < param2; ++i) {
			std::cin >> param1;
			stops.push_back(param1);
		}
		newBus(bus, name, param2, stops, mem );
	}
	else if (comand == "BUSES_FOR_STOP") {
		std::cin >> param1;
		busesForStop(bus, param1, mem);
	}
	else if (comand == "STOPS_FOR_BUS") {
		std::cin >> param1;
		stopForBus(bus, param1, mem);
	}
	else if (comand == "ALL_BUSES") {
		allBuses(bus);
	}
}

int main() {
	std::map<std::string, std::vector<std::string>> bus;
	int nCom = 0;
	std::cin >> nCom;
	for (int i = 0; i < nCom; ++i) {
		action(bus);
	}
	return 0;
}