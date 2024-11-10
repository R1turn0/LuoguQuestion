#include <iostream>
#include <vector>

class Solution {
public:
    static int findPeakElement(std::vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    std::vector<int> nums = {1,20,3,4,5,6,7,8,9};
    std::cout << Solution::findPeakElement(nums) << std::endl;
    return 0;
}
