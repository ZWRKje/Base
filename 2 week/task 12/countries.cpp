#include <iostream>
#include <vector>
#include <map>
void change(std::map<std::string, std::vector<std::string>>& country, const std::string& param1, const std::string& param2) {
    int n = country[param1].size();
    if (n == 0) {

        country[param1].push_back(param2);
        std::cout << "Introduce new country " << param1 << " with capital " << param2 << std::endl;
    }
    else if (country[param1][n - 1] == param2) {
        std::cout << "Country " << param1 << " hasn't changed its capital" << std::endl;
    }
    else if (country[param1][n - 1] != param2) {
        std::cout << "Country " << param1
            << " has changed its capital from " << country[param1][n - 1] << " to " << param2 << std::endl;
        country[param1].push_back(param2);
    }
}
void reName(std::map<std::string, std::vector<std::string>>& country, const std::string& param1, const std::string& param2) {

    if (param1 == param2 || (country.count(param1) == 0) || (country.count(param2) == 1)) {
        std::cout << "Incorrect rename, skip" << std::endl;
    }
    else if (country.count(param1) == 1) {
        int n = country[param1].size();
        std::cout << "Country " << param1 << " with capital " << country[param1][n - 1]
            << " has been renamed to " << param2 <<std::endl;
        std::map<std::string, std::vector<std::string>> temp;
        temp[param1] = country[param1];
        country.erase(param1);
        country[param2] = temp[param1];
    }

}

void about(std::map<std::string, std::vector<std::string>>& country, const std::string& param1) {
    if (country.count(param1) == 0) {
        std::cout << "Country  " << param1 << " doesn't exist" << std::endl;
    }
    else {
        int n = country[param1].size();
        std::cout << "Country  " << param1 << " has capital " << country[param1][n - 1] << std::endl;
    }
}

void dump(std::map<std::string, std::vector<std::string>>& country) {
    if (country.size() == 0) {
        std::cout << "There are no countries in the world"<< std::endl;;
    }
    else {
        for (auto s : country) {
            int n = s.second.size();
            std::cout << s.first << "/" << s.second[n - 1];
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
void action(std::map<std::string, std::vector<std::string>>& country) {
    std::string comand, param1, param2;
    std::cin >> comand;
    if (comand == "CHANGE_CAPITAL") {
        std::cin >> param1;
        std::cin >> param2;
        change(country, param1, param2);
    }
    else if (comand == "RENAME") {
        std::cin >> param1;
        std::cin >> param2;
        reName(country, param1, param2);
    }
    else if (comand == "ABOUT") {
        std::cin >> param1;
        about(country, param1);
    }
    else if (comand == "DUMP") {
        dump(country);
    }
}
int main() {
    std::map<std::string, std::vector<std::string>> country;
    int n = 0;;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        action(country);
    }

    return 0;
}