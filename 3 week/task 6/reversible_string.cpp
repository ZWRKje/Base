#include <iostream>
#include <string>
#include <algorithm>

class ReversibleString {
public:
    ReversibleString() { };
    ReversibleString(const std::string& data) {
        this->str = data;
    };
    void Reverse() {
        std::reverse(str.begin(), str.end());
    };
    std::string ToString() const  {
        return this->str;
    };
private:
    std::string str;
};

// int main() {
//     ReversibleString s("live");
//     s.Reverse();
//     std::cout << s.ToString() << std::endl;

//     s.Reverse();
//     const ReversibleString& s_ref = s;
//     std::string tmp = s_ref.ToString();
//     std::cout << tmp << std::endl;

//     ReversibleString empty;
//     std::cout << '"' << empty.ToString() << '"' << std::endl;

//     return 0;
// }