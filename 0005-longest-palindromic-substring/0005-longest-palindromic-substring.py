class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == s[::-1]: return s
        
        a = 1
        start = 0
        for i in range(1, len(s)):
            # aaa, from index 1 to index 2, a -> aa or when aa -> aaa, increase max window by 1
            if i - a >= 0 and s[i - a:i+1] == s[i - a:i+1][::-1]:
                start = i - a
                a += 1
            
            # aba when coming to index 2, we find bab, from a -> bab, increase max window by 2
            elif i - a >= 1 and s[i - a - 1:i+1] == s[i - a - 1:i+1][::-1]:
                start = i - a - 1
                a += 2
            
        return s[start: start + a]