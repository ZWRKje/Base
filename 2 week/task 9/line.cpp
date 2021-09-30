#include <iostream>
#include <vector>
void worry(std::vector<bool>& queue, const int& param) {
    queue[param] = true;
};

void quiet(std::vector<bool>& queue, const int& param) {
    queue[param] = false;
};

void posCome(std::vector<bool>& queue, const int& param) {
    for (int i = 0; i < param; ++i)
        queue.push_back(false);
};

void negCome(std::vector<bool>& queue, const int& param) {
    queue.erase(queue.end() + param, queue.end());
};

void wCout(std::vector<bool>& queue) {
    size_t n = queue.size();
    size_t count = 0;
    for (int i = 0; i < n; ++i) {
        if (queue[i] == true)
            count++;
    }
    std::cout << count << std::endl;
};

void action(const std::string& str, int& param) {
    static std::vector<bool> queue;
    if (str == "WORRY") 
        worry(queue, param);
    else if (str == "QUIET")
        quiet(queue, param);
    else if (str == "COME" && param > 0)
        posCome(queue, param);
    else if (str == "COME" && param < 0)
        negCome(queue, param);
    else if (str == "WORRY_COUNT") 
        wCout(queue);      
};

int main() {
    std::string str;
    size_t nCom = 0;
    int param = 0;
    std::cin >> nCom;
    for (int i = 0; i < nCom; ++i) {
        std::cin >> str;
        if (str != "WORRY_COUNT") 
            std::cin >> param;
        action(str, param);
    }
    return 0;
}
