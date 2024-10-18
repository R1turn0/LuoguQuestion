#include <iostream>
#include <cstring>
#include <vector>

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;    // 三个正整数 n,m,pn,m,p，表示出题人数，选手数，与正确预测数
    unsigned int k, player[m], num; // k表示出题人预测可能最终排名第一的选手位数
                                    // player数组表示选手获得出题人预测获胜的次数，play[0]表示一号选手，player[1]表示二号选手
                                    // num为选手号
    std::vector<unsigned int> winner;   // 正确预测的选手号

    memset(player, 0, sizeof(player));

    for (int i = 0; i < n; i++) {
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> num;
            num--;
            player[num]++;  // 一号选手获得预测，player[0]++，以此类推
        }
    }

    num = 0;
    for (unsigned int i : player) {
//        std::cout << i << " ";
        num++;
        if (i == p) {
            winner.push_back(num);
        }
    }

    std::cout << winner.size() << std::endl;
    for (unsigned int i : winner) {
        std::cout << i << " ";
    }

    return 0;
}

