#include <vector>
#include <iostream>
std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector<int> newRev = {};
    size_t n = v.size() - 1;
    for (int i = n; i >= 0; i--)
        newRev.push_back(v[i]);

    return newRev;
}


int main() {
    std::vector<int> v = { 1, 5, 3, 4, 2 };
    v = Reversed(v);
    for (auto a : v)
        std::cout << a;

    return 0;
}