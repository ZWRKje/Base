#include <iostream>
#include <vector>

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

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) {
    std::vector<std::string> temp;
    size_t n = words.size();
    for (int i = 0; i < n; ++i) {
        size_t a = words[i].size();
        if (words[i].size() >= minLength) {
            bool flag = true;
            flag = IsPalindrom(words[i]);
            if (flag)
                temp.push_back(words[i]);
        }

    }
    return temp;
}

int main() {
    std::vector<std::string>a = { "", "aba"};
    a = PalindromFilter(a, 5);
    for (auto s : a)
        std::cout << s;

    return 0;
}