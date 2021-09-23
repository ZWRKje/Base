#include <iostream>

int main() {
    int a = 0, b = 0, r = 0, q = 0;
    std::cin >> a >> b;
    q = a / b;
    r = a % b;
    while (r != 0) {
        a = r;
        q = b / r;
        r = b % r;
        b = a;

    }

    std::cout << b;

    return 0;
}