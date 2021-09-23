#include <iostream>

int main(){
    std::string str;
    int poz = -2;
    int i = 0;
    std::cin >> str;
    size_t len = str.length();
    while((i < len) && (poz != 0)){
        if (str[i] == 'f')
            poz++;
        ++i;
    }
    if(poz <= -1)
        std::cout << poz;
    else 
        std::cout << i - 1;
    return 0;
}