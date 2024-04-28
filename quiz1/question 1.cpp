#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0; // If the array is empty, there are no duplicates

    int index = 0; // Index to keep track of the next position to store a unique element

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[index]) {
            nums[++index] = nums[i];
        }
    }


    return index + 1;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 5, 5, 6};

    std::cout << "Original Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int length = removeDuplicates(nums);

    std::cout << "Array with Duplicates Removed: ";
    for (int i = 0; i < length; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "New Length: " << length << std::endl;

    return 0;
}
