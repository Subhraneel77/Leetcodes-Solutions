class Solution(object):
    def maxDistToClosest(self, seats):
        pre_zeros, suf_zeros, max_zeros, zeros = -1, -1, -1, 0
        for seat in seats:
            if seat == 0: zeros += 1
            else:
                if pre_zeros == -1: 
                    pre_zeros = zeros
                else:
                    max_zeros = max(max_zeros, zeros)
                zeros = 0
        suf_zeros = zeros
        return max(pre_zeros, suf_zeros, (max_zeros + 1) // 2)