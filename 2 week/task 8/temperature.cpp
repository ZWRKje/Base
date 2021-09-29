#include <iostream>
#include <vector>

std::vector<int> checkTemp(std::vector<int>& temp) {
    size_t n = temp.size();
    std::vector<int> rez;
    int medTemp = 0;
    for (int i = 0; i < n ; ++i)
        medTemp += temp[i];
    medTemp /= n;

    for (int i = 0; i < n; ++i) {
        if (temp[i] > medTemp) {
            rez.push_back(i);
        }
    }
    return rez;
}

int main() {
    int n;
    std::cin >> n;
    if (n != 0) {
        std::vector<int> temp(n);
        for (int& a : temp)
            std::cin >> a;

        temp = checkTemp(temp);
        std::cout << temp.size() << std::endl;
        for (int& a : temp)
            std::cout << a << " ";
    }
   
    return 0;
}