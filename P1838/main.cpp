//#include <iostream>
//
//static char checkerboard[9] = {0};
//
//int main() {
//    std::string str;
//    std::cin >> str;
//    bool player = true;
//    for (char i: str) {
//        if (player)
//            checkerboard[i - '0' - 1] = '1';
//        else
//            checkerboard[i - '0' - 1] = '2';
//        player = !player;
//    }
//    for (int i = 0; i < 9; i++) {
//        if (i % 3 == 0) std::cout << std::endl;
//        std::cout << checkerboard[i] << ' ';
//    }
//    return 0;
//}

#include <iostream>

//一整行连（编号1,2,3）
static int hang[10] = {0,
                1, 1, 1,
                2, 2, 2,
                3, 3, 3
};
//一整列连（编号4,5,6）
static int lie[10] = {0,
               4, 5, 6,
               4, 5, 6,
               4, 5, 6
};
//左上↘右下对角线连（编号7）
static int djx1[10] = {0,
                7, 0, 0,
                0, 7, 0,
                0, 0, 7
};
//右上↙左下对角线连（编号8）
static int djx2[10] = {0,
                0, 0, 8,
                0, 8, 0,
                8, 0, 0
};
static int x[2][9];//两个人的棋每一种连法的连子数

int main() {
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.size(); i++) {
        x[i % 2][hang[s[i] - '0']]++;
        x[i % 2][lie[s[i] - '0']]++;
        x[i % 2][djx1[s[i] - '0']]++;
        x[i % 2][djx2[s[i] - '0']]++;
        //各种连法都++
        for (auto & z : x) {
            for (int j: z) std::cout << j << " ";
            std::cout << "// ";
        }
        std::cout << std::endl;
    }
    for (int i = 1; i < 9; i++) {
        if (x[0][i] == 3) {
            std::cout << "xiaoa wins.\n" << std::endl;
            return 0;
        } else if (x[1][i] == 3) {
            std::cout << "uim wins." << std::endl;
            return 0;
        }
    }
    std::cout << "drew.\n" << std::endl;
    return 0;
}
