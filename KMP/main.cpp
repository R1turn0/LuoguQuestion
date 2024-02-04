//#include <iostream>
//
//std::string build_next(std::string patt);
//int kmp_search(std::string str, std::string patt);
//
//int main() {
//    std::string str = "ABAABABABCA";
//    std::string patt = "ABABC";
//    std::cout << kmp_search(str, patt) << std::endl;
//    return 0;
//}
//
//// 计算Next数组;
//std::string build_next(std::string patt) {
//    std::string next = "0";
//    int prefix_len = 0;
//    int i = 1;
//    while (i < patt.size()) {
//        if (patt[prefix_len] == patt[i]) {
//            prefix_len += 1;
//            next.append(std::to_string(prefix_len));
//            i += 1;
//        } else {
//            if (prefix_len == 0) {
//                next.append("0");
//                i += 1;
//            } else {
//                prefix_len = next[prefix_len - 1] - '0';
//            }
//        }
//    }
//    return next;
//}
//
//int kmp_search(std::string str, std::string patt) {
//    int i = 0, j = 0;
//    std::string next = build_next(patt);
//    while (i < str.size()) {
//        if (str[i] == patt[j]) {
//            i += 1, j += 1;
//        } else if (j > 0) {
//            j = next[j - 1] - '0';
//        } else {
//            i += 1;
//        }
//        if ( j == patt.size()) {
//            return i - j;
//        }
//    }
//    return 0;
//}

// https://blog.csdn.net/nanhuaibeian/article/details/115748836
#include <iostream>

int *get_next(std::string patt);

int kmp_search(std::string str, std::string patt);

int main() {
    std::cout << kmp_search("ABAABABABCA", "ABABC") << std::endl;
    return 0;
}

int *get_next(std::string patt) {
    int *next = new int[patt.length()];
    int i = 0, j = -1;
    next[0] = -1; // while the first char not match, i++, i++
    while (i < patt.length() - 1) {
        if (j == -1 || patt[i] == patt[j]) {
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;
}

int kmp_search(std::string str, std::string patt) {
    int i = 0, j = 0;
    int *next = get_next(patt);
    while ((i < str.length()) && (j < patt.length())) {
        if (str[i] == patt[j]) {
            i++, j++;
        } else {
            j = next[j];
        }
    }
    if (j == patt.length()) {
        return i - j;
    }
    return -1;
}
