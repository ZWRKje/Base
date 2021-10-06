#include <iostream>
#include <algorithm>
#include <vector>


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

    std::sort(begin(vec1), end(vec1), 
         [](const int& x, const int& y){
            return abs(x) < abs(y);
          } 
    );

    printVec(vec1);
    return 0;
}