class Solution {
public:
    int maximumSwap(int num) {
        int maxIndex = -1, swap1 = -1, swap2 = -1;
        std::string nums = std::to_string(num);
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            if (maxIndex == -1 || nums[i] > nums[maxIndex]) {
                maxIndex = i;
            } 
            else if (nums[i] < nums[maxIndex]) {
                swap1 = i;
                swap2 = maxIndex;
            }
        }

        if (swap1 != -1 && swap2 != -1) {
            std::swap(nums[swap1], nums[swap2]);
        }

        return std::stoi(nums);
    }
};