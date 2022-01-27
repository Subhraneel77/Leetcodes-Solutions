class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        count = collections.defaultdict(int)
        count[0] = 1
        sum_num = 0
        ans = 0
        for num in nums:
            sum_num += num
            if (sum_num % k) in count:
                ans += count[sum_num % k]
            count[sum_num % k] += 1
        return ans
        