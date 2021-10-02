#include <iostream>
#include<set>
#include <map>

void add(std::map<int, std::set<std::string>>& base, std::string param1, std::string param2) {
    bool flag = true;
    static int n= 0;
        for (int i = 0; i < base.size(); ++i) {
            if (base[i].count(param1) == 1 && base[i].count(param2) == 1) {
                flag = false;
            }
        }
    
    if (flag) {     
        base[n].insert(param1);
        base[n].insert(param2);
        ++n;
    }


}

void count(std::map<int, std::set<std::string>>& base, std::string param1) {
    int con = 0;
    for (auto s : base) {
        if (s.second.count(param1) == 1) {
            ++con;
        }
    }

    if (con > 0)
        std::cout << con << std::endl;
    else
        std::cout << 0 << std::endl;
}

void check(std::map<int, std::set<std::string>>& base, std::string param1, std::string param2) {
    bool flag = false;
    for (auto s : base) {
        if (s.second.count(param1) == 1 && s.second.count(param2) == 1)
            flag = true;
    }
    if (flag)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;


}

void action(std::map<int, std::set<std::string>>& base) {
    std::string comand;
    std::cin >> comand;
    if (comand == "ADD") {
        std::string param1;
        std::string param2;
        std::cin >> param1 >> param2;
        add(base, param1, param2);

    }
    else if (comand == "COUNT") {
        std::string param1;
        std::cin >> param1;
        count(base, param1);
    }
    else if (comand == "CHECK") {
        std::string param1;
        std::string param2;
        std::cin >> param1 >> param2;
        check(base, param1, param2);
    }

}

int main() {
    int n = 0;
    std::map<int, std::set<std::string>> base;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        action(base);
    }

    return 0;
}

