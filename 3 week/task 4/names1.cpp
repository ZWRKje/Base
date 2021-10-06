#include <iostream>
#include <vector>
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
private:
    std::map<int, people> info;
};


int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }

    return 0;
}