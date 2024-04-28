#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // Using XOR to cancel out pairs of numbers
    }
    return result;
}

int main() {
    std::vector<int> nums = {4, 1, 2, 1, 2};
    int result = singleNumber(nums);
    std::cout << "The single number is: " << result << std::endl;
    return 0;
}




