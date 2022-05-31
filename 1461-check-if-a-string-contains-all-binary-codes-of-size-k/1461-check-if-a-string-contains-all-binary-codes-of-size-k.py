class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:     
        n=len(s)
        required_count=2 ** k        
        seen=set()
        for i in range(n-k+1):
            tmp=s[i:i+k]
            if tmp not in seen:
                seen.add(tmp)
                required_count-=1
                if required_count==0: # kill the loop once the condition is met
                    return True
        return False            