#include <iostream>
#include <algorithm>
#include <vector>

bool compare(const int& x, const int& y){
    if(std::abs(x) < std::abs(y)){
        return true;
    }
    return false;
}

void printVec(const std::vector<int>& vec){
    for(const auto& i : vec){
        std::cout << i << " ";  
    }
}

int main (){
    size_t n = 0;
    std::cin >> n;
    int i = 0;
    std::vector<int> vec1(n);

    while (n > 0) {
        std::cin >> vec1[i];
        ++i;
        --n;
    }

    std::sort(begin(vec1), end(vec1), compare);

    printVec(vec1);
    return 0;
}