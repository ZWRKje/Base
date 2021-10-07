#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct people {
	std::string name;
	std::string lastName;
};

class Person {
public:
	void ChangeFirstName(int year, const std::string& first_name) {
		if (info.count(year) == 0) info[year].lastName = "";
		info[year].name = first_name;
	}
	void ChangeLastName(int year, const std::string& last_name) {
		if (info.count(year) == 0) info[year].name = "";
		info[year].lastName = last_name;
	}
	std::string GetFullName(int year) {
		if (info.size() == 0) {
			return "Incognito";
		}
		else {
			for (auto& s : info) {
				if (s.first > year) return "Incognito";
				break;
			}
		}
		std::string name = "";
		std::string secondName = "";
		for (auto& s : info) {
			if (s.first <= year && s.second.name != "") name = s.second.name;
			if (s.first <= year && s.second.lastName != "") secondName = s.second.lastName;
		}
		if (name == "")
			return secondName + " with unknown first name";
		else if (secondName == "")
			return name + " with unknown last name";
		else
			return name + " " + secondName;
	}
	std::string history(std::vector<std::string>& history) {

		std::string rezult = "(";
		if (history.size() == 2) {
			rezult += history[0];
		}
		else {
			history.pop_back();
			for (int i = history.size() - 1; i > 0; --i) {
				rezult += history[i] + ", ";
			}
			rezult += history[history.size() - 2];
		}
		return rezult + ")";
	}
	std::string GetFullNameWithHistory(int year) {

		if (info.size() == 0) {
			return "Incognito";
		}
		else {
			for (auto& s : info) {
				if (s.first > year) return "Incognito";
				break;
			}
		}
		std::vector<std::string> historyName;
		std::vector<std::string> historyLastName;
		std::string name = "";
		std::string secondName = "";
		for (auto& s : info) {
			if (s.first <= year && s.second.name != "") {
				if (name != s.second.name) {
					historyName.push_back(s.second.name);
				}
				name = s.second.name;

			}
			if (s.first <= year && s.second.lastName != "") {
				if (secondName != s.second.lastName) {
					historyLastName.push_back(s.second.lastName);
				}
				secondName = s.second.lastName;

			}
		}
		if (name == "") {
			if (historyLastName.size() == 1) {
				return secondName + " with unknown first name";
			}
			else {
				return secondName + " " + history(historyLastName) + " with unknown first name";
			}
		}
		else if (secondName == "") {
			if (historyName.size() == 1) {
				return name + " with unknown last name";
			}
			else {
				return name + " " + history(historyName) + " with unknown last name";
			}
		}
		else {
			if (historyName.size() == 1 && historyLastName.size() == 1) {
				return name + " " + secondName;
			}
			else if (historyName.size() != 1 && historyLastName.size() == 1) {
				return name + " " + history(historyName) + " " + secondName;
			}
			else if (historyName.size() == 1 && historyLastName.size() != 1) {
				return name + " " + secondName + " " + history(historyLastName);
			}
			else {
				return name + " " + history(historyName) + " " + secondName + " " + history(historyLastName);
			}
		}
	}
private:
	std::map<int, people> info;

};


int main() {
   Person person;

   person.ChangeFirstName(1965, "Polina");
   person.ChangeLastName(1967, "Sergeeva");
   for (int year : {1900, 1965, 1990}) {
       std::cout << person.GetFullNameWithHistory(year) << std::endl;
   }

   person.ChangeFirstName(1970, "Appolinaria");
   for (int year : {1969, 1970}) {
       std::cout << person.GetFullNameWithHistory(year) << std::endl;
   }

   person.ChangeLastName(1968, "Volkova");
   for (int year : {1969, 1970}) {
       std::cout << person.GetFullNameWithHistory(year) << std::endl;
   }

   person.ChangeFirstName(1990, "Polina");
   person.ChangeLastName(1990, "Volkova-Sergeeva");
   std::cout << person.GetFullNameWithHistory(1990) << std::endl;

   person.ChangeFirstName(1966, "Pauline");
   std::cout << person.GetFullNameWithHistory(1966) << std::endl;

   person.ChangeLastName(1960, "Sergeeva");
   for (int year : {1960, 1967}) {
       std::cout << person.GetFullNameWithHistory(year) << std::endl;
   }

   person.ChangeLastName(1961, "Ivanova");
   std::cout << person.GetFullNameWithHistory(1967) << std::endl;

   return 0;
}