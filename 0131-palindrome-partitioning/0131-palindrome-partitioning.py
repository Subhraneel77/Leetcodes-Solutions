class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = [] # which will be our answer
        self.helper(res, [], s) # calling to recursion function 
        return res
    
    # Entire recursive function, that generates all the partition substring
    def helper(self, res, curr, s):
        if s == "":
            res.append(curr)
        
        for i in range(len(s)):
            if self.isPalindrome(s[:i + 1]): # what we are checking over here is, if we partition the string from index to i Example-(0, 0) is palindrome or not
                self.helper(res, curr + [s[:i + 1]], s[i + 1:]) # take the substring and store it in our list & call the next substring from index + 1
    
    # A simple palindromic function start from 0 go till end. And basically keep on checking till they don't cross. 
    def isPalindrome(self, s):
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - 1 - i]:
                return False
        return True