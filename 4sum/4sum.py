from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []

        def k_sum(nums, k, target, arr, start_idx):
            if k == 2:
                two_sum(nums, arr, k, start_idx, target)
                return
            for i in range(start_idx, len(nums) - k + 1):
                if i > start_idx and nums[i] == nums[i - 1]:
                    continue
                k_sum(nums, k - 1, target - nums[i], arr + [nums[i]], i + 1)

        def two_sum(nums, arr, k, start_idx, target):
            left = start_idx
            right = len(nums) - 1

            while left < right:
                total = nums[left] + nums[right]
                if total == target:
                    res.append(arr + [nums[left], nums[right]])
                    left += 1
                    right -= 1

                    while left < right and nums[left] == nums[left - 1]:
                        left += 1  # skip same element to avoid duplicate quadruplets
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1  # skip same element to avoid duplicate quadruplets
                elif total < target:
                    left += 1
                else:
                    right -= 1

        k_sum(nums, 4, target, [], 0)
        return res
        