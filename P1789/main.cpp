#include <iostream>
#include <cstring>

 void torch(int* p, int x, int y);
 void fluorite(int* p, int x, int y);

int main() {
    unsigned int n, m, k;
    unsigned int x, y, o, p;
    std::cin >> n >> m >> k;
    int world[n][n];
    memset(world, 0, sizeof(world));

    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        world[x-1-2][y-1]++;
        world[x-1-1][y-1-1]++;
        world[x-1-1][y-1-0]++;
        world[x-1-1][y-1+1]++;
        world
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void torch(int* p, int x, int y) {

}