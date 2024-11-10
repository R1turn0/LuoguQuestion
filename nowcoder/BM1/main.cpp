#include <iostream>
#include <list>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数初始化列表
};

class Solution {
public:
    static ListNode *ReverseList(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *ans = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return ans;
    }
};

int main() {
    auto *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    auto *ans = Solution::ReverseList(head);
    return 0;
}
