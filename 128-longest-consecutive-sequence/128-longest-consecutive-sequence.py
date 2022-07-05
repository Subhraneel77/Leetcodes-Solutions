class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        
        longest_sequence = 0
        for num in nums:
            if num - 1 in num_set:
                continue
            current_length = 1
            while num + 1 in num_set:
                num += 1
                current_length += 1
            longest_sequence = max(longest_sequence, current_length)
        return longest_sequence