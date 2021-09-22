#include <iostream>

int main(){
    std::string a, b, c;
    std::cin >> a >> b >> c;
    
    if(a <= b &&  a <= c){
            std::cout << a;      
    }else if (b <= a && b <= c) {
            std::cout << b;
    }else 
            std::cout << c;
    system("PAUSE");
    return 0;
}