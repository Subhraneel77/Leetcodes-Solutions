#include <vector>
#include <functional> // For std::function

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // A lambda function for recursive quick sort
        std::function<void(int, int)> quickSort = [&](int left, int right) {
            // Base case: If the current segment is empty or a single element, no need to sort
            if (left >= right) {
                return;
            }

            // Initialize pointers for partitioning process
            int pivotIndex = left + (right - left) / 2; // Choose middle element as pivot
            int pivotValue = nums[pivotIndex];
            int i = left - 1;
            int j = right + 1;
          
            // Partition the array into two halves
            while (i < j) {
                // Increment i until nums[i] is greater or equal to pivot
                do {
                    i++;
                } while (nums[i] < pivotValue);

                // Decrement j until nums[j] is less or equal to pivot
                do {
                    j--;
                } while (nums[j] > pivotValue);

                // If i and j haven't crossed each other, swap the elements
                if (i < j) {
                    std::swap(nums[i], nums[j]);
                }
            }

            // Recursively apply the same logic to the left and right halves of the array
            quickSort(left, j);     // Apply quicksort to the left subarray
            quickSort(j + 1, right); // Apply quicksort to the right subarray
        };

        // Start the quick sort from the first to the last element
        quickSort(0, nums.size() - 1);

        // Return the sorted array
        return nums;
    }
};
