#include <iostream>
#include <map>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> &m) {

    std::set<std::string> rezult;
    for (auto s : m)
        rezult.insert(s.second);

    for (std::string a : rezult)
        std::cout << a << " ";

    return rezult;
}

int main()
{
    std::set<std::string> values = BuildMapValuesSet({{1, "odd"},
                                                      {2, "even"},
                                                      {3, "odd"},
                                                      {4, "even"},
                                                      {5, "odd"}});

    return 0;
}