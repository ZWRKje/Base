#include <iostream>
#include <set>
#include <vector>


int main(){
    int n = 0;
    std::cin >> n;
    std::vector<std::string> str(n);

    for (std::string &s : str) 
        std::cin >> s;
        
    std::set<std::string> unic(str.begin(),str.end());

    std::cout << unic.size();
    
    return 0;
}