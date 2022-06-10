class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        seen = set()
        for start_idx in range(len(s)):
            seen.clear()
            end_idx = start_idx
            while end_idx < len(s):
                if s[end_idx] in seen:
                    break
                seen.add(s[end_idx])
                end_idx += 1
            res = max(res, end_idx - start_idx)
        return res