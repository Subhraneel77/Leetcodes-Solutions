var searchRange = function (nums, target) {
    return [findFirstOccurrence(nums, target), findLastOccurrence(nums, target)];
};

const findFirstOccurrence = (nums, target) => {
    // Left and right pointers
    let left = 0;
    let right = nums.length - 1;
    // Index of first occurrence
    let firstOccurrence = -1;
    // Loop until the two pointers meet
    while (left <= right) {
        // Middle index
        let middle = left + parseInt((right - left) / 2);
        // Check if we have found the value
        if (nums[middle] === target) {
            firstOccurrence = middle;
            right = middle - 1;
        }
        // If the target is less than the element
        // at the middle index
        else if (target < nums[middle]) {
            right = middle - 1;
        }
        // If the target is greater than the element
        // at the middle index
        else {
            left = middle + 1;
        }
    }
    return firstOccurrence;
};

const findLastOccurrence = (nums, target) => {
    // Left and right pointers
    let left = 0;
    let right = nums.length - 1;
    // Index of first occurrence
    let lastOccurrence = -1;
    // Loop until the two pointers meet
    while (left <= right) {
        // Middle index
        let middle = left + parseInt((right - left) / 2);
        // Check if we have found the value
        if (nums[middle] === target) {
            lastOccurrence = middle;
            left = middle + 1;
        }
        // If the target is less than the element
        // at the middle index
        else if (target < nums[middle]) {
            right = middle - 1;
        }
        // If the target is greater than the element
        // at the middle index
        else {
            left = middle + 1;
        }
    }
    return lastOccurrence;
};