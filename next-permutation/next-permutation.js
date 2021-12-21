var nextPermutation = function(nums) {
    // Length of the array
    const n = nums.length;
    // Index of the first element that is smaller than
    // the element to its right.
    let index = -1;
    // Loop from right to left
    for (let i = n - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            index = i - 1;
            break;
        }
    }
    // Base condition
    if (index === -1) {
        reverse(nums, 0, n - 1);
        return nums;
    }
    let j = n - 1;
    // Again swap from right to left to find first element
    // that is greater than the above find element
    for (let i = n - 1; i >= index + 1; i--) {
        if (nums[i] > nums[index]) {
            j = i;
            break;
        }
    }
    // Swap the elements
    swap(nums, index, j);
    // Reverse the elements from index + 1 to the nums.length
    reverse(nums, index + 1, n - 1);
    return nums;
};

const reverse = (nums, i, j) => {
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
};

const swap = (nums, i, index) => {
    const temp = nums[index];
    nums[index] = nums[i];
    nums[i] = temp;
};
