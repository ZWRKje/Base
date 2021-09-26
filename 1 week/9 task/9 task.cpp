#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n = 0;
    std::cin >> n; 
    std::vector<int> num;
    do {
        num.push_back(n % 2);
        n /= 2;
    }
    while(n != 0);
    std::reverse(num.begin(), num.end());

    for (int i = 0 ; i < num.size(); ++i ){
        std::cout<<num[i];
    }

    return 0;
}