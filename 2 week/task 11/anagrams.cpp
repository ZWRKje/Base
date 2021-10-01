#include <iostream>
#include <map>
bool isEqual(std::map<char, int> firstW, std::map<char, int> secondW)
{
        if (firstW == secondW)
            return true;
        else
            return false; 
}

void isAnagram(std::string first, std::string second)
{
    std::map<char, int> firstW;
    std::map<char, int> secondW;
   
        for (auto i : first)
            ++firstW[i];

        for (auto i : second)
            ++secondW[i];

        if (isEqual(firstW, secondW)) {
            firstW.clear();
            secondW.clear();
            std::cout << "YES" << std::endl;
        } else {
            firstW.clear();
            secondW.clear();
            std::cout << "NO" << std::endl;
        }
           

}
int main()
{
    int n = 0;
    std::string str;
    std::string str2;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> str;
        std::cin >> str2;
        isAnagram(str, str2);  
    }

    return 0;
}