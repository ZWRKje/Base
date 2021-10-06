#include <iostream>
#include <vector>
#include <algorithm>

class SortedStrings {
public:
    void AddString(const std::string& s) {
        this->str.push_back(s);
    }

    std::vector<std::string> GetSortedStrings() {
        std::sort(str.begin(),str.end());
        return str;
    }
private:
    std::vector<std::string> str;
};

void PrintSortedStrings(SortedStrings& strings) {
   for (const std::string& s : strings.GetSortedStrings()) {
     std::cout << s << " ";
   }
   std::cout << std::endl;
}

 int main() {
   SortedStrings strings;

   strings.AddString("first");
   strings.AddString("third");
   strings.AddString("second");
   PrintSortedStrings(strings);

   strings.AddString("second");
   PrintSortedStrings(strings);

   return 0;
 }