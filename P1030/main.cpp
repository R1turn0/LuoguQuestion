#include <iostream>

void beford(std::string fir, std::string aft) {
    if (!fir.empty()) {
        char stub = aft[fir.size() - 1];
        std::cout << stub;
        int tree = fir.find(stub);
        beford(fir.substr(0, tree), aft.substr(0, tree));
        beford(fir.substr(tree + 1),
               aft.substr(tree, fir.size() - tree - 1));
    }
}

int main()
{
    std::string fir, aft;
    std::cin >> fir >> aft;
    beford(fir, aft);
    std::cout << std::endl;
    return 0;
}

// FDHGIBEAC
// FHIGDEBCA