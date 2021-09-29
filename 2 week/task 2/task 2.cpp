#include <iostream>
#include <string>

bool IsPalindrom(std::string str) {
    size_t n = str.size();
    bool flag = true;

    for (int i = 0; i < n; ++i) 
        str[i] = tolower(str[i]);

    for (int i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - i - 1]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    std::string str = " ";
    bool flagOut = false;
    std::cin >> str;
    flagOut = IsPalindrom(str);
    if (flagOut) 
        std::cout << "true";
    else
        std::cout << "false";

    return 0;
}