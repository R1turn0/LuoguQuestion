#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid; // 返回找到的索引
            else if (nums[mid] < target) left = mid + 1; // 目标值在右侧
            else right = mid - 1; // 目标值在左侧
        }
        return -1; // 未找到返回 -1
    }
};

int main() {
    vector<int> nums = {-1, 0, 3, 4, 6, 10, 13, 14};
    Solution sln;
    std::cout << sln.search(nums, -1) << std::endl;
    return 0;
}
