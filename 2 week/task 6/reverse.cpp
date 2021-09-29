#include <vector>
#include <iostream>
#include <algorithm>

void Reverse(std::vector<int>&  v){
    size_t n = v.size();
    for(int i = 0; i < n / 2; ++i){
        std::swap(v[i], v[n - i -1]);
    }
}

int main(){
    std::vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for(auto a : numbers){
        std::cout << a;
    }
    return 0;
}