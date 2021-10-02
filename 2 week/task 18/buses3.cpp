#include <iostream>
#include <set>
#include <map>



void action(std::map<int, std::set<std::string>>& bus) {
    bool flag = true;
    int n = 0;
    std::string str;
    std::set<std::string> temp;
    std::cin >> n;
    while (n) {
        std::cin >> str;
        temp.insert(str);
        --n;
    }
    for (auto s : bus) {
        if (s.second == temp) {
            flag = false;
            n = s.first;
            break;
        }
    }
    if (flag) {
        std::cout << "New bus " << bus.size() + 1 << std::endl;
        bus[bus.size() + 1].swap(temp);
    }
    else
        std::cout << "Already exists for " << n << std::endl;
}

int main() {
    int n = 0;
    std::map<int, std::set<std::string>> bus;
    std::cin >> n;
    while (n) {
        action(bus);
        --n;
    }
    return 0;
}