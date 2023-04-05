#include <iostream>
#include <cstring>

void beford(std::string fir, std::string aft) {
    if (!fir.empty()) {
        std::cout << aft[fir.size() - 1];
        int tree = fir.find(aft[fir.size() - 1]);
        beford(fir.substr(0, tree), aft.substr(0, tree));
        beford(fir.substr(tree + 1), aft.substr(tree, fir.size() - tree - 1));
    }
}

int main()
{
    char fir[8], aft[8];
    std::cin >> fir >> aft;
    beford(fir, aft);
    std::cout << std::endl;
    return 0;
}