#include <iostream>
#include <algorithm>
#include <vector>

bool compare( std::string x,  std::string y) {
    for (auto& i : x)
        i = tolower(i);

    for (auto& i : y)
        i = tolower(i);

    return x < y;
}

void printVec(const std::vector<std::string>& vec) {
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
}

int main() {
    size_t n = 0;
    std::cin >> n;
    std::vector<std::string> vec1(n);
    for (auto& i : vec1) {
        std::cin >> i;
    }

    std::sort(begin(vec1), end(vec1), compare);

    printVec(vec1);
    return 0;
}