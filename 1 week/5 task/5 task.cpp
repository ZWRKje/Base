#include <iostream>

int main()
{
    double n, a, b, x, y;
    n = 0;
    a = b = x = y = n;
    std::cin >> n >> a >> b >> x >> y;
    if (n > b){
        std::cout << n - ((n * y) / 100);
    }
    else if (n > a){
        std::cout << n - ((n * x) / 100);
    }
    else
        std::cout << n;
    return 0;
}