#include <iostream>

void UpdateIfGreater(int firNum, int& secNum){
    if(firNum > secNum)
        secNum = firNum;
}

int main (){
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    std::cout << b;
    return 0;
}