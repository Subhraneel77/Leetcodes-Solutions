class Solution:
    def guessNumber(self, n: int) -> int:
        s = 1
        e = n+1
        while s+1<e:
            mid = (s+e)//2
            if guess(mid)>=0:
                s = mid
            else:
                e = mid
        return s