#include <iostream>
#include <cmath>

int main()
{
    int a = 0, b = 0, c = 0;
    double d = 0.0, x1 = 0.0, x2 = 0.0;
    std::cin >> a >> b >> c;
    d = pow(b, 2) - (4 * a * c);
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    if (a == 0 ){
        if(b != 0){
            std::cout << (c) / -b;
        }
        else 
            std::cout<<" ";
        
    }else if (d > 0){
        std::cout << x1 << " " << x2;
    }else if(d == 0 ){
        std::cout << -b /(2 * a);
    }else 
        std::cout << " ";

    system("PAUSE");
    return 0;
}
