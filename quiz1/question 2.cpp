#include <iostream>
#include <vector>
#include <algorithm>

void reverseArray(std::vector<int>& nums, int start, int end) {
    while (start < end) {
        std::swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    // Reverse the entire array
    reverseArray(nums, 0, n - 1);

    reverseArray(nums, 0, k - 1);

    reverseArray(nums, k, n - 1);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    std::cout << "Original Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    rotate(nums, k);

    std::cout << "Array Rotated by " << k << " steps to the right: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
