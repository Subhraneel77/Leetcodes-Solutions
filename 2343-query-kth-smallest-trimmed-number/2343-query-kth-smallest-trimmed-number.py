class Solution: 
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]: 
        def q(x,y): 
            a = [] 
            for i, v in enumerate(nums) : 
                s = v[-y:] 
                p = (int(s), i) 
                bisect.insort(a, p) 
             
            return a[x-1][1] 
         
        res = [] 
        for x,y in queries :  
            res.append(q(x,y)) 
             
        return res