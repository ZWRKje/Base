#include <vector>
#include <string>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination){
    size_t n = source.size();
    for (int i = 0; i < n; ++i){
        destination.push_back(source[i]);
    }
    source.clear();
}

int main(){
    std::vector<std::string> source = {"a", "b", "c"};
    std::vector<std::string> destination = {"z"};
    MoveStrings(source, destination);

    return 0;
}