class Solution:
    def removePalindromeSub(self, s: str) -> int:
        def zip_iter():
            i,j,n=0,len(s)-1,len(s)//2
            while i<=n:
                yield (s[i], s[j])
                i+=1
                j-=1
                
        return 1 if all(x==y for x,y in zip_iter()) else 2