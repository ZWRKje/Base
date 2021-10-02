#include <iostream>
#include <map>
#include <vector>

void action(std::map <int, std::vector<std::string>>& bus) {
    
    std::vector<std::string> stops;
    int n = 0;
    bool flag = true;
    std::string str;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> str;
        stops.push_back(str);
    }
    for (auto s : bus) {
        int i = 0;
        if (s.second == stops) {
            flag = false;
            std::cout << "Already exists for " << s.first << std::endl;
            break;
        }
    }
    if (flag) {
        bus[bus.size() + 1].swap(stops);
        std::cout << "New bus " << bus.size() << std::endl;
    }

}
int main() {
    int nCom = 0;
    std::cin >> nCom;
    std::map<int, std::vector<std::string>> bus;
    for (int i = 0; i < nCom; ++i) {
        action(bus);
    }

    return 0;
}